#include <cstdio>
const int N = 1e3 + 20;
typedef unsigned long long ll;
ll mod = 1e9 + 7;
char list[N];
int plist = 0;
int vis[N][N];
ll ans[N][N];
ll f(int i, int j){
    if(i == j) return 1;
    if(i == j + 1) return 0;
    if(vis[i][j]) return ans[i][j]; vis[i][j] = 1;
    if(list[i] == list[j]){
        return ans[i][j] = (f(i + 1, j) + f(i, j - 1) + 1) % mod;
    }else{
        return ans[i][j] = (f(i + 1, j) - f(i + 1, j - 1) + f(i, j - 1)) % mod;
    }
}
int main(){
    for (char c = getchar(); c > 32; c = getchar()){
        list[++plist] = c;
    }
    printf("%llu ", f(1, plist) % mod);
    return 0;
}