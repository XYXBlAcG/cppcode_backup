#include <cstdio>
#include <vector>
#include <map>
#include <stdlib.h>
#define random(a, b) rand() % (b - a + 1) + a
#define int unsigned long long
const int N = 55, INF = 0x3f3f3f3f3f3f3f3f, a = random(1, INF);
int rand(int x){
    x ^= a;
    x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
    x ^= a;
    return x;
}
int m, n, d[N], u[N];
std::vector<int> st[N];
std::map<int, int> ma;
void down(int x){
    d[x] = 1;
    for (auto v : st[x]) down(v), d[x] += rand(d[v]);
}
void up(int x){
    for (auto v : st[x]) u[v] = d[v] + rand(u[x] - rand(d[v])), up(v);
}
void clean(){
    for (int i = 1; i <= n; i++) st[i].clear();
}
signed main(){
    scanf("%lld", &m);
    for (int i = 1; i <= m; i++){
        scanf("%lld", &n);
        int fa = 0, tmp = 0;
        for (int j = 1; j <= n; j++){
            scanf("%lld", &tmp);
            st[tmp].push_back(j);
            if(!tmp) fa = j;
        }
        down(fa), u[fa] = d[fa], up(fa);
        int hash = 1;
        for (int j = 1; j <= n; j++) (hash += rand(u[j]));
        if(!ma.count(hash)) ma[hash] = i;
        printf("%lld\n", ma[hash]);
        clean();
    }
    return 0;
}