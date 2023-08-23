#include <cstdio>
#include <algorithm>
const int N = 1e5 + 5;
struct Node{
    int x, l, r, id, type; // x 下标, 
    bool operator < (const Node& i){
        return x < i.x;
    }
}p[N];
int n, a[N], m, ans[N];
void add();
int sum(int x);
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", a + i);
        p[i] = (Node){i, a[i], 0};
    }
    int cnt = n;
    for (int i = 1; i <= m; i++){
        int a, b, x, y;
        scanf("%d%d%d%d", &a, &b, &x, &y);
        p[++cnt] = (Node){a - 1, x, y, i, 1};
        p[++cnt] = (Node){b - 1, x, y, i, 2};
    }
    std::sort(p + 1, p + 1 + cnt);
    for (int i = 1; i <= cnt; i++){
        if(p[i].type == 0) add();
        else if(p[i].type == 1) ans[p[i].id] -= sum(p[i].r) - sum(p[i].l - 1);
        else if(p[i].type == 2) ans[p[i].id] += sum(p[i].r) - sum(p[i].l - 1);
    }
    return 0;
}