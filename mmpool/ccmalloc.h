#pragma once
#include "ThreadCache.h"
#include "PageCache.h"

// ConCurrentAlloc == ccmalloc
// ConCurrentFree == ccfree

static void* ccmalloc(size_t size) {
    // 1.申请大于256kB的内存
    if (size > MAX_SIZE) {
        // 计算页数
        PAGE_ID kpage = (SizeClass::Align(size)) >> PAGE_SHIFT;
        
        // 申请大于256kB 但是小于等于(MAX_PAGE-1)页的内存
        if (size <= 128 * 8 * 1024) {
            Span* span = PageCache::GetInstance()->NewSpan(kpage);
            return span->_free_list;
        }
        // 申请大于(MAX_PAGE-1)页的内存
        else {
            void* ptr = SystemAlloc(kpage);
            return ptr;
        }
    }
    else {
        if (pThreadCache == nullptr) {
            pThreadCache = new ThreadCache();
        }
    }
};

static void ccfree(void* ptr) {
    pThreadCache->Deallocate(ptr, (PageCache::GetInstance()->_pageid_span_map[((PAGE_ID)ptr >> PAGE_SHIFT)])->_page_block_size);
}