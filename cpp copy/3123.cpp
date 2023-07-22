#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
typedef long long ll;
const int N = 1e6 + 20;
int n, m;
int vis[N];
struct Node{
    std::vector<int> id;
    std::vector<int> ed;
}st[N];
std::vector<int> res[N]; int pres = 1;
int odd_list[N], odd, cnt;

void dfs(int u){
    for (int i = st[u].ed.size() - 1; i >= 0; i--){
        if(vis[st[u].id[i]]) continue;
        int v = st[u].ed[i];
        // printf("v : %d\n", v);
        // printf("!"); fflush(stdout);
        if(!vis[st[u].id[i]]){
            // printf("in v : %d\n", v);
            vis[st[u].id[i]] = 1;
            dfs(v);
        }
    }
    if(u == n + 1) ++pres;
    else res[pres].push_back(u);
    for (int i = st[u].ed.size() - 1; i >= 0; i--){
        if(vis[st[u].id[i]]) {
            st[u].ed.pop_back();
            st[u].id.pop_back();
        }
    }
}
void add(){
    odd = 0;
    // cnt++;
    for (int i = 1; i <= n; i++){
        if(odd_list[i] & 1){
            st[i].id.push_back(++cnt);
            st[i].ed.push_back(n + 1);
            st[n + 1].id.push_back(cnt);
            st[n + 1].ed.push_back(i);
            odd++;
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        int u = 0, v = 0;
        scanf("%d%d", &u, &v);
        st[u].id.push_back(++cnt);
        st[v].id.push_back(cnt);
        odd_list[u]++; odd_list[v]++;
        st[u].ed.push_back(v);
        st[v].ed.push_back(u);
    }

    add();
    dfs(n + 1);
    for (int i = 1; i <= n; i++){
        if(st[i].ed.size()){
            pres++;
            dfs(i);   
        }
    }
    for (int i = 1; i <= pres; i++){
        if((int)res[i].size() - 1 < 1) continue;
        printf("%d", (int)(res[i].size() - 1));
        for (int j = 0; j < res[i].size(); j++){
            printf(" %d", res[i][j]);
        }printf("\n");
    }
    return 0;
}


// int num[N], ncnt;
// int ans[N], pans, aans[N], paans;
// paans = pans; ncnt = 0;
// for (int i = 1; i <= pans; i++){
//     if(ans[i] == n + 1){
//         ++ncnt;
//         num[ncnt - 1] = (i - num[ncnt - 1]) - 1 ;
//         num[ncnt] = i;
//     }
//     aans[i] = ans[i];
// }
// minus();
// memset(ans, 0, sizeof(ans)); pans = 0;
// int nnncnt = 0, flag1 = 0;
// for (int i = 1; i < paans; i++){
//     if(aans[i] == n + 1){
//         if(num[++nnncnt] - 1 <= 0) continue;
//         // printf("\n");
//         if(flag1){
//             printf("\n");
//         }flag1 = 1;
//         printf("%d", num[nnncnt] - 1);
//         continue;
//     }else
//         printf(" %d", aans[i]);
// }

// gift i love this
// 23 34
// 1 2
// 2 1
// 1 5
// 5 1
// 5 4
// 4 3
// 3 4
// 3 2
// 6 6
// 6 7
// 7 8
// 8 8
// 7 10
// 10 10
// 7 9
// 9 9
// 11 12
// 12 11
// 12 13
// 13 12
// 11 14
// 12 14
// 13 14
// 15 16
// 16 17
// 17 18
// 18 19
// 19 15
// 20 21
// 20 22
// 20 23
// 21 22
// 21 23
// 22 23

// printf("pres = %d\n", pres);
    // for (int i = 1; i <= pres; i++){
    //     if((int)res[i].size() - 1 < 1) {
    //         printf("sizeless\n");
    //         continue;
    //     }
    //     printf("res[i][0] = %d\n", res[i][0]);
    // }

    // void dfs(int u){
//     // printf("!");
//     // printf("u : %d\n", u);
//     for (int i = st[u].ed.size() - 1; i >= 0; i--){
//         if(vis[st[u].id[i]]) {
//             st[u].ed.pop_back();
//             continue;}
//         int v = st[u].ed[i];
//         st[u].ed.pop_back();
//         // printf("v : %d\n", v);
//         // printf("!"); fflush(stdout);
//         if(!vis[st[u].id[i]]){
//             // printf("in v : %d\n", v);
//             vis[st[u].id[i]] = 1;
//             dfs(v);
//         }
//     }
//     if(u == n + 1) ++pres;
//     else res[pres].push_back(u);
// }

    // printf("15: %lu 16: %lu 17: %lu 18: %lu 19: %lu\n",\
    // st[15].ed.size(), st[16].ed.size(), st[17].ed.size(), st[18].ed.size(), st[19].ed.size());
    // memset(vis, 0, sizeof(vis));