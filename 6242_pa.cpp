#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <random>
std::mt19937 frand(time(0));
    template <typename T>
    T random(T a = 0, T b = 0x7fffffff){
        return (frand() % (b - a + 1)) + a;
    }
const int N = 1e5 + 5;
int a[N];
int main(){
    int n = 10, m = 10, k = 2;
    printf("%d %d %d\n", n, m, k);
    for (int i = 1; i <= n; i++) printf("%d ", a[i] = (int)random(1, (int)50));
    printf("\n");
    for (int i = 1; i <= m; i++){
        int l = random(1, n), r = random(1, n);
        while(r < l) r = random(1, n);
        printf("%d %d ", l, r);
        int ll = random(1, n - k);
        for (int j = 1; j <= k; j++) printf("%d ", a[j + ll - 1]);
        putchar('\n');
    }
    return 0;
}