#pragma once

#include "common.h"

class PageCache {
public:
	static PageCache* GetInstace() {
		return &_instance;
	}
	Span* NewSpan(size_t kpage);
private:
	PageCache() {}
	PageCache(const PageCache&) = delete;
	PageCache operator=(const PageCache&) = delete;
	static PageCache _instance;
	SpanList _span_lists[MAX_PAGE];
};