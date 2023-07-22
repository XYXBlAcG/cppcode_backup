#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
const int N = 5e5 + 5;
long long mod = 1e9 + 7, ans = -1, res = 0; int left = 1, cnt = 0;
struct Node{
    int u, v, w;
}st[N], re[N], che[N]; int pche;
int fath[N], pre;
int n, m;
bool cmp(Node a, Node b) {
    return a.w < b.w;
}
int find(int x){ return fath[x] != x ? fath[x] = find(fath[x]) : x ;}
void merge(int x, int y){ fath[x] = fath[y]; }
void reverse(){
    for (int i = 1; i <= pche; i++){
        
    }
}
void check(){
    for (int i = 1; i <= pche; i++){
        if(find(che[i].u) == find(che[i].v)){
            reverse();
            return;
        }
    }
    // for (int i = left; i <= left + cnt; i++){
    //     if(che[i].u && find(che[i].u) )
    // }
}
void dfs(int p, int l){
    if(!p) { check(); return; }
    // int u = st[l].u, v = st[l].v;
    // re[++pre] = (Node){u, fath[u]};
    // re[++pre] = (Node){v, fath[v]};
    // int U = find(u), V = find(v);
    for (int i = l + 1; i <= left + cnt; i++){
        che[++pche] = st[i];
        dfs(p - 1, i); pche--;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++){
        fath[i] = i;
    }
    for (int i = 1; i <= m; i++){
        int u, v, w;
        scanf("%d%d%d",&u,&v,&w);
        st[i] = (Node){u, v, w};
    }
    std::sort(st + 1, st + 1 + m, cmp);
    for (int i = 1; i <= m; i++){
        int u = st[i].u, v = st[i].v;
        int U = find(u), V = find(v);
        if(U != V){
            merge(U, V);
        }
    }
    for (int i = 1; i <= m; i++){
        if(i != m && st[i + 1].w == st[i].w){
            ++cnt;
        }else{
            dfs(cnt, left);
            printf("ans:%lld, res:%lld\n", ans, res);
            ans = (ans == -1) ? res : (ans * res % mod), res = 0;
            for (int i = pre; i >= 1; i--){
                fath[re[i].u] = re[i].v;
                re[i] = (Node){0, 0, 0};   
            }pre = 0; cnt = 0; left = i + 1;
        }
    }
    printf("%lld\n", (ans == -1) ? 0 : ans);
    return 0;
}