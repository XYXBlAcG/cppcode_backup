#include <cstdio>
#include <vector>
#include <algorithm>
const int N = 1005;
int n, m, vis[N];
struct Node{
    int l, r;
}q[N];
std::vector<int> st[N];
int main(){
    scanf("%d%d", &n, &m);
    for (int o = 1; o <= n; o++)
        q[o] = (Node){0, 0};
    for (int o = 1; o <= m; o++){
        int i, j, a;
        scanf("%d%d%d", &i, &j, &a);
        int k = j, cnt = 1;
        for (; q[k].r && cnt <= a; k = q[k].r, cnt++);
        q[q[j].l].r = q[k].r;
        q[q[k].r].l = q[j].l;
        q[k].r = q[i].r;
        q[q[i].r].l = k;
        q[j].l = i;
        q[i].r = j;
    }
    int cntt = 0;
    
    for (int i = 1; i <= n; i++){
        if(vis[i]) continue;
        ++cntt;
        int ooo = i;
        for (; q[ooo].l; ooo = q[ooo].l);
        for (; ooo; ooo = q[ooo].r){
            vis[ooo] = 1;
            st[cntt].push_back(ooo);
            // printf("%d ", ooo);
        }
        // putchar('\n');
    }
    
    std::sort(st + 1, st + 1 + cntt);
    printf("%d\n", cntt);
    for (int i = 1; i <= cntt; i++){
        for (auto v : st[i]){
            printf("%d ", v);
        }putchar('\n');
    }
    return 0;
}