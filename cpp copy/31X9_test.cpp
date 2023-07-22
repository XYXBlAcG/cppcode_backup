#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 105;
const int INF = 0x3f3f3f3f;

int n, m;
int d[MAXN][MAXN];
vector<vector<vector<int > > > path;

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] != INF && d[k][j] != INF) {
                    int len = d[i][k] + d[k][j];
                    if (len < d[i][j]) {
                        d[i][j] = len;
                        vector<int> p = path[i][k];
                        p.insert(p.end(), path[k][j].begin() + 1, path[k][j].end());
                        path[i][j].clear();
                        for (int x : p) {
                            path[i][j].push_back(x);
                        }
                    } else if (len == d[i][j]) {
                        vector<int> p = path[i][k];
                        p.insert(p.end(), path[k][j].begin() + 1, path[k][j].end());
                        if (p < path[i][j]) {
                            path[i][j].clear();
                            for (int x : p) {
                                path[i][j].push_back(x);
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    // 初始化邻接矩阵和路径数组
    path.resize(n + 1, vector<vector<int> >(n + 1, {{}}));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = INF;
            path[i][j] = {{i}};
        }
        d[i][i] = 0;
    }
    // 读入边权并更新邻接矩阵
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
        path[u][v] = {{u, v}};
    }
    // Floyd 算法求解最短路径
    floyd();
    // 遍历每一对节点，输出最短路径中经过集合字典序最小的路径
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                cout << i << " -> " << j << ": ";
                for (int k : path[i][j]) {
                    cout << k << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}