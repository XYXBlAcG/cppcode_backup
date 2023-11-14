#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
const int N = 205;
int n, res, vis[N * N], dis[N * N];
struct Pos {int x, y;};
int get(Pos a) { return (a.x - 1) * n + a.y; }
Pos get(int x) {
    int mo = x % n;
    if (mo == 0) mo = n;
    return { (x - mo) / n + 1, mo };
}
std::vector<Pos> p;
std::queue<int> q;
bool chklf(Pos a) { return a.x >= 1 && a.x <= n && a.y >= 1 && a.y <= n; }
int solve(int x){
    dis[x]--, q.push(x), vis[x] = 0;
    while(q.size()){
        auto u = get(q.front()); q.pop();
        for (int i = 0; i < 4; i++){
            int tx = u.x + "1102"[i] - '1', ty = u.y + "0211"[i] - '1', v = get({tx, ty});
            if(!chklf({tx, ty})) continue;
            if(dis[v] > dis[get(u)] + vis[v]) dis[v] = dis[get(u)] + vis[v], q.push(v);
        }
    }
    return dis[x];
}
int main() {
    #ifdef ONLINE_JUDGE
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[get({i, j})] = std::min({i, j, n - i + 1, n - j + 1}), vis[get({i, j})] = 1;
    for (int i = 1, v; i <= n * n; i++)
        scanf("%d", &v), res += solve(v);
    printf("%d\n", res);
    return 0;
}