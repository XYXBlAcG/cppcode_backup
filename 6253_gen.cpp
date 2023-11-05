#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include "xyx.h"
using namespace xyx;
const int N = 5e5 + 5;

int main(){
    int n = 100000, m = 500000, top = INT32_MAX;
    printf("%d %d\n", n, m);
    for (int i = 1; i <= n; i++) printf("%d ", random(1, top));
    putchar('\n');
    MakeTree<N> maketree;
    maketree.makeTree(n, 1);
    for (int i = 1; i <= m; i++){
        int op = random(1, n);
        if(op & 1){
            printf("1 %d\n", random(1, n));
        }else{
            printf("2 %d %d\n", random(1, n), random(1, n));
        }
    }
    return 0;
}