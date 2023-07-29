// MINECRAFT v1.16.5
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 0x3f3f3f3f
const int N = 2e5 + 5;
int n, m, a, b, c;
int A[N];
long long ans = 9223372036854775807;
struct ABC{
    int a, b, c;
}abc[N];
struct Node{
    int v, w, idx;
};
std::vector<Node> st[N]; 
int q1[N], q2[N], q3[N], l1 = 0, r1 = 0, l2 = 0, r2 = 0, l3 = 0, r3 = 0, visa[N], da[N], pa[N], visb[N], db[N], pb[N], visc[N], dc[N], pc[N];
void bfsa(int u) {
    while (l1 <= r1) l1++;
    q1[++r1] = u;
    visa[u] = 1;
    da[u] = 0;
    pa[u] = -1;
    while (l1 <= r1) {
        u = q1[l1++];
        for (auto v : st[u]) {
            if (!visa[v.v]) {
                q1[++r1] = v.v;
                visa[v.v] = 1;
                da[v.v] = da[u] + v.w;
                pa[v.v] = u;
            }
        }
    }
}
void bfsb(int u) {
    l2 = 0, r2 = 0;
    while (l2 <= r2) l2++;
    q2[++r2] = u;
    visb[u] = 1;
    db[u] = 0;
    pb[u] = -1;
    while (l2 <= r2) {
        u = q2[l2++];
        for (auto v : st[u]) {
            if (!visb[v.v]) {
                q2[++r2] = v.v;
                visb[v.v] = 1;
                db[v.v] = db[u] + v.w;
                pb[v.v] = u;
            }
        }
    }
}
void bfsc(int u) {
    l3 = 0, r3 = 0;
    while (l3 <= r3) l3++;
    q3[++r3] = u;
    visc[u] = 1;
    dc[u] = 0;
    pc[u] = -1;
    while (l3 <= r3) {
        u = q3[l3++];
        for (auto v : st[u]) {
            if (!visc[v.v]) {
                q3[++r3] = v.v;
                visc[v.v] = 1;
                dc[v.v] = dc[u] + v.w;
                pc[v.v] = u;
            }
        }
    }
}
int main(){
    scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
    for (int i = 1; i <= m; i++){
        scanf("%d", &A[i]);
    }
    std::sort(A + 1, A + m + 1);
    for (int i = 1; i <= m; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        st[u].push_back((Node){v, 1, i});
        st[v].push_back((Node){u, 1, i});
    }
    bfsa(a); 
    // for (int i = 1; i <= n; i++){
    //     printf("%d ", da[i]);
    // }printf("\n");
    bfsb(b); 
    // for (int i = 1; i <= n; i++){
    //     printf("%d ", db[i]);
    // }printf("\n");
    bfsc(c); 
    // for (int i = 1; i <= n; i++){
    //     printf("%d ", dc[i]);
    // }printf("\n");
    
    // 分配B
    for (int i = 1; i <= n; i++){
        abc[i] = (ABC){da[i], db[i], dc[i]};
    }
    for (int i = 1; i <= n; i++){
        long long tmp = 0;
        if(abc[i].a + abc[i].b + abc[i].c > m) continue;
        // printf("a:%d b:%d c:%d\n", abc[i].a, abc[i].b, abc[i].c);
        for (int j = 1; j <= abc[i].b; j++){
            tmp += A[j];
        }tmp *= 2;
        // printf("第一步:%lld\n", tmp);
        for (int j = abc[i].b + 1; j <= abc[i].a + abc[i].c + abc[i].b; j++){
            tmp += A[j];
        }
        // printf("第二步:%lld \n", tmp);
        ans = std::min(ans, tmp);
    }
    printf("%lld ", ans);
    return 0;
}