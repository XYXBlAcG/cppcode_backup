#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
int t, n;
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n <= 3) {
            puts("-1");
            continue;
        }
        if(n == 4) {
            printf("3 1 4 2\n");
            continue;
        }
        for (int i = 1 + !(n & 1); i <= n; i += 2)
            printf("%d ", i);
        printf("%d %d ", n - 3, n - 1);
        for (int i = n - 5; i >= 1 + (n & 1); i -= 2) printf("%d ", i);
        putchar('\n');
    }
    return 0;
}