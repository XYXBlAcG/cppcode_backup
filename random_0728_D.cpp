#include <cstdio>
#include <stdlib.h>
#include <time.h> 
int op, n, a, b, c, d, e, m;
int main(){
    a = 0, b = 1e9, n = 1000, m = 1000, c = 1, d = 100, e = 50;
    srand((unsigned)time(NULL));
    printf("%d\n", n);
    for (int i = 1; i <= n; i++){
        printf("%d %d\n", (rand() % (b - a + 1)) + a, (rand() % (b - a + 1)) + a);
    }putchar('\n');
    printf("%d\n", m);
    int aaa = 1, zzz = 3;
    for (int i = 1; i <= m; i++){
        int kk = (rand() % (zzz - aaa + 1)) + aaa;
        printf("%d ", kk);
        if(kk == 1) printf("%d %d\n", (rand() % (c - n + 1)) + n, (rand() % (c - n + 1)) + n);
        else printf("%d %d\n", (rand() % (c - n + 1)) + n, (rand() % (b - a + 1)) + a); 
    }
    // for (int i = 1; i <= n; i++){
    //     printf("%d %d\n", (rand() % (e - c + 1))+ c, (rand() % (d - e + 1))+ e);
    // }
    // for (int i = 1; i <= n; i++){
    //     printf("第 %d 个随机数为: %d\n", i, (rand() % (b - a + 1))+ a);
    // }
}