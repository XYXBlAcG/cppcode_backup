#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
const int N = 18005, M = 18005;
struct Node {
    int v, w;
} dui[M];
int n, m, dis[N], pdui;
std::vector<Node> st[N];
bool cmp(const Node& a, const Node& b) { return a.w > b.w; }
void dj(int s) {
    memset(dis, INF, sizeof(dis));
    dis[s] = 0;
    dui[++pdui] = { s, 0 };
    std::push_heap(dui + 1, dui + pdui + 1, cmp);
    while (pdui) {
        int u = dui[1].v;
        std::pop_heap(dui + 1, dui + (pdui--) + 1, cmp);
        for (auto ed : st[u]) {
            int v = ed.v, w = ed.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                dui[++pdui] = { v, dis[v] };
                std::push_heap(dui + 1, dui + pdui + 1, cmp);
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v, w; i <= m; i++) scanf("%d%d%d", &u, &v, &w), st[u].push_back({ v, w });
    for (int i = 1; i <= n; i++) {
        dj(i);
        for (int j = 1; j <= n; j++)
            if (dis[j] > ((INF) >> 1))
                printf("inf ");
            else
                printf("%d ", (i != j) ? dis[j] : 0);
        putchar('\n');
    }
    return 0;
}