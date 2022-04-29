#define _CRT_SECURE_NO_WARNINGS 1
#include "CentralCache.h"
#include "PageCache.h"
CentralCache CentralCache::_instance; // ���嵥��

Span* CentralCache::GetOneSpan(SpanList& span_list, size_t size) {
	// ȥCentralCache��Ӧ��SpanList�����ҷǿ�Span���ҵ����ظ�Span�ĵ�ַ���Ҳ�����ȥ��PageCache�����µ�Span
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
	// ��PageCache������ҳΪ��λ���ڴ棬���ҽ����и�
	span_list._mtx.unlock(); // ��ʱ��Ͱ���������Ա����ڴ滹�����Ļ��������߳̿���ֱ���û��������ڴ�

	PageCache::GetInstace()->_mtx.lock();
	Span* new_span = PageCache::GetInstace()->NewSpan(SizeClass::PageBatch(size));
	PageCache::GetInstace()->_mtx.unlock();

	span_list._mtx.lock();

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
	return new_span;

}
size_t CentralCache::GiveToThreadCache(void*& start, void*& end, size_t batch_size, size_t size) {
	size_t index = SizeClass::Index(size);
	_span_lists[index]._mtx.lock();
	Span* span = GetOneSpan(_span_lists[index], size);
	// ������һ��Span��Ҳ����ζ��Span����������һ���ڴ��
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
	// start ָ����һ��������Pop�������ڴ��
	// ��ThreadCache����num��size��С���ڴ��
	size_t index = SizeClass::Index(size);
	// ������Ҫ֪��������һ��Span
	while (start) {
		Span* span = PageCache::GetInstace()->GetSpanViaAddress(start);
		span->_used_amount--;
		if (span->_used_amount == 0) {
			// һ��Span�Ѿ�ȫ�����˻�������ô�黹��PageCache
			PageCache::GetInstace()->_mtx.lock();
			span->_free_list = nullptr;
			span->_next = nullptr;
			span->_prev = nullptr;
			PageCache::GetInstace()->GetPageFromCentralCache(span);
			PageCache::GetInstace()->_mtx.unlock();
		}
		start = NextObj(start);
	}
}
