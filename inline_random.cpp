#include <cstdio>
// #include <cstdlib>
#include <random>
#include <iostream>
#include <ctime>
#include <algorithm>
namespace xyx{
    std::mt19937 frand(time(0));
    template <typename T>
    T random(T a = 0, T b = 0x7fffffff){
        return (frand() % (b - a + 1)) + a;
    }
    // 随机排列
    template <size_t Size>
    void randA(int n){
        printf("%d\n", n);
        std::vector<int> v = {};
        for (int i = 1; i <= n; i++)
            v.push_back(i);
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(v.begin(), v.end(), g);
        std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
        putchar('\n');
    }


    // old rand
    // void frand(){srand((unsigned)time(NULL));}
    // void ffrand(unsigned u){srand(u);}
    // template <typename T>
    // T random(T a = 0, T b = RAND_MAX){
    //     return (rand() % (b - a + 1)) + a;
    // }
    // template <typename T>
    // T rand01(){return rand() / double(RAND_MAX);}
};
