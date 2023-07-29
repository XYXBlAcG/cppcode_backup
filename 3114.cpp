#include <cstdio>
#include <vector>
#include <cstring>
const int MAXN = 1e5 + 10;
const int MAXM = 5e4 + 10;
int K, N, M, id[510], ans, who;
int tmp[MAXN];
int vis[MAXM];
std::vector<int> st[MAXN];
void dfs(int a){
    if(vis[a] == who){ 
        return;
    }tmp[a]++; vis[a] = who;
    for(int i = 0; i < st[a].size(); i++){
        int b = st[a][i];
        if(vis[b] != who){
            dfs(b);
        }
    }
}
int main(){
    scanf("%d%d%d", &K, &N, &M);
    for (int i = 1; i <= K; i++){
        scanf("%d", &id[i]);
    }
    for (int i = 1; i <= M; i++){
        int u , v;
        scanf("%d%d", &u, &v);
        st[u].push_back(v);
    }
    for (who = 1; who <= K; who++){
        dfs(id[who]);
    }
    for (int i = 1; i <= N; i++){
        if(tmp[i] == K) ans++;
    }
    printf("%d\n", ans);
    return 0;
}