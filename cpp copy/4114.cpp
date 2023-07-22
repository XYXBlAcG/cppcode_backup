#include <cstdio>
#include <algorithm>
// const int N = 2e9 + 10;
typedef unsigned long long llu;
int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int n;
llu ans, yinzi;

void getP(int id, llu val, llu the){
    if(id >= 10) return;
    if(yinzi < val || yinzi == val && the < ans){ yinzi = val; ans = the;}
    for (int i = 1;; i++){
        if(prime[id] * the > n) break;
        getP(id + 1, val * (i + 1), the *= prime[id]);
    }
}

int main(){
    scanf("%d",&n);
    getP(0, 1, 1);
    printf("%llu\n", ans);
    return 0;
}