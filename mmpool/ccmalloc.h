#pragma once
#include "ThreadCache.h"
#include "PageCache.h"

// ConCurrentAlloc == ccmalloc
// ConCurrentFree == ccfree

static void* ccmalloc(size_t size) {
    // 1.�������256kB���ڴ�
    if (size > MAX_SIZE) {
        // ����ҳ��
        PAGE_ID kpage = (SizeClass::Align(size)) >> PAGE_SHIFT;
        
        // �������256kB ����С�ڵ���(MAX_PAGE-1)ҳ���ڴ�
        if (size <= 128 * 8 * 1024) {
            Span* span = PageCache::GetInstance()->NewSpan(kpage);
            return span->_free_list;
        }
        // �������(MAX_PAGE-1)ҳ���ڴ�
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