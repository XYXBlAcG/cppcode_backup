#include <bits/stdc++.h>
#define int long long
using namespace std;
int x[20], y[20], l[20], n, ans;
signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> l[i], l[i] += x[i] + y[i];
    for (int S = 1; S < (1 << n); S++) {
        int sgn = -1, mx = 0, my = 0, ml = 1e9;
        for (int i = 0; i < n; i++)
            if (S & (1 << i))
                sgn = -sgn, mx = max(mx, x[i]), my = max(my, y[i]), ml = min(ml, l[i]);
        if (mx + my > ml)
            continue;
        ans += sgn * (ml - mx - my) * (ml - mx - my);
    }
    cout << ans;
}