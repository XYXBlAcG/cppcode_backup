#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
const int N = 1e3 + 5;
int t, n, m, x, y, rec[21][N], id, seg, pans, vis[21][N];
std::vector<int> st[21][N];
struct Node{
    int x, y;
}ans[N];
bool cmp(Node a, Node b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
int sg(int x){
    if(vis[id][x]) return rec[id][x]; vis[id][x] = 1;
    // memset(rec[id], 0, sizeof(rec[id]));
    int mex[N];
    memset(mex, 0, sizeof(mex));
    for (auto v : st[id][x]){
        // rec[id][sg(v)] = 1;
        mex[sg(v)] = 1;
    }
    for (int i = 0; i <= n; i++){
        if(!mex[i]) return rec[id][x] = i;
    }
    return rec[id][x] = 0;
}
int main(){
    scanf("%d", &t);
    for (id = 1; id <= t; id++){
        scanf("%d%d", &n, &m);
        for (int j = 1; j <= m; j++){
            scanf("%d%d", &x, &y);
            st[id][x].push_back(y);
        }
        seg ^= sg(1);
    }
    if(seg == 0){
        printf("No Solution.\n");
        return 0; 
    }
    for (int i = 1; i <= t; i++){
        for (auto v : st[i][1]){
            int tmp = rec[i][v];
            for (int x = 1; x <= t; x++){
                if(x != i) tmp ^= rec[x][1];
            }
            if(tmp == 0) ans[++pans] = (Node){i, v};
            // if(seg ^ rec[i][1] ^ rec[i][v] == 0){
            //     ans[++pans] = (Node){i, v};
            // }
        }
    }
    std::sort(ans + 1, ans + 1 + pans, cmp);
    for (int i = 1; i <= pans; i++){
        printf("%d %d\n", ans[i].x, ans[i].y);
    }
    
    
    return 0;
}