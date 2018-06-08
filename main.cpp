#include <iostream>
#include <cassert>
#include <time.h>
#include <vector>
#include <stack>

#include "MemoryPool.h"

using namespace std;

/* Adjust these values depending on how much you trust your computer */
#define ELEMS 1000000
#define REPS 50

int main()
{

    clock_t start;

    MemoryPool<size_t> pool;
    start = clock();
    for(int i = 0;i < REPS;++i)
    {
        for(int j = 0;j< ELEMS;++j)
        {
            // 创建元素
            size_t* x = pool.newElement();

            // 释放元素
            pool.deleteElement(x);
        }
    }
    std::cout << "MemoryPool Time: ";
    std::cout << (((double)clock() - start) / CLOCKS_PER_SEC) << "\n\n";


    start = clock();
    for(int i = 0;i < REPS;++i)
    {
        for(int j = 0;j< ELEMS;++j)
        {
            size_t* x = new size_t;

            delete x;
        }
    }
    std::cout << "new/delete Time: ";
    std::cout << (((double)clock() - start) / CLOCKS_PER_SEC) << "\n\n";

    return 0;

}
