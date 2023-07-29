#include <cstdio>
#include <queue>
#include <cstring>
const int N = 2010;
int num[N][N];
int dist[N][N];
bool vis[N][N];
struct Node {
    int x, y, d;
    bool operator < (const Node& other) const {
        return d > other.d;
    }
};
std::priority_queue<Node> q;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    q.push((Node){1, 1, num[1][1]});
    dist[1][1] = num[1][1];
    while (!q.empty()) {
        Node t = q.top();
        q.pop();
        int x = t.x, y = t.y;
        if (vis[x][y]) continue;
        vis[x][y] = 1;
        if (x == n && y == m) break;
        if (x > 1) {
            int d = dist[x][y] + num[x - 1][y];
            if (d < dist[x - 1][y]) {
                dist[x - 1][y] = d;
                q.push((Node){x - 1, y, d});
            }
        }
        if (x < n) {
            int d = dist[x][y] + num[x + 1][y];
            if (d < dist[x + 1][y]) {
                dist[x + 1][y] = d;
                q.push((Node){x + 1, y, d});
            }
        }
        if (y > 1) {
            int d = dist[x][y] + num[x][y - 1];
            if (d < dist[x][y - 1]) {
                dist[x][y - 1] = d;
                q.push((Node){x, y - 1, d});
            }
        }
        if (y < m) {
            int d = dist[x][y] + num[x][y + 1];
            if (d < dist[x][y + 1]) {
                dist[x][y + 1] = d;
                q.push((Node){x, y + 1, d});
            }
        }
    }
    printf("%d\n", dist[n][m]);
    return 0;
}