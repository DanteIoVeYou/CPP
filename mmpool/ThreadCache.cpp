#define _CRT_SECURE_NO_WARNINGS 1
#include "ThreadCache.h"

void* ThreadCache::Allocate(size_t size) { // 给线程分配内存的接口
    size_t align_num = SizeClass::Align(size);
    size_t index = SizeClass::Index(size);
    if (_free_list[index].Empty()) {
        return FetchFromCentralCache(index); // 桶里没有内存，向上申请内存，再分配
    }
    else {
        return _free_list[index].Pop();
    }
}

void ThreadCache::Deallocate(void* ptr, size_t size) {
    assert(ptr);
    assert(size <= MAX_SIZE);
    // 插到正确的桶里
    size_t index = SizeClass::Index(size);
    _free_list[index].Push(ptr);
} // 让线程还内存的接口
void* ThreadCache::FetchFromCentralCache(size_t index) {
    return nullptr;
} // ThreadCache的某个桶没有内存了，就向上级CentralCache申请内存