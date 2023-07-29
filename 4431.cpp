#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f 
#define int long long
const int N = 4e5 + 5;
int n, m, a[N], op, l, r, t[N];
int ask(int v, int l, int r, int L, int R){
    if(L <= l && r <= R){
        return t[v];
    }
    if(r < L || R < l){
        return 0;
    }
    int m = (l + r) >> 1;
    return ask(v << 1, l, m, L, R) + ask(v << 1 | 1, m + 1, r, L, R);
}
void modify(int v, int l, int r, int id, int add){
    if(r < id || id < l){
        return;
    }
    if(l == r && r == id){
        t[v] += add;
        return;
    }
    int m = (l + r) >> 1;
    modify(v << 1, l, m, id, add), modify(v << 1 | 1, m + 1, r, id, add);
    t[v] = t[v << 1] + t[v << 1 | 1];
}
void build(int v, int l, int r){
    if(l == r){
        t[v] = a[l]; return;
    }
    int m = (l + r) >> 1;
    build(v << 1, l, m), build(v << 1 | 1, m + 1, r);
    t[v] = t[v << 1] + t[v << 1 | 1];
}
signed main(){
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++){
        scanf("%lld",&a[i]);
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++){
        scanf("%lld%lld%lld", &op, &l, &r);
        if(op == 1){
            modify(1, 1, n, l, r);
        }else{
            printf("%lld\n", ask(1, 1, n, l, r));
        }
    }
    return 0;
}