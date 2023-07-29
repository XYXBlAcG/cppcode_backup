#include <cstdio>
#include <stdlib.h>
#include <time.h> 
int n, op, a, b;
int main(){
    // 1
    printf("输入需要生成随机数的个数: (个数属于(0,2147483647])");
    scanf("%d", &n);
    while(n <= 0){
        printf("\n错误,请重新输入:");
        scanf("%d", &n);
    }
    putchar('\n');
    // 2
    printf("选择操作:\n1.所有范围为[a,b]\n2.对于每一组数输入范围[a,b]\n3.生成0~1之间的浮点数(double类型),输出10位小数\n");
    scanf("%d", &op);
    while((op != 1 and op != 2 and op != 3)){
        printf("错误,请重新输入:");
        scanf("%d", &op);
        putchar('\n');
    }
    if(op == 1){
        scanf("%d%d", &a, &b);
    }
    // 3
    srand((unsigned)time(NULL));
    for (int i = 1; i <= n; i++){
        if(op != 3){
            if(op == 2) scanf("%d%d", &a, &b);
            printf("第 %d 个随机数为: %d\n", i, (rand() % (b - a + 1))+ a);
        }else{
            printf("第 %d 个随机数为: %lf\n", i, rand() / double(RAND_MAX));
        }
    }
    printf("结束.\n");
    return 0;
}