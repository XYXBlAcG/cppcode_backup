#include <cstdio>
#include <cmath>
#include <algorithm>
typedef double dd;
int n, x, ans;
int main(){
    freopen("section.in", "r", stdin);
    freopen("section.out", "w", stdout);
    scanf("%d%d", &n, &x);
    for (int a = 2; a <= n; a++){
        if(a == x) continue;
        for (int b = 2; b <= n && a + b <= n + 1; b++){
            if(b == x) continue;
            for (int c = std::max((int)ceil((dd)(a * b - n) / (dd)b), 1); c < a; c++){
                if((a * b - n) % c != 0) continue;
                int d = (a * b - n) / c;
                if(b > d && d > 0) ans++;
            }
        }
    }
    printf("%d\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}