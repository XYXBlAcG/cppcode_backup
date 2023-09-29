#include <cstdio>
typedef long long ll;
const int N = 15;
int n, a[N], b[N], t[N]; bool vis[N][1 << N]; ll rec[N][1 << N];
void pre(){
    t[0] = 1;
    for (int i = 1; i < N; i++)
        t[i] = t[i - 1] * 3;
    
}
ll f(int i, unsigned S){
    if(i > n && !S) return 0;
    if(vis[i][S]) return rec[i][S]; vis[i][S] = 1;
    
}
int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    return 0;
}