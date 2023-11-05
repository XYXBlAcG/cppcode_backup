#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <unordered_map>
#define fail(u) tr[u].fail
#define tr(u, v) tr[u].mp[v]
#define ne(u, v) (tr[u].mp.find(v) == tr[u].mp.end())
using std::string;
const int N = 1e5 + 5;
int n, m, end[N], cnt, fa[N][20], dep[N], dfn[N], sz[N], pdfn;
std::vector<int> nam[N], st[N];
char rd[N];
struct Node{
    int fail;
    std::unordered_map<int, int> mp;
}tr[N];
void read(std::vector<int>& x){
    int num = 0;
    scanf("%d", &num);
    for (int i = 1, elem; i <= num; i++){
        scanf("%d", &elem);
        x.push_back(elem);
    }
}
struct Tree{
    int sum[N];
    int lowbit(int u){return u & -u;}
    void add(int u, int val){
        for (; u <= n; u += lowbit(u)) sum[u] += val;
    }
    int query(int u){
        int ans = 0;
        for (; u; u -= lowbit(u)) ans += sum[u];
        return ans;
    }
}tree;
void build(std::vector<int>& x){
    int p = 0;
    for (auto v : x){
        if(ne(p, v)) tr[p].mp[v] = ++cnt;
        p = tr[p].mp[v];
    }
}
std::queue<int> que;
void get_fail(){
    for (auto v : tr[0].mp) que.push(v.second);
    while(que.size()){
        int t = que.front(); que.pop();
        for (auto v : tr[t].mp){
            if(ne(t, v.second)) tr(t, v.second) = tr(fail(t), v.second);
            else fail(tr(t, v.second)) = tr(fail(t), v.second), que.push(v.second);
        }
    }
    for (int i = 1; i <= cnt; i++){
        st[fail(i)].push_back(i);   
    }
}
void predfs(int u, int fath){
    fa[u][0] = fath;
    dep[u] = dep[fath] + 1;
    dfn[u] = ++pdfn;
    for (int i = 1; i <= 19; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto v : st[u]){
        if(v == fath) continue;
        predfs(v, u);
        sz[u] += sz[v];
    }
    sz[u]++;
}
int lca(int a, int b){
    if(a == b) return a;
    if(dep[a] < dep[b]) std::swap(a, b);
    for (int i = 19; ~i; i--) if(dep[fa[a][i]] >= dep[b]) a = fa[a][i];
    if(a == b) return a;
    for (int i = 19; ~i; i--) if(fa[a][i] ^ fa[b][i]) a = fa[a][i], b = fa[b][i];
    return fa[a][0];
}
void solve(){
    
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        read(nam[i]), nam[i].push_back(-1), read(nam[i]);
    for (int i = 1; i <= m; i++){
        
    }
    predfs(0, 0);
    
    return 0;
}