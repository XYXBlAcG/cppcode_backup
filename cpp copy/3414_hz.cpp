#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using std::cin;
using std::max;
using std::min;
using std::sort;
using std::string;
using std::swap;

inline int read() {
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * w;
}

const int N = 5e6 + 10;

int n, m, u, v, x, y, z, w, peach, now, us, c, number, pnode, maxpoint, ans, pedge, leave[N], head[N],
    used[2 * N], sigma[N], length, fin;

struct Edge {
    int ver, nxt, weight;
} edge[2 * N];

struct Node {
    int nxt, head, time, type;
} node[N];

void add_edge(int u, int v, int w) {
    edge[++pedge] = { v, head[u], w };
    head[u] = pedge;
    edge[++pedge] = { u, head[v], w };
    head[v] = pedge;
}

void dfs(int point) {
    if (used[point])
        return;
    used[point] = 1;
    sigma[point] = peach;
    for (int i = head[point]; i; i = edge[i].nxt) {
        peach ^= edge[i].weight;
        dfs(edge[i].ver);
        peach ^= edge[i].weight;
    }
    return;
}

void trie() {
    for (int k = 1; k <= n; k++) {
        number = sigma[k];
        now = 0;
        for (int j = 30; j >= 0; j--) {
            us = 0;
            c = number >> j;
            if (c == 1)
                number -= 1 << j;
            for (int i = node[now].head; i; i = node[i].nxt) {
                if (node[i].type == c) {
                    node[now].time++;
                    now = i;
                    us = 1;
                }
            }
            if (!us) {
                node[++pnode] = { node[now].head, 0, 0, c };
                node[now].head = pnode;
                node[now].time++;
                now = pnode;
            }
            if (j == 0) {
                node[now].time++;
                leave[now] = 1;
            }
        }
    }
}

void find() {
    for (int i = 1; i <= n; i++) {
        now = 0;
        number = sigma[i];
        ans = 0;
        for (int j = 30; j >= 0; j--) {
            us = 0;
            c = number >> j;
            if (c == 1)
                number -= (1 << j);
            for (int i = node[now].head; i; i = node[i].nxt) {
                if (node[i].type != c) {
                    now = i;
                    us = 1;
                    ans |= (c ^ 1) << j;
                }
            }
            if (!us) {
                now = node[now].head;
                ans |= c << j;
            }
        }
        ans ^= sigma[i];
        if (ans > fin)
            fin = ans;
    }
}

void delet() {
    n = m = u = v = x = y = z = w = peach = now = us = c = number = pnode = maxpoint = ans = pedge = 0;
    for (int i = 0; i < N; i++) {
        leave[i] = head[i] = used[i] = used[i + N] = node[i].nxt = node[i].head = node[i].time =
            node[i].type = 0;
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i < n; i++) {
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
        }
        dfs(1);
        trie();
        find();
        printf("%d\n", fin);
    }
    return 0;
}