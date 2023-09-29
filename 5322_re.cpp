#include <cstdio>
#include <string>
#include <iostream>
#define int unsigned long long
const int N = 1e6 + 5;
int n, m, jc[N], P = 99991, d[N];
char str[N];
void pre(){
    jc[0] = 1;
    for (int i = 1; i <= n; ++i)
        jc[i] = jc[i - 1] * P;
}
int lowbit(int x) {return x & (-x);}
int sum(int x){
    int res = 0;
    for (; x; x -= lowbit(x))
        res += d[x];
    return res;
}
void add(int x, int c){
    for (; x <= n; x += lowbit(x)) d[x] += c;
}
bool check(int l1, int r1, int l2, int r2){
    if(l1 < l2) return (sum(r1) - sum(l1 - 1)) * jc[l2 - l1] == (sum(r2) - sum(l2 - 1));
    else return (sum(r1) - sum(l1 - 1)) == (sum(r2) - sum(l2 - 1)) * jc[l1 - l2];
}
signed main(){
    scanf("%llu%llu", &n, &m);
    pre();
    std::cin >> str;
    for (int i = 1; i <= n; i++){
        str[i - 1] = str[i - 1] - 'a' + 1;
        add(i, (str[i - 1]) * jc[i]);
    }
    for (int i = 1; i <= m; i++){
        int op, x, l1, r1, l2, r2;
        char cc;
        scanf("%llu", &op);
        if(op == 1){
            scanf("%llu", &x);
            std::cin >> cc; cc = cc - 'a' + 1;
            add(x, (cc - str[x - 1]) * jc[x]);
            str[x - 1] = cc;
        }else{
            scanf("%llu%llu%llu%llu", &l1, &r1, &l2, &r2);
            if(check(l1, r1, l2, r2)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}