#include <cstdio>
#include <vector>
#include <algorithm>
const int N = 2e5 + 5;
int n, m;
// int edge;
int in[N], out[N];
bool vis[N];
int ans[N], pans;
struct Node{
    // int id;
    std::vector<int> id;
    std::vector<int> ed;
}st[N];

void dfs(int u){
    for (int i = st[u].ed.size() - 1; i >= 0; i--){
        int v = st[u].ed[i];
        if(!vis[st[u].id[i]]){
            vis[st[u].id[i]] = 1;
            st[u].ed.pop_back();
            dfs(v);
        }
    }
    ans[++pans] = u;
}
bool cmp(int a, int b){
    return a > b;
}
int main(){
    scanf("%d%d",&n,&m);
    int cnt = 0;
    for (int i = 1; i <= m; i++){
        int u = 0, v = 0;
        scanf("%d%d",&u,&v);
        st[u].id.push_back(++cnt);
        out[u]++; in[v]++;
        st[u].ed.push_back(v);
    }
    int smo = 0, bo = 0, flag = 0, cha;
    for (int i = 1; i <= n; i++){
        if(in[i] != out[i]) {
            ++flag;
            if(flag == 1){
                cha = in[i] - out[i];
            }
            if(flag == 1) smo = i;
            else bo = i;
        }
    }
    // printf("odd:%d ", odd);
    // printf("smo:%d ", smo);
    // printf("bo:%d \n", bo);
    if(flag != 0 && flag != 2){
        printf("No Solution\n");
    }
    // else if(odd && !st[smo].ed.size() && !st[smo].ed.size()){
    //     printf("No Solution\n");
    // }
    else{
        for (int i = 1; i <= n; i++){
            std::sort(st[i].ed.begin(),st[i].ed.end(), cmp);
        }
        if(!flag){
            // printf("Way 1\n");
            for (int i = 1; i <= n; i++){
                if(st[i].ed.size()){
                    dfs(i);
                    break;
                }
            }
        }else{
            // printf("Way 2\n");
            if(cha <= 0){\
                // printf("Way 3\n");
                dfs(smo);
            }else{
                // printf("Way 4\n");
                dfs(bo);
            }
        }
        for (int i = pans; i > 0; i--){
            printf("%d ", ans[i]);
        }
    }
    return 0;
}