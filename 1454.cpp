#include <cstdio>
#include <algorithm>
const int N = 3005;
int n, t[N], c[N], ans = -0x3f3f3f3f;
struct Node{
    int t, p, c, s;
}node[N];
bool cmp(Node a, Node b){
    if(a.s ^ b.s) return a.s > b.s;
    return a.p < b.p;
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &node[i].t, &node[i].p, &node[i].c), node[i].s = node[i].p + node[i].c;
    std::sort(node + 1, node + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
        t[i] = t[i - 1] + node[i].t;
    for (int i = n; i; i--)
        c[i] = c[i + 1] + node[i].c;
    for (int i = 1; i <= n; i++){
        ans = std::max(ans, t[i - 1] - node[i].p + c[i + 1]);
    }
    printf("%d\n", ans);
    return 0;
}