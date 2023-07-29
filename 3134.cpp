#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
const int N = 1e6 + 5;
const int M = 1e6 + 5;
typedef unsigned long long llu;
int c2n[28], flag_1[28], pair[2][28], idx[N], id2p[N], rock[N];
int point[N], vis[N], flag[28];
std::vector<int> st[M];
std::vector<int> offhid[M];
int dist[N + M], queue[N + M], l = 0, r = 1;
int now = 0;
int n, m;
void bfs(){
    int u = 0;
    while(l < r){
        u = queue[l];
        for (int i = 0; i < st[u].size(); i++){
            int v = st[u][i];
            if(!vis[v]){
                vis[v] = 1;
                queue[r++] = v;
                dist[v] = dist[u] + 1;
            }
        }
        l++;
    }
}
int main(){
    scanf("%d%d ",&n,&m);
    // memset(dist, 1, sizeof(dist));
    int cnt = 0;
    for (char c = getchar(); c > 32; c = getchar()){
        point[++cnt] = (int)c;
    }
    for (int i = 1; i <= n; i++){
        if(point[i] >= 'A' && point[i] <= 'Z'){
            if(!c2n[(int)(point[i] - 'A' + 1)]){
                c2n[(int)(point[i] - 'A' + 1)] = i;
            }else{
                st[c2n[(int)(point[i] - 'A' + 1)]].push_back(i);
                st[i].push_back(c2n[(int)(point[i] - 'A' + 1)]);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if(point[i] >= 'A' && point[i] <= 'Z'){
            point[i] = (int)'.';
        }
    }
    for (int i = 1; i <= n; i++){
        int t = point[i];
        if(t >= 'a' && t <= 'z'){
            if(!pair[flag[t - 'a' + 1]][t - 'a' + 1]){
                pair[flag[t - 'a' + 1]][t - 'a' + 1] = i;
                id2p[i] = flag[t - 'a' + 1];
                idx[i] = ++cnt;
                // printf("%d 配对的是 %d\n", i, idx[i]);
            }else{
                flag[t - 'a' + 1] ^= 1;
                pair[flag[t - 'a' + 1]][t - 'a' + 1] = i;
                id2p[i] = flag[t - 'a' + 1];
                idx[i] = ++cnt;
                // printf("%d 配对的是 %d\n", i, idx[i]);
                // printf("所以 %d 和 %d 链接\n", i, idx[pair[flag[t - 'a' + 1] ^ 1][t - 'a' + 1]]);
                // printf("%d 和 %d 链接\n", idx[i], pair[flag[t - 'a' + 1] ^ 1][t - 'a' + 1]);
                // 写的一坨屎，我自己都看不懂
                st[idx[pair[flag[t - 'a' + 1] ^ 1][t - 'a' + 1]]].push_back(i);
                st[idx[i]].push_back(pair[flag[t - 'a' + 1] ^ 1][t - 'a' + 1]);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        int t = point[i];
        if(t == '#'){
            rock[i] = ++cnt;
            st[cnt].push_back(i); //rock入 本体出
        }
    }
    //passed!
    for (int i = 1; i <= m; i++){
        int u = 0, v = 0;
        scanf("%d%d", &u, &v);
        if(point[v] == '.' && point[u] == '.'){
            st[u].push_back(v);
            st[v].push_back(u);
        }else if((point[u] < 'a' or point[u] > 'z') && point[v] == '#'){
            // rewrite plz
            // st[u].push_back(++cnt);
            // st[cnt].push_back(v);
            // st[v].push_back(u);
            st[u].push_back(rock[v]);
            st[v].push_back(u);
            // point[v] = (int)'.';
        }else if(point[u] >= 'a' && point[u] <= 'z' && point[v] >= 'a' && point[v] <= 'z' && point[u] != point[v]){
            // st[u].push_back(idx[pair[id2p[point[v]]][point[v] - 'a' + 1]]);
            // st[v].push_back(idx[pair[id2p[point[u]]][point[u] - 'a' + 1]]);
            st[u].push_back(idx[v]);
            st[v].push_back(idx[u]);
        }else if(point[u] >= 'a' && point[u] <= 'z' && point[v] != '#' && (point[v] < 'a' or point[v] > 'z')){
            st[u].push_back(v);
            // st[v].push_back(idx[pair[id2p[point[u]]][point[u] - 'a' + 1]]);
            st[v].push_back(idx[u]);
        }else if(point[u] >= 'a' && point[u] <= 'z' && point[v] == '#'){
            // rewrite plz
            st[u].push_back(rock[v]);
            // st[v].push_back(idx[pair[id2p[point[u]]][point[u] - 'a' + 1]]);
            st[v].push_back(idx[u]);
            // st[u].push_back(++cnt);
            // st[cnt].push_back(idx[pair[id2p[point[u]]][point[u] - 'a' + 1]]);
            // st[cnt].push_back(v);
        }else if(point[u] >= 'a' && point[u] <= 'z' && point[v] >= 'a' && point[v] <= 'z' && point[u] == point[v]){
            if(u == v){
                st[u].push_back(v);
            }
        }else if(point[v] >= 'a' && point[v] <= 'z'){
            // st[u].push_back(idx[pair[id2p[point[v]]][point[v] - 'a' + 1]]);
            st[u].push_back(idx[v]);
            // st[pair[id2p[point[v]]][point[v]] - 'a' + 1].push_back(u);

            // st[v].push_back(u);
        }
    }

    // for (int i = 1; i <= cnt; i++){
    //     for (int j = 0; j < st[i].size(); j++){
    //         printf("%d %d\n", i, st[i][j]);
    //     }
    // }


    
    st[0].push_back(1);
    //setup edge output
    // for (int i = 1; i <= n ; i++){
    //     for (int j = 0; j < st[i].size(); j++){
    //         printf("从%d到%d\n", i, st[i][j]);
    //     }
    // }
    bfs();
    // for (int i = 1; i <= n; i++){
    //     printf("vis[%d] : %d\n", i, vis[i]);
    // }
    for (int i = 1; i <= n; i++){
        if(!vis[i]) {printf("-1 "); continue;}
        printf("%d ", dist[i] - 1);
    }
    return 0;
}

// offline (old)
// for (int i = 1; i <= 26; i++){
//     int a = pair[0][i], b = pair[1][i];
//     if(a){
//         cnt++;
//         for (int j = 0; j < offhid[a].size(); j++){
//             st[offhid[a][j]].push_back(a);
//             st[cnt].push_back(offhid[a][j]);
//         }
//         st[b].push_back(cnt);
//         cnt++;
//         for (int j = 0; j < offhid[b].size(); j++){
//             st[offhid[b][j]].push_back(b);
//             st[cnt].push_back(offhid[b][j]);
//         }
//         st[a].push_back(cnt);
//     }
// }

// for (int i = 1; i <= m; i++){
//     int u = 0, v = 0;
//     scanf("%d%d", &u, &v);
//     int t = point[v];
//     int e = point[u];
//     //online
//     if(t == '.'){
//         // printf("normal\n");
//         st[u].push_back(v);  
//         if(96 < e && e < 123){
//             offhid[u].push_back(u);
//         }else{
//             st[v].push_back(u);
//         }
//     }else if(t == '#'){
//         // printf("rock\n");
//         st[u].push_back(++cnt);
//         st[cnt].push_back(v);
//         if(96 < e && e < 123){
//             offhid[u].push_back(u);
//         }else{
//             st[v].push_back(u);
//         }
//     }else if(t >= 65 && t <= 90){
//         // printf("visible\n");
//         // 显性传送门
//         st[u].push_back(v);
//         // st[v].push_back(u);
//         if(96 < e && e < 123){
//             offhid[u].push_back(u);
//         }else{
//             st[v].push_back(u);
//         }
//         if(c2n[(int)(t - 64)] && !flag_1[(int)(t - 64)]){ 
//             flag_1[(int)(t - 64)] = 1;
//             st[v].push_back(c2n[(int)(t - 64)]);
//             st[c2n[(int)(t - 64)]].push_back(v);
//             // st[c2n[(int)(t - 64)]].push_back(v);
//             // st[v].push_back(c2n[(int)(t - 64)]);
//         }else{
//             if(!flag_1[(int)(t - 64)])
//                 c2n[(int)(t - 64)] = v;
//             // c2n[(int)t - 64] = ++cnt;
//             // st[cnt].push_back(v);
//             // st[v].push_back(v);
//         }
//     }else{
//         // printf("hidden\n");
//         // offline to solve
//         offhid[v].push_back(u);
//         if(!pair[0][(int)(t - 96)]){
//             pair[0][(int)(t - 96)] = v;
//         }else{
//             pair[1][(int)(t - 96)] = v;
//         }
//     }
// }
// // offline (modify)
// for (int i = 1; i <= 26; i++){
//     int a = pair[0][i], b = pair[1][i];
//     if(a){
//         cnt++;
//         if(offhid[a].size()) {
//             st[cnt].push_back(b);
//         }
//         for (int j = 0; j < offhid[a].size(); j++){
//             if(offhid[a][j] == a){
//                 // 显然有误
//                 // st[a].push_back(b);

//                 st[cnt].push_back(b);
                
//                 continue;
//             }else if(offhid[a][j] == b){
//                 // the same
//                 // st[a].push_back(a);
//                 continue;
//             }
//             st[offhid[a][j]].push_back(cnt);
//             // st[cnt].push_back(b);
//         }
//         // st[b].push_back(cnt);
//         cnt++;
//         if(offhid[b].size()){ 
//             st[cnt].push_back(a);
//         }
//         for (int j = 0; j < offhid[b].size(); j++){
//             if(offhid[b][j] == b){
//                 // st[b].push_back(a);

//                 st[cnt].push_back(a);
//                 continue;
//             }else if(offhid[b][j] == a){
//                 // st[b].push_back(b);
//                 continue;
//             }
//             st[offhid[b][j]].push_back(cnt);
//             // st[cnt].push_back(a);
//         }
//         // st[a].push_back(cnt);
//     }
// }

//end re 
// for(int i = 1; i <= m; i++){
//         int u = 0, v = 0;
//         scanf("%d%d", &u ,&v);
        // addedge(u, v);
        // addedge(v, u);
        // if(point[u] == '.'){
        //     st[u].push_back(v);
        //     st[v].push_back(u);
        // }
    // }

//     for (int i = 1; i <= m; i++){
//     int u = 0, v = 0;
//     scanf("%d%d", &u, &v);
//     int t = point[v];
//     int e = point[u];
//     //online
//     if(t == '.'){
//         // printf("normal\n");
//         st[u].push_back(v);  
//         if(96 < e && e < 123){
//             offhid[u].push_back(u);
//         }else{
//             st[v].push_back(u);
//         }
//     }else if(t == '#'){
//         // printf("rock\n");
//         st[u].push_back(++cnt);
//         st[cnt].push_back(v);
//         if(96 < e && e < 123){
//             offhid[u].push_back(u);
//         }else{
//             st[v].push_back(u);
//         }
//     }else if(t >= 65 && t <= 90){
//         // printf("visible\n");
//         // 显性传送门
//         st[u].push_back(v);
//         // st[v].push_back(u);
//         if(96 < e && e < 123){
//             offhid[u].push_back(u);
//         }else{
//             st[v].push_back(u);
//         }
//         if(c2n[(int)(t - 64)] && !flag_1[(int)(t - 64)]){ 
//             flag_1[(int)(t - 64)] = 1;
//             st[v].push_back(c2n[(int)(t - 64)]);
//             st[c2n[(int)(t - 64)]].push_back(v);
//             // st[c2n[(int)(t - 64)]].push_back(v);
//             // st[v].push_back(c2n[(int)(t - 64)]);
//         }else{
//             if(!flag_1[(int)(t - 64)])
//                 c2n[(int)(t - 64)] = v;
//             // c2n[(int)t - 64] = ++cnt;
//             // st[cnt].push_back(v);
//             // st[v].push_back(v);
//         }
//     }else{
//         // printf("hidden\n");
//         // offline to solve
//         offhid[v].push_back(u);
//         if(!pair[0][(int)(t - 96)]){
//             pair[0][(int)(t - 96)] = v;
//         }else{
//             pair[1][(int)(t - 96)] = v;
//         }
//     }
// }
// // offline (modify)
// for (int i = 1; i <= 26; i++){
//     int a = pair[0][i], b = pair[1][i];
//     if(a){
//         cnt++;
//         if(offhid[a].size()) {
//             st[cnt].push_back(b);
//         }
//         for (int j = 0; j < offhid[a].size(); j++){
//             if(offhid[a][j] == a){
//                 // 显然有误
//                 // st[a].push_back(b);

//                 st[cnt].push_back(b);
                
//                 continue;
//             }else if(offhid[a][j] == b){
//                 // the same
//                 // st[a].push_back(a);
//                 continue;
//             }
//             st[offhid[a][j]].push_back(cnt);
//             // st[cnt].push_back(b);
//         }
//         // st[b].push_back(cnt);
//         cnt++;
//         if(offhid[b].size()){ 
//             st[cnt].push_back(a);
//         }
//         for (int j = 0; j < offhid[b].size(); j++){
//             if(offhid[b][j] == b){
//                 // st[b].push_back(a);

//                 st[cnt].push_back(a);
//                 continue;
//             }else if(offhid[b][j] == a){
//                 // st[b].push_back(b);
//                 continue;
//             }
//             st[offhid[b][j]].push_back(cnt);
//             // st[cnt].push_back(a);
//         }
//         // st[a].push_back(cnt);
//     }
// }
    