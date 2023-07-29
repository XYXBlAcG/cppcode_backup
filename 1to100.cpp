#include <cstdio>
int ans;
int main(){
    for (int i = 1; i <= 100; i++){
        ans += (i - 1) * (i - 1);
    }
    printf("%d\n", ans);
    return 0;
}