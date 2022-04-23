#define _CRT_SECURE_NO_WARNINGS 1
#include "PageCache.h"
PageCache PageCache::_instance;
Span* PageCache::NewSpan(size_t kpage) {
	// ��PageCache��ȡkpage��Span
	// 1. PageCache��kpage�±��Ͱ�������ֳɵ�Span��ֱ�ӷ���
	if (!_span_lists[kpage].Empty()) {
		return _span_lists[kpage].PopFront();
	}
	// 2. PageCache��kpage�±��Ͱ����û���ֳɵ�Span����������
	for (size_t i = kpage + 1; i < MAX_PAGE; i++) {
		if (!_span_lists[i].Empty()) {
			// �ҵ��˷ǿյ�Ͱ�������з֣���iҳ�зֳ� kpage + i-kpage
			Span* nspan = _span_lists[i].PopFront(); // �ҵ����ֳɵ�Span
			Span* kspan = new Span; // �г������ص�Span
			kspan->_page_id = nspan->_page_id;
			kspan->_page_amount = kpage;
			nspan->_page_id += kpage;
			nspan->_page_amount -= kpage;
			_span_lists[nspan->_page_amount].PushFront(nspan);
			return kspan;
		}
	}
	// 3. �Ҳ����ֳɵ�Span����ϵͳ����MAX_PAGE��С��Span
	void* ptr = SystemAlloc(MAX_PAGE - 1);
	PAGE_ID page_id = ((PAGE_ID)ptr >> PAGE_SHIFT);
	Span* kspan = new Span;
	kspan->_page_id = page_id;
	kspan->_page_amount = MAX_PAGE - 1;
	_span_lists[MAX_PAGE - 1].PushFront(kspan);

	return NewSpan(kpage);
}