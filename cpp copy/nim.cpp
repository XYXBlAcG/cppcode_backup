#include <cstdio>
int t, n, sum, tmp;
int main(){
    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        scanf("%d", &n);
        for (int j = 0; j < n; j++) scanf("%d", &tmp), sum = j ? (sum ^ tmp) : tmp;
        puts(sum ? "Yes" : "No");
    }
    return 0;
}