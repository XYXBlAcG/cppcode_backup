#include <cstdio>
#include <stdlib.h>
#include <time.h> 
int op, n, a, b, c, d, e;
int main(){
    a = 0, b = 1048576, n = 100, c = 1, d = 100, e = 50;
    srand((unsigned)time(NULL));
    printf("%d 100 1000\n", n);
    for (int i = 1; i <= n; i++){
        printf("%d ", (rand() % (b - a + 1))+ a);
    }putchar('\n');
    for (int i = 1; i <= n; i++){
        printf("%d %d\n", (rand() % (e - c + 1))+ c, (rand() % (d - e + 1))+ e);
    }
    // for (int i = 1; i <= n; i++){
    //     printf("第 %d 个随机数为: %d\n", i, (rand() % (b - a + 1))+ a);
    // }
}