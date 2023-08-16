#include <cstdio>
int main(){
    int n = 100000;
    printf("%d\n", n);
    for (int i = 0; i < n; i++){
        if(i & 1) printf("%d ", i);
        else printf("%d ", n - i);
    }putchar('\n');
    return 0;
}