#define _CRT_SECURE_NO_WARNINGS 1
#include "CentralCache.h"
#include "PageCache.h"
CentralCache CentralCache::_instance; // 定义单例

Span* CentralCache::GetOneSpan(SpanList& span_list, size_t size) {
	// 去CentralCache对应的SpanList里面找非空Span；找到返回该Span的地址；找不到则去向PageCache申请新的Span
	Span* begin = span_list.Begin();
	Span* end = span_list.End();
	while (begin != end) {
		if (begin->_free_list != nullptr) {
			return begin;
		}
		else {
			begin = begin->_next;
		}
	}
	// 向PageCache申请以页为单位的内存，并且进行切割
	span_list._mtx.unlock(); // 暂时将桶锁解锁，以便有内存还回来的话，其他线程可以直接拿还回来的内存

	PageCache::GetInstace()->_mtx.lock();
	Span* new_span = PageCache::GetInstace()->NewSpan(SizeClass::PageBatch(size));
	PageCache::GetInstace()->_mtx.unlock();
	char* addr_begin = (char*)((new_span->_page_id) << PAGE_SHIFT);
	char* addr_end = (char*)((new_span->_page_id + new_span->_page_amount) << PAGE_SHIFT);
	new_span->_free_list = addr_begin;
	void* tail = new_span->_free_list;
	while (addr_begin != addr_end) {
		NextObj(tail) = addr_begin + size;
		tail = NextObj(tail);
		addr_begin += size;
	}

	span_list.PushFront(new_span);
	span_list._mtx.lock();
	return new_span;

}
size_t CentralCache::GiveToThreadCache(void*& start, void*& end, size_t batch_size, size_t size) {
	size_t index = SizeClass::Index(size);
	_span_lists[index]._mtx.lock();
	Span* span = GetOneSpan(_span_lists[index], size);
	// 至少有一个Span，也就意味着Span里面至少有一个内存块
	start = span->_free_list;
	end = start;
	size_t actual_batch_size = 1;
	while (actual_batch_size < batch_size && NextObj(end) != nullptr) {
		actual_batch_size++;
		end = NextObj(end);
	}
	span->_free_list = NextObj(end);
	span->_used_amount += actual_batch_size;
	NextObj(end) = nullptr;

	_span_lists[index]._mtx.unlock();

	return actual_batch_size;
}

void CentralCache::GetBackFromThreadCache(void* start, size_t size) {
	// start 指向了一批连续的Pop出来的内存块
	// 从ThreadCache回收num个size大小的内存块
	size_t index = SizeClass::Index(size);
	// 我们需要知道还给哪一个Span
	Span* span = 
}
