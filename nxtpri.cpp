#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include "/Users/xiexie/Downloads/gmp-6.3.0/nextprime.c"
const int N = 1e5 + 5;

int main(){
    printf("%d\n", gmp_nextprime());
    return 0;
}