#pragma once
// lib header file
#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>
#include <thread>
#define INIT_POOL_SIZE (1 << 13)
#define INIT_POOL_PAGE 2
#define MAX_SIZE 256*1024

static void*& NextObj(void* obj) {
    return *(void**)obj;
}

class FreeList {
public:
    FreeList() : _free_list(nullptr) {}

    // 头插
    void Push(void* obj) {
        assert(obj);
        NextObj(obj) = _free_list;
        _free_list = obj;
    }
    // 头删
    void* Pop() {
        assert(_free_list != nullptr);
        void* obj = _free_list;
        _free_list = NextObj(obj);
        return obj;
    }
    bool Empty() {
        return _free_list == nullptr;
    }
public:
    void* _free_list;
};


class SizeClass {
public:
    // 计算内存对齐数
    static size_t _Align(size_t size, size_t align_num) {
        if (size % align_num == 0) {
            return size;
        }
        else {
            return (size / align_num + 1) * align_num;
        }
    }
    static size_t Align(size_t size) {
        if (size <= 128) {
            return _Align(size, 8);
        }
        else if (size <= 1024) {
            return _Align(size, 16);
        }
        else if (size <= 1024 * 8) {
            return _Align(size, 128);

        }
        else if (size <= 1024 * 64) {
            return _Align(size, 1024);

        }
        else if (size <= 1024 * 256) {
            return _Align(size, 8192);
        }
        else {
            // error
            assert(false);
            return -1;
        }
    }
    // 计算申请xx字节的内存需要去哪个下标的哈希桶里面取
    static size_t _Index(size_t size, size_t align_num) {
        if (size % align_num == 0) {
            return size / align_num - 1;
        }
        else {
            return size / align_num;
        }
    }
    static size_t Index(size_t size) {
        static size_t bucket[4] = { 16, 56, 56, 56 };
        if (size <= 128) {
            return _Index(size, 8);
        }
        else if (size <= 1024) {
            return _Index(size, 16) + bucket[0];
        }
        else if (size <= 8 * 1024) {
            return _Index(size, 128) + bucket[0] + bucket[1];
        }
        else if (size <= 64 * 1024) {
            return _Index(size, 128 * 8) + bucket[0] + bucket[1] + bucket[2];
        }
        else if (size <= 256 * 1024) {
            return _Index(size, 1024 * 8) + bucket[0] + bucket[1] + bucket[2] + bucket[3];
        }
        else {
            //error
            assert(false);
            return -1;
        }
    }
};