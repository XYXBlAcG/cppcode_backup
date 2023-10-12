#include <cstdio>
#include <algorithm>
const int N = 1e5 + 5;
int n, k, len, res[N];
struct Node{
    int a, b, c, cnt, ans;
    bool operator!=(const Node az) const{
        return (az.a != a) || (az.b != b) || (az.c != c);
    }
}d1[N], d2[N];
bool cmp1(Node a, Node b){
    if(a.a != b.a) return a.a < b.a;
    if(a.b != b.b) return a.b < b.b;
    return a.c < b.c;
}
bool cmp2(Node a, Node b){
    if(a.b != b.b) return a.b < b.b;
    return a.c < b.c;
}
struct Tree{
    int node[N << 1];
    int lowbit(int u){return u & -u;}
    void add(int u, int v){
        for (; u <= k; u += lowbit(u)) node[u] += v;
    }
    int get(int u){
        int ans = 0;
        for (; u; u -= lowbit(u)) ans += node[u];
        return ans;
    }
}tree;
void solve(int l, int r){
    if(l >= r) return;
    int mid = (l + r) >> 1;
    int i = l, j = mid + 1;
    solve(l, mid), solve(mid + 1, r);
    std::sort(d2 + l, d2 + mid + 1, cmp2);
    std::sort(d2 + mid + 1, d2 + r + 1, cmp2);
    for (; j <= r; j++){
        for (; i <= mid && d2[i].b <= d2[j].b; i++)
            tree.add(d2[i].c, d2[i].cnt);
        d2[j].ans += tree.get(d2[j].c);
    }
    for (int o = l; o < i; o++) tree.add(d2[o].c, -d2[o].cnt);
}
int main(){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d%d%d", &d1[i].a, &d1[i].b, &d1[i].c);
    std::sort(d1 + 1, d1 + n + 1, cmp1);
    for (int i = 1, t = 0; i <= n; i++){
        ++t;
        if(d1[i + 1] != d1[i]) d2[++len] = {d1[i].a, d1[i].b, d1[i].c, t, 0}, t = 0;
    }
    solve(1, len);
    for (int i = 1; i <= len; i++){
        res[d2[i].ans + d2[i].cnt] += d2[i].cnt;
        // printf("%d %d\n", d2[i].ans, d2[i].cnt);
    }
    for (int i = 1; i <= n; i++) printf("%d\n", res[i]);
    return 0;
}
/*
0 1
0 1
2 1
1 1
4 1
0 1
2 1
2 1
6 1
9 1
3
1
3
0
1
0
1
0
0
1
*/