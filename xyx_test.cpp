#include <cstdio>
#include <algorithm>
#include "xyx.h"
using namespace xyx;
const int N = 1e5 + 5;
Heap<std::pair<int, int>, N> heap;
MakeTree<N> maketree;
MakeGraph<N> makeGraph;
BITS<int, N, 100> bits;
int main(){
    // maketree.makeTree(20, 1, 1, 1, 100);
    // maketree.makeLian(20, 1, 1, 100);
    // freopen("xyxtest.out", "w", stdout);
    makeGraph.DAG(1000, 499501, 0);
    // fclose(stdout);
    return 0;
}


// printf("%d\n", xyx::moder((int)1e9 + 7, 1, 4, 5, 6, 1324234, 546456, 678678, 3423423, 192837464251));
    // printf("%d\n", xyx::max(1, 2, 3, 5, 8, 20));
    // for (int i = 1; i <= 100; i++){
    //     int j = i * i;
    //     xyx::output(5, "i = ", i, ", j = ", j);
    // }
    // xyx::moder((int)1e9 + 7, 1, 2, 3, 4, 5);
    // heap.push({1, 1});
    // heap.push({1, 2});
    // heap.push({2, 1});
    // for (auto v : heap){
    //     printf("%d %d\n", v.first, v.second);
    // }
    // int a = 0, b = 0, c = 0, d = 0, e = 0;
    // int a, b, c, d, e;
    // fin(a, b, c, d, e);
    // printf("%d %d %d %d %d\n", a, b, c, d, e);
    // __int128_t int128;
    // fin(int128);
    // int128 -= 114;
    // fout(int128);
    // randA<1000>(100);
    // q.enque(1);
    // printf("%d\n", std::max(1, 2, 3, 4, 5, 6));
    // printf("%d\n", xyx::max(114, 514, 1919, 810, 2736123, 345345,12312, 23423));
    // printf("%d\n", std::max({114, 514, 1919, 810, 2736123, 345345,12312, 23423})); 
    // __int128_t int128;
    // fin(int128);
    // fout(int128);
    // freopen("maketree.out", "w", stdout);
    // int n = 10000;
    // maketree.makeTree(n, 1);