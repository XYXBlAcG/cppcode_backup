#include <bits/stdc++.h>

using i64 = long long;

inline int read() {
    bool sym = false; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

const int N = 5E5 + 10;

struct Edge {
    int to, next;
} edge[N << 1]; // 链式前向星

int head[N << 1], cnt, ans[N];

void add(int x, int y) {
    // 链式前向星加边
    edge[++cnt].to = y;
    edge[cnt].next = head[x];
    head[x] = cnt;
}

int fa[N][20], deep[N];

void dfs(int x, int father) {
    // 求 x 的深度 deep[x] 和 fa[x][], father 是 x 的父节点
    deep[x] = deep[father] + 1;
    // 深度：比父节点深度多 1
    fa[x][0] = father;
    // 记录父节点
    for (int i = 1; (1 << i) <= deep[x]; i++) {
        // 求 fa[][] 数组, 最多到根节点
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    }
    for (int i = head[x]; i; i = edge[i].next) {
        // 遍历节点 i 的所有孩子
        if (edge[i].to != father) {
            // 邻居：除了父亲, 都是孩子
            dfs(edge[i].to, x);
        }
    }
}

int LCA(int x, int y) {
    if (deep[x] < deep[y]) {
        // 让 x 位于更底层, 即 x 的深度值更大
        std::swap(x, y);
    }
    // 把 x 和 y 提到相同的高度
    for (int i = 19; i >= 0; i--) {
        // x 最多跳 19次, 2^19 > 5e5 + 10;
        if (deep[x] - deep[y] >= (1 << i)) {
            // 如果 x 跳过头了, 就换一个小的 i 重新跳
            x = fa[x][i];
            // 如果 x 还没跳到 y 的层, 就更新 x 继续跳
        }
    }
    if (x == y) {
        return x;
        // y 就是 x 的祖先
    }

    // x 和 y 同步向上跳, 找到 LCA
    for (int i = 19; i >= 0; i--) {
        // 如果祖先相等, 说明跳过头了, 换一个小的 i 重新跳
        if (fa[x][i] != fa[y][i]) {
            // 如果祖先不相等, 就更新 x 和 y 继续跳
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
    // 最后 x 位于 LCA 的下一层, 父节点 fa[x][0] 就是 LCA
}

int main() {
    int n = read(), m = read(), root = read();
    for (int i = 1; i < n; i++) {
        // 链式前向星建树
        int u = read(), v = read();
        add(u, v), add(v, u);
    }
    dfs(root, 0);
    // 计算每个节点的深度并预处理 fa[][] 数组
    
    for (int i = 1; i <= m; i++) {
        int x = read(), y = read();
        ans[i] = LCA((x + ans[i - 1]) % (n + 1), (y + ans[i - 1]) % (n + 1));
        // std::cout << LCA(x, y) << "\n";
    }
    for (int i = 1; i <= m; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}