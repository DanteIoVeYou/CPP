#pragma once
#include "ThreadCache.h"


// ConCurrentAlloc == ccmalloc
// ConCurrentFree == ccfree

static void* ccmalloc(size_t size) {
    if (pThreadCache == nullptr) {
        pThreadCache = new ThreadCache();
    }
    return pThreadCache->Allocate(size);
};

static void ccfree(void* ptr, size_t size) {
    pThreadCache->Deallocate(ptr, size);
}