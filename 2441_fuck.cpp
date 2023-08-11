#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
priority_queue<int> q;
struct Point {
    int t, c;
    bool operator<(const Point &b) const { return t < b.t; }
} a[2009];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d", &a[i].t);
    for (int i = 1; i <= m; i++) scanf("%d", &a[i].c);
    sort(a + 1, a + m + 1);
    int j = m;
    for (int i = n; i >= 1; i--) {
        while (a[j].t == i) q.push(a[j--].c);
        if (q.size() == 0)
            break;
        printf("ans = %d\n", ans);
        ans += q.top();
        q.pop();
    }
    printf("%d", ans);
    return 0;
}