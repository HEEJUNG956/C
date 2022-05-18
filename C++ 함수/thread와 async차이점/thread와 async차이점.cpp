#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <cstdio>
using namespace std;
void for_print(int num)
{
    for (int i = 0; i < 100; i++)
        printf("%d번 Thread : %d\n", num, i);
}
int main()
{
    // thread 계산
    //vector<thread> v_thread;
    //v_thread.reserve(2000);

    //for (size_t i = 0; i < 2000; i++)
    //    v_thread.emplace_back(std::thread(for_print, i));

    //for (size_t i = 0; i < 2000; i++)
    //    v_thread[i].join();

    //vector<thread>().swap(v_thread);
    //return 0;


    // async 계산
    vector<future<void>> v_async;
    v_async.reserve(2000);

    for (size_t i = 0; i < 2000; i++)
        v_async.emplace_back(async(launch::async, for_print, i));

    for (size_t i = 0; i < 2000; i++)
        v_async[i].wait();

    return 0;
}
