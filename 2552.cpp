#include <cstdio>
const int N = 105;
typedef long long ll;
ll n, m; ll mod = 1000000007;
ll pos[N][N];
bool sign[1000];
ll f[400][N][N];
int main(){
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            scanf("%lld", &pos[i][j]);
        }
    }
    int lent = 0;
    ll a = m;
    while(a){
        if(!(a & 1)) {a >>= 1; sign[++lent] = 1;}
        else {a--; sign[++lent] = 0;}
    }
    int roll = 0;
    //1
    for (int i = 1; i <= n ;i++){
        for (int j = 1; j <= n; j++){
            f[1][i][j] = pos[i][j];
        }
    }
    // int h = lent;
    while(roll < lent){
        roll++;
        if(sign[lent - roll + 1]){
        // if(sign[roll - 1]){
            for (int i = 1; i <= n; i++){
                
                    for (int k = 1; k <= n; k++){
                        for (int j = 1; j <= n; j++){
                        f[roll][i][j] += f[roll - 1][i][k] * f[roll - 1][k][j];
                        f[roll][i][j] %= mod;
                        // printf("%ll ", f[roll][i][j]);
                    }
                    // printf("\n");
                }
            }
        }else{
            for (int i = 1; i <= n; i++){
                
                    for (int k = 1; k <= n; k++){
                        for (int j = 1; j <= n; j++){
                        f[roll][i][j] += f[roll - 1][i][k] * pos[k][j];
                        f[roll][i][j] %= mod;
                        // printf("%ll ", f[roll][i][j]);
                    }
                    // printf("\n");
                }
            }
        }
    }
    ll res = 0;  
    for (int j = 1; j <= n; j++){
        res += f[roll][1][j];
    }
    printf("%lld\n", res % mod);
    return 0;
}
