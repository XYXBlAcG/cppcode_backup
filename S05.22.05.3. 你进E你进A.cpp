#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
const int N = 1e5 + 5;
int n, m, a[N];
struct Node{
    int sum, gcd;
}node[N * 4];
struct Tree{
    void build(int u, int l, int r){

    }
    void modify(int u, int l, int r, int ql, int qr, int val){

    }
    void mdf(int u, int l, int r, int pos, int val){

    }
    int querysum(int u, int l, int r){

    }
    int querygcd(int u, int l, int r){

    }
    int querylen(int u, int l, int r){
        
    }
};
signed main(){
    #ifdef ONLINE_JUDGE
    freopen("ntrcreep.in", "r", stdin);
    freopen("ntrcreep.out", "w", stdout);
    #endif
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    for (int i = 1, op, p, l, r, x; i <= m; i++){
        scanf("%lld", &op);
        if(op == 1){
            scanf("%lld%lld", &p, &x);

        }else if(op == 2){
            scanf("%lld%lld%lld", &l, &r, &x);

        }else if(op == 3){
            scanf("%lld%lld", &l, &r);

        }else if(op == 4){
            scanf("%lld%lld", &l, &r);

        }else{
            scanf("%lld%lld", &l, &r);

        }
    }
    return 0;
}