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
    

    template <size_t Size>
    struct MakeTree{
        int fa[Size];
        void init(int n){
            for (int i = 1; i <= n; i++) fa[i] = i;
        }
        int find(int a){
            return fa[a] == a ? a : fa[a] = find(fa[a]);
        }
        bool same(int a, int b){
            return find(a) == find(b);
        }
        void merge(int a, int b){
            a = find(a), b = find(b);
            fa[a] = b;
        }
        void makeTree(int n, int st){
            init(n);
            printf("%d\n", n);
            for (int i = 1; i < n; i++){
                int a = random(st, n - 1 + st), b = random(st, n - 1 + st);
                // printf("a = %d, b = %d\n", a, b);
                // printf("find(a) = %d, find(b) = %d\n", find(a), find(b));
                while(same(a, b)) a = random(st, n - 1 + st), b = random(st, n - 1 + st);
                merge(a, b);
                // printf("afind(a) = %d, afind(b) = %d\n", find(a), find(b));
                printf("%d %d\n", a, b);
            }
        }
    };
    


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
