#include <cstdio>
#include <algorithm>
#include <cmath>
typedef long long ll;
ll d1, p1, q1, d2, p2, q2;
struct Pos {
    ll x, y;
} a, b;
Pos solve(ll d, ll p, ll q) {
    Pos tmp = { 0, 0 };
    if (d == 0) {
        tmp.x = -(p - q);
        tmp.y = q;
    }
    if (d == 1) {
        tmp.x = q;
        tmp.y = p;
    }
    if (d == 2) {
        tmp.x = p;
        tmp.y = p - q;
    }
    if (d == 3) {
        tmp.x = p - q;
        tmp.y = -q;
    }
    if (d == 4) {
        tmp.x = -q;
        tmp.y = -p;
    }
    if (d == 5) {
        tmp.x = -p;
        tmp.y = -(p - q);
    }
    return tmp;
}
int main() {
    freopen("hive.in", "r", stdin);
    freopen("hive.out", "w", stdout);

    scanf("%lld%lld%lld%lld%lld%lld", &d1, &p1, &q1, &d2, &p2, &q2);
    a = solve(d1, p1, q1);
    b = solve(d2, p2, q2);
    if(a.x < b.x) std::swap(a, b);
    if(a.y < b.y) printf("%lld\n", a.x - b.x + std::abs(a.y - b.y));
    else printf("%lld\n", std::max(a.x - b.x, a.y - b.y));

    fclose(stdin);
    fclose(stdout);
    return 0;
}