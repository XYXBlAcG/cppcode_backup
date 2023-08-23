#include <cstdio>
#include <stdlib.h>
#include <time.h>
int main(){
    int n = 40000;
    srand((unsigned)time(NULL));
    printf("%d\n", n);
    int a = 1, b = 1e9;
    for (int i = 1; i <= n; i++){
        printf("%d ", (rand() % (b - a + 1))+ a);
    }putchar('\n');
    int c = 1, d = n;
    printf("%d\n", n);
    for (int i = 1; i <= n; i++){
        int e = (rand() % (d - c + 1))+ c;
        int f = (rand() % (d - e + 1))+ e;
        printf("%d %d\n", e, f);
    }
    return 0;
}