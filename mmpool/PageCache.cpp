#define _CRT_SECURE_NO_WARNINGS 1
#include "PageCache.h"
PageCache PageCache::_instance;
Span* PageCache::NewSpan(size_t kpage) {
	// 在PageCache获取kpage的Span
	// 1. PageCache的kpage下标的桶里面有现成的Span，直接返回
	if (!_span_lists[kpage].Empty()) {
		return _span_lists[kpage].PopFront();
	}
	// 2. PageCache里kpage下标的桶里面没有现成的Span，往下面找
	for (size_t i = kpage + 1; i < MAX_PAGE; i++) {
		if (!_span_lists[i].Empty()) {
			// 找到了非空的桶，进行切分：将i页切分成 kpage + i-kpage
			Span* nspan = _span_lists[i].PopFront(); // 找到的现成的Span
			Span* kspan = new Span; // 切出来返回的Span
			kspan->_page_id = nspan->_page_id;
			kspan->_page_amount = kpage;
			nspan->_page_id += kpage;
			nspan->_page_amount -= kpage;
			_span_lists[nspan->_page_amount].PushFront(nspan);
			return kspan;
		}
	}
	// 3. 找不到现成的Span，向系统申请MAX_PAGE大小的Span
	void* ptr = SystemAlloc(MAX_PAGE - 1);
	PAGE_ID page_id = ((PAGE_ID)ptr >> PAGE_SHIFT);
	Span* kspan = new Span;
	kspan->_page_id = page_id;
	kspan->_page_amount = MAX_PAGE - 1;
	_span_lists[MAX_PAGE - 1].PushFront(kspan);

	return NewSpan(kpage);
}