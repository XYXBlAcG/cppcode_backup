#include <cstdio>
#include <string>
#include <stdlib.h>
#include <time.h>
#define random(a, b) rand() % (b - a + 1) + a
int n = 100000, l = 20;
int main(){
    srand((unsigned)time(NULL)); 
    printf("%d %d\n", n, l);
    for (int i = 1; i <= n; i++){
        printf("%c", random('a', 'z'));
    }
    return 0;
}