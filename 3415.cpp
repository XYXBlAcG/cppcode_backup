#include <cstdio>
#include <vector>
#include <algorithm>
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;
struct Edge{
    int u, v;
}edge[N], sorter[N];
std::vector<int> st[N]; std::vector<Edge> temp;
int n, a[N], fath[N], minn[N], ans, cnt, vis[N], idx[N], vvis[N];
int find(int a){
    return fath[a] != a ? fath[a] = find(fath[a]) : a;
}
void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    fath[a] = fath[b];
}
struct Node{
    int son[2], who;
}node[N];
void add(int a, int val){
    int cur = 0;
    for (int i = (1 << 30); i; (i >>= 1)){
        bool tmp = a & i;
        if(!node[cur].son[tmp]) node[cur].son[tmp] = ++cnt; 
        vis[cur]++;
        cur = node[cur].son[tmp];
    }
    node[cur].who = val;
    vis[cur]++;
}
int search(int a){
    int cur = 0, tmp2 = 0;
    for (int i = (1 << 30); i; i >>= 1){
        bool tmp = a & i;
        if(node[cur].son[tmp] && (i == 1 && vis[cur] > 1)){
            // tmp2 += i;
            cur = node[cur].son[tmp];
        }else{
            cur = node[cur].son[tmp ^ 1];
        }
    }
    return node[cur].who;
    // ans = std::max(ans, tmp2);
}
void del(int x){
    std::vector<Edge> tmp3;
    x = find(x);
    for (int i = 1 ; i <= n; i++){
        if(fath[i] == x){
            tmp3.push_back((Edge){i, });
        }
    }
    for (auto j : tmp3){
        int cur = 0, tmp2 = 0;
        for (int i = (1 << 30); i; i >>= 1){
            bool tmp = x & i; vis[cur]--, node[cur].who = 0;
            if(node[cur].son[tmp] && (i == 1 && vis[cur] > 1)){
                cur = node[cur].son[tmp];
            }else{
                cur = node[cur].son[tmp ^ 1];
            }
        }
    }
}
int connect, tot;
void boruvka(){
    connect = 0, tot = 0;
    for (int i = 1; i <= n; i++) minn[i] = INF;
    while (true){
        for (int u = 1; u <= n; u++){
            int v = search(a[u]), w = a[v] ^ a[u];
            if(find(v) == find(u)) continue;
            connect++;
            if(w < minn[u] || w == minn[u] && u < idx[u]) minn[u] = w, idx[u] = u;
            if(w < minn[v] || w == minn[v] && v < idx[v]) minn[v] = w, idx[v] = v;
        }
        if(!connect) break;
        for (int u = 1; u <= n; u++){
            if(minn[u] != INF && !vvis[idx[u]]){
                int v = search(u);
                merge(u, v), tot += a[u] ^ a[v], vvis[idx[u]] = 1;
            }
        }
        
    }
}
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
        sorter[i] = (Edge){a[i], i}, fath[i] = i;
    }
    std::sort(sorter + 1, sorter + 1 + n);
    temp.push_back(sorter[1]);
    for (int i = 2; i <= n; i++){
        if(sorter[i].u == sorter[i - 1].u) merge(sorter[i].v, sorter[i - 1].v);
        else temp.push_back(sorter[i]);
    }
    for (auto v : temp) add(v.u, v.v);
    boruvka();
    printf("%d\n", ans);
    return 0;
}