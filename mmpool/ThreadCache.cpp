#define _CRT_SECURE_NO_WARNINGS 1
#include "ThreadCache.h"

void* ThreadCache::Allocate(size_t size) { // ���̷߳����ڴ�Ľӿ�
    size_t align_num = SizeClass::Align(size);
    size_t index = SizeClass::Index(size);
    if (_free_list[index].Empty()) {
        return FetchFromCentralCache(index); // Ͱ��û���ڴ棬���������ڴ棬�ٷ���
    }
    else {
        return _free_list[index].Pop();
    }
}

void ThreadCache::Deallocate(void* ptr, size_t size) {
    assert(ptr);
    assert(size <= MAX_SIZE);
    // �嵽��ȷ��Ͱ��
    size_t index = SizeClass::Index(size);
    _free_list[index].Push(ptr);
} // ���̻߳��ڴ�Ľӿ�
void* ThreadCache::FetchFromCentralCache(size_t index) {
    return nullptr;
} // ThreadCache��ĳ��Ͱû���ڴ��ˣ������ϼ�CentralCache�����ڴ�