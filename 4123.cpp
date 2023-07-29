#include <cstdio>
#include <algorithm>
const int N = 1e6 + 5;
int n;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        int a0 = 0, a1 = 0, b0 = 0, b1 = 0, ans = 0;
        scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
        for (int j = 1; j * j <= b1; j++){
            if(b1 % j == 0){
                if(j % a1 == 0 && gcd(j / a1, a0 / a1) == 1 && gcd(b1 / j, b1 / b0) == 1) ans++;
                int a = b1 / j;
                if(j != a && a % a1 == 0 && b1 % a == 0 && gcd(a / a1, a0 / a1) == 1 && gcd(b1 / a, b1 / b0) == 1) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
