#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <vector>
const int N = 3e6 + 5;
std::vector<int> st[N];
int n, fa[N], dfn[N], pdfn, size[N], vis[N], d[N];
int find(int);
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
int belong(int i, int j){return dfn[j] <= dfn[i] && dfn[i] < dfn[j] + size[j];}
void dfs(int u){
    dfn[u] = ++pdfn;
    for (auto v : st[u])
        dfs(v), size[u] += size[v];
    vis[u] = 1;
    int cur = u;
    while(vis[cur] && belong(cur, u)){
        cur = find(cur);
        int nxt = cur + 1;
        if(vis[nxt] && belong(nxt, u)) fa[cur] = nxt;
        cur = nxt;
    }
    d[cur]--, d[u]++;
}
struct FileIO{
    FileIO(){
        freopen("ancester.in", "r", stdin);
        freopen("ancester.out", "w", stdout);
    }
    ~FileIO(){
        fclose(stdin);
        fclose(stdout);
    }
}FileIO;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) fa[i] = i, size[i] = 1;
    for (int i = 2; i <= n; i++){
        int fath = 0;
        scanf("%d", &fath);
        st[fath].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++){
        d[i] += d[i - 1];
        printf("%d\n", d[i]);
    }

    return 0;
}