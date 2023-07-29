#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 2010;
const int INF = 0x3f3f3f3f;
int a[N][N], dist[N][N];
int n, m;

int bfs() {
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    dist[1][1] = (a[1][1]);

    int cnt[10];
    queue<pair<int, int>> q;
    q.push({1, 1});

    while (!q.empty()) {
        auto t = q.front();
        q.pop();

        int x = t.first, y = t.second;
        if (x == n && y == m) return dist[n][m];

        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < 4; i++) {
            int nx = x + "1201"[i] - '1';
            int ny = y + "0112"[i] - '1';
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                int s = (a[nx][ny]);
                if (dist[x][y] + s < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + s;
                    q.push({nx, ny});
                }
            }
        }
    }

    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    cout << bfs() << endl;

    return 0;
}
