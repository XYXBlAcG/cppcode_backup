#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define ls(u) u << 1
#define rs(u) u << 1 | 1
const int N = 4e5 + 5;
int n, w[N], ans[N], pos[N], mx, num, p[N];
void dp(int u){
    p[u] = std::max(p[ls(u)], 0) + std::max(0, p[rs(u)]);
    p[u] += (w[u] >= num) ? 1 : -1;
    mx = std::max(mx, p[u]);
}
struct FileIO{
    FileIO(){
        freopen("mid.in", "r", stdin);
        freopen("mid.out", "w", stdout);
    }
    ~FileIO(){
        fclose(stdin);
        fclose(stdout);
    }
}FileIO;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", w + i), pos[w[i]] = i;
    for (num = n; num; num--){
        for (int j = pos[num]; j; j >>= 1) dp(j);
        ans[mx - 1] = std::max(ans[mx - 1], num);
    }
    for (int i = n - 1; ~i; i--) ans[i] = std::max(ans[i + 1], ans[i]);
    for (int i = 0; i < n; i++) printf("%d ", ans[i]);
    return 0;
}