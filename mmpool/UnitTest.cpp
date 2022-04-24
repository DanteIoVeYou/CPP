#define _CRT_SECURE_NO_WARNINGS 1

#include "ccmalloc.h"

void TLSTest() {
    std::thread t1([]() {
        for (int i = 0; i < 5; i++) {
            void* ptr = ccmalloc(8);
            std::cout << std::this_thread::get_id() << "  " << pThreadCache << std::endl;
        }
        });

    std::thread t2([]() {
        for (int i = 0; i < 5; i++) {
            void* ptr = ccmalloc(8);
            std::cout << std::this_thread::get_id() << "  "<< pThreadCache << std::endl;
        }
        });

    t1.join();
    t2.join();
}


void TestAlloc1() {

    void* p1 = ccmalloc(6);
}
int main()
{
    //TLSTest();
    TestAlloc1();
    return 0;
}
