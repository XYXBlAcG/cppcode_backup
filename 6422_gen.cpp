#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define INF 1000000000
int s = 1, t = 2;
int main(){
    int n = 1000, m = 3000, s = 1, t = 1000;
    printf("%d %d %d %d\n", n, m, s, t);
    for (int i = 2; i <= 999; i++){
        printf("%d %d %d\n", i - 1, i, INF);
        printf("%d %d %d\n", i, t, 1);
        printf("%d %d %d\n", i, i, INF);
    }
    for (int i = 2; i <= 7; i++){
        printf("%d %d %d\n", i, i, INF);
    }
    return 0;
}