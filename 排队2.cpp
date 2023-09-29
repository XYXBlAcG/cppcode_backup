#include <cstdio>
#include <vector>
#include <algorithm>
const int N = 1005;
int n, m, vis[N], ccc;
struct Node{
    int l, r;
}p[N];
std::vector<int> ans[N];
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        p[i] = {0, 0};
    // for (int o = 1; o <= m; o++){
    //     int i, j, a;
    //     scanf("%d%d%d", &i, &j, &a);
    //     int cnt = i;
    //     for (int w = 1; p[cnt].r && w <= a; cnt = p[cnt].r, w++);
    //     p[p[j].l].r = p[cnt].r;
    //     p[p[cnt].r].l = p[j].l;
    //     p[cnt].r = p[i].r;
    //     p[p[i].r].l = cnt;
    //     p[i].r = j;
    //     p[j].l = i;
    // }
    for (int o = 1; o <= m; o++){
        int i, j, a;
        scanf("%d%d%d", &i, &j, &a);
        int k = j, cnt = 1;
        for (; p[k].r && cnt <= a; k = p[k].r, cnt++);
        p[p[j].l].r = p[k].r;
        p[p[k].r].l = p[j].l;
        p[k].r = p[i].r;
        p[p[i].r].l = k;
        p[j].l = i;
        p[i].r = j;
    }
    int cntt = 0;
    for (int i = 1; i <= n; i++){
        if(vis[i]) continue;
        ++cntt;
        int ooo = i;
        for (; p[ooo].l; ooo = p[ooo].l);
        for (; ooo; ooo = p[ooo].r){
            vis[ooo] = 1;
            ans[cntt].push_back(ooo);
            // printf("%d ", ooo);
        }
        // putchar('\n');
    }
    // for (int i = 1; i <= n; i++){
    //     if(!vis[i]){
    //         ccc++;
    //         int v = i;
    //         for (; p[v].l; v = p[v].l)
    //         for (; v; v = p[v].r){
    //             ans[ccc].push_back(v);
    //             vis[v] = 1;
    //         }
    //     }
    // }
    std::sort(ans + 1, ans + 1 + cntt);
    printf("%d\n", cntt);
    for (int i = 1; i <= cntt; i++){
        for (auto v : ans[i]){
            printf("%d ", v);
        }putchar('\n');
    }
    return 0;
}