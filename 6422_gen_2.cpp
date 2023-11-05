#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>

int main(){
    int n = 1000, m = 3000, k = 1000000000, s = 1, t = 1000;
    int up = 380;
    printf("%d %d %d %d\n", n, m, s, t);
    for (int i = 2; i <= up; i++){
        printf("%d %d %d\n", s, i, k);
        printf("%d %d %d\n", s, i, k);
    }
    for (int i = 2; i <= up; i++){
        printf("%d %d %d\n", i, up + 1, k);
        printf("%d %d %d\n", i, up + 1, k);
    }
    for (int i = up + 1; i <= 999; i++){
        printf("%d %d %d\n", i, i + 1, k);
        printf("%d %d %d\n", i, i + 1, k);
    }
    for (int i = 1; i <= 246; i++){
        printf("%d %d %d\n", i, i, k);
    }
    return 0;
}