#include <cstdio>
int main(){
    int u = 0;
    for (int a = 1; a < 100000; a++){
        u = 0;
        for (int n = 1; n <= 2023; n++){
            u += (n * n - n * a) / 5;
        }
        if (u >= -1000 && u <= 1000){
            printf("u:%d\n", u);
            printf("a:%d\n", a);
        }
        // if ((a + u) >= 0 && (a + u) <= 999){
        //     printf("%d",a+u);
        // }
        
    }
    return 0;
}