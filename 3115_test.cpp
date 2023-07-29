/* 给一个允许有重边和自环的无向图，
你需要将每条边染色成红色或蓝色，
使得所有度数>=2的点，
都既与一条蓝色边相连，
又与一条红色边相连。问是否有解，有解的话输出一组解，
输出的第一行包含一个正整数T，表示数据的组数。 
对于每组数据，输入的第一行包含两个正整数n和m，表示点数和边数。
其中点用1到n的整数编号。 
接下来m行，每行包含两个正整数，表示一条边。
对于每组数据输出一行。如果无解，输出 No solution.；
如果有解，输出长度为m的一个字符串，
字符串全部由R和B构成，表示按照输入顺序给出的边的颜色。
题目可能有多组解，你只用输出任何一个正确的即可。*/

// #include <iostream>
// #include <vector>
// #include <cstring>

// using namespace std;

// const int MAXN = 100005;

// int n, m;
// int head[MAXN], nxt[MAXN * 2], to[MAXN * 2], cnt;
// int color[MAXN];
// bool vis[MAXN];

// void addEdge(int u, int v) {
//     nxt[++cnt] = head[u];
//     head[u] = cnt;
//     to[cnt] = v;
// }

// bool dfs(int u, int c) {
//     color[u] = c;
//     vis[u] = true;
//     for (int i = head[u]; i; i = nxt[i]) {
//         int v = to[i];
//         if (color[v] == c) return false;
//         if (color[v] == 0 && !dfs(v, 3 - c)) return false;
//     }
//     return true;
// }

// int main() {
//     int T;
//     cin >> T;
//     while (T--) {
//         cin >> n >> m;
//         cnt = 0;
//         memset(head, 0, sizeof(head));
//         memset(color, 0, sizeof(color));
//         memset(vis, false, sizeof(vis));

//         for (int i = 1; i <= m; i++) {
//             int u, v;
//             cin >> u >> v;
//             addEdge(u, v);
//             addEdge(v, u);
//         }

//         bool flag = true;
//         for (int i = 1; i <= n; i++) {
//             if (!vis[i] && !dfs(i, 1)) {
//                 flag = false;
//                 break;
//             }
//         }

//         if (!flag) cout << "No solution." << endl;
//         else {
//             for (int i = 1; i <= m; i++) {
//                 if (color[to[i * 2]] == 1 && color[to[i * 2 + 1]] == 2) cout << "R";
//                 else cout << "B";
//             }
//             cout << endl;
//         }
//     }
//     return 0;
// }


// #include <iostream>
// #include <cstring>
// #include <vector>

// using namespace std;

// const int MAXN = 1005;
// const int MAXM = 200005;

// int n, m;
// int head[MAXN], ver[MAXM << 1], nxt[MAXM << 1], tot;
// int color[MAXM], vis[MAXN];

// void add(int x, int y) {
//     ver[++tot] = y;
//     nxt[tot] = head[x];
//     head[x] = tot;
// }

// bool dfs(int u, int c) {
//     vis[u] = c;
//     for (int i = head[u]; i; i = nxt[i]) {
//         int v = ver[i];
//         if (color[i] == c) return false;
//         if (!color[i]) {
//             color[i] = c;
//             color[i ^ 1] = 3 - c;
//             if (!dfs(v, 3 - c)) return false;
//         } else if (color[i] == 3 - c) {
//             if (!dfs(v, c)) return false;
//         }
//     }
//     return true;
// }

// bool check() {
//     memset(color, 0, sizeof(color));
//     for (int i = 1; i <= n; i++) {
//         if (!vis[i] && !dfs(i, 1)) return false;
//     }
//     return true;
// }

// int main() {
//     int T;
//     cin >> T;
//     while (T--) {
//         tot = 1;
//         memset(head, 0, sizeof(head));
//         memset(vis, 0, sizeof(vis));
//         cin >> n >> m;
//         for (int i = 1; i <= m; i++) {
//             int x, y;
//             cin >> x >> y;
//             add(x, y);
//             add(y, x);
//         }
//         if (!check()) {
//             cout << "No solution." << endl;
//         } else {
//             for (int i = 2; i <= tot; i += 2) {
//                 cout << (color[i] == 1 ? "R" : "B");
//             }
//             cout << endl;
//         }
//     }
//     return 0;
// }


#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Edge {
    int u, v;
};

bool solve(int n, int m, vector<Edge>& edges) {
    vector<int> degree(n + 1, 0);
    for (const auto& edge : edges) {
        degree[edge.u]++;
        degree[edge.v]++;
    }

    string color(m, ' ');
    for (int i = 0; i < m; ++i) {
        if (degree[edges[i].u] >= 2 && degree[edges[i].v] >= 2) {
            color[i] = 'R';
            degree[edges[i].u]--;
            degree[edges[i].v]--;
        } else {
            color[i] = 'B';
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (degree[i] >= 2) {
            return false;
        }
    }

    cout << color << endl;
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<Edge> edges(m);
        for (int i = 0; i < m; ++i) {
            cin >> edges[i].u >> edges[i].v;
        }

        if (!solve(n, m, edges)) {
            cout << "No solution." << endl;
        }
    }

    return 0;
}