#include <cstdio>
int n;
int main(){
    scanf("%d", &n);
    for (int i = 1; i < n; i++){
        printf("%d %d\n", n - i + 1, n - i);
    }
    return 0;
}