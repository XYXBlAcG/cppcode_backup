#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
// #include <stack>
const int N = 3e5 + 10;
int T, n, m;
std::vector<int> st[N], col[N];
int to[N];
//blue 1 red 0
int fa[N];
int vis[N];
int anc[N];
// int col[N];
int rootcol = -1;
// std::vector<int> rootcol;
// std::stack<int> father, tmp;
int root;
bool dfs(int a, int c){
    int ans = 1;
    anc[a] = 1;
    vis[a] = 1;
    // printf("a:%d \n", a);
    for (int i = 0; i < st[a].size(); i++){
        int b = st[a][i];
        if (!vis[b]){
            if(a == root && i == 0) rootcol = c ^ 1; 
            // rootcol.push_back(c ^ 1);
            // rootcol = c ^ 1;
            col[a][b] = c ^ 1;
            // fa[b] = a;
            // father.push(a);
            // bool flag = dfs(b, c ^ 1); 
            ans = dfs(b, c ^ 1);
            // if(rootcol.size()) rootcol.pop_back();
            // if(!father.empty()) father.pop();
        }else if (b == root){
            col[b][a] = c ^ 1;
            // if(col[a][b] == col[b][a]){
                if(rootcol != col[b][a]) return 1;                
                else{
                    col[b][a] ^= 1; 
                    // rootcol.push_back((flag ^ 1)); 
                    rootcol = 2;
                    printf("!");
                    fflush(stdout);
                    // for (int o = father.top(); st[o].size() <= 2 && !father.empty(); ){
                    //     tmp.push(o), father.pop();
                    //     col[father.top()][o] ^= 1;
                    // }
                    // printf("?");
                    // fflush(stdout);
                    // if(father.empty()){
                    //     return 0;
                    // }
                    // while(!tmp.empty()){
                    //     father.push(tmp.top()); tmp.pop();
                    // }
                    printf(".");
                    fflush(stdout);
                    // return 0;
                }
            // }
        }else if(anc[b] == 1){
            col[a][b] = c ^ 1;
        }
    }
    anc[a] = 0;
    return ans;
}

bool check() {
    for (root = 1; root <= n; root++) {
        // rootcol.clear();
        rootcol = -1;
        // std::stack<int>().swap(father);
        if (!vis[root] && !dfs(root, 1)) return 0;
    }
    return 1;
}

int main(){
    scanf("%d", &T);
    while(T--){
        //main
        for (int i = 1; i <= N; i++){
            st[i].clear();
            col[i].clear();
        }
        memset(vis, 0, sizeof(vis));
        memset(anc, 0, sizeof(anc));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++){
            int x, y;
            scanf("%d%d", &x, &y);
            st[x].push_back(y);
            st[y].push_back(x);
            to[x] = i; to[y] = i;
            
        }
        if(check()){
            printf("No solution.\n");
        }else{
            // for (int i = root; ; ){
            //     std::cout << (col[i][0] ? "B" : "R");
            // }
            printf("Solution:\n");
            printf("\n");
        }
    }
    return 0;
}

// bool flag = 0;
// for (int o = a; o != root; o = st[o][fa[o]]){
//     if(st[fa[o]].size() <= 2){
//         col[o] ^= 1;
//     }else{
//         root = fa[o];
//         flag = 1;
//         break;
//     }
    
// }
// if(flag){
    
//     return dfs(root, c ^ 1);
// }else{
//     return 0;
// }

// if(!flag){
//     if(i + 1 < st[a].size() && st[a].size() > 2){
//         continue;
//     }else{
//         col[a] ^= 1;
//         return 0;
//     }
// }


// if(a == root){
//     if(rootcol == -1){
//         rootcol = c ^ 1;
//     }else if(rootcol == 0 && c == rootcol){
//         rootcol = 2;
//     }else if(rootcol == 1 && c == rootcol){
//         rootcol = 2;
//     }else{
//         rootcol = c ^ 1;
//     }
// }

// for (int j = 0; j < rootcol.size(); j++){
//     if(rootcol[j] == 0 && flag == 0 || !j) {flag = 0; continue;}
//     else if(rootcol[j] == 1 && flag == 1 || !j) {flag = 1; continue;}
//     else return 1;
// }