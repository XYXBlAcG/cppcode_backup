#include <cstdio>
#include <stdlib.h>
#include <time.h>
#define int long long
signed main(){
    int n = 5e4;
    srand((unsigned)time(NULL));
    // for (int i = 1; i <= n; i++){
    //     if(op != 3){
    //         if(op == 2) scanf("%d%d", &a, &b);
    //         printf("第 %d 个随机数为: %d\n", i, (rand() % (b - a + 1))+ a);
    //     }else{
    //         printf("第 %d 个随机数为: %lf\n", i, rand() / double(RAND_MAX));
    //     }
    // }
    int a = 1, b = 1e9;
    printf("%lld\n", n);
    for (int i = 1; i <= n; i++){
        printf("%lld ", (rand() % (b - a + 1))+ a);
    }putchar('\n');
    printf("%lld\n", n);
    a = 1, b = 5e4;
    for (int i = 1; i <= n; i++){
        printf("%lld ", (rand() % (b - a + 1))+ a);
    }

    return 0;
}