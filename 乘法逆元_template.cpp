#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define int long long
const int N = 1e5 + 5;
int qp(int a, int b, int c){
    int ans = 1;
    while(b){
        if(b & 1) (ans *= a) %= c;
        (a *= a) %= c;
        b >>= 1;
    }
    return ans;
}
int inv(int a, int b){
    return qp(a, b - 2, b);
}
signed main(){
    int n, p;
    scanf("%d%d")
    return 0;
}