#include <cstdio>
#include <cstring>

const int MAXN = 1e5 + 10;

int K, N, M, id[510], ans;
int tmp[MAXN];
int vis[MAXN];

struct Node {
    int val;
    Node* next;
    Node(int val) : val(val), next(nullptr) {}
};

Node* st[MAXN];

void dfs(int a) {
    if (vis[a]) {
        return;
    }tmp[a]++; vis[a] = 1;
    Node* p = st[a];
    while (p) {
        int b = p->val;
        if (!vis[b]) {
            dfs(b);
        }
        p = p->next;
    }
}

inline int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

int main() {
    K = read();
    N = read();
    M = read();

    for (int i = 1; i <= K; i++) {
        id[i] = read();
    }

    for (int i = 1; i <= M; i++) {
        int u = read(), v = read();
        Node* node = new Node(v);
        node->next = st[u];
        st[u] = node;
    }

    for (int i = 1; i <= K; i++) {
        memset(vis, 0, sizeof(vis));
        dfs(id[i]);
    }

    for (int i = 1; i <= N; i++) {
        if (tmp[i] == K)
            ans++;
    }

    printf("%d\n", ans);
    return 0;
}
