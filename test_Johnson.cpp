#include <cstdio>
#include <stdlib.h>
#include <time.h>
#define random(a, b) (rand() % (b - a + 1)) + a
int n = 2000, m = 8000;
int main(){
    srand((unsigned)time(NULL)); 
    printf("%d %d\n", n, m);
    for (int i = 1; i <= m; i++){
        if(i >= 5) printf("%d %d %d\n", random(1, n), random(1, n), random(0, 10000));
        else printf("%d %d %d\n", random(1, n), random(1, n), random(-10000, 0));
    }
    return 0;
}