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
	Span* new_span = PageCache::GetInstace()->NewSpan(SizeClass::PageBatch(size));
	char* addr_begin = (char*)(new_span->_page_id << PAGE_SHIFT);
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
void CentralCache::GiveToThreadCache(void*& start, void*& end, size_t batch_size, size_t size) {
	size_t index = SizeClass::Index(size);
	Span* span = GetOneSpan(_span_lists[index], size);
	// ������һ��Span��Ҳ����ζ��Span����������һ���ڴ��
	_span_lists[index]._mtx.lock();

	start = span->_free_list;
	end = start;
	size_t actual_batch_size = 1;
	while (actual_batch_size < batch_size && NextObj(end) != nullptr) {
		actual_batch_size++;
		end = NextObj(end);
	}
	span->_free_list = NextObj(end);
	NextObj(end) = nullptr;

	_span_lists[index]._mtx.unlock();
}