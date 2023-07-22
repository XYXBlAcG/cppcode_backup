#include <cstdio>
const int N = 1e6 + 5;
int n, pre[N], mid[N], nxt[N], midx[N], pn;
void cal(int l, int l_, int r_){
    int m = midx[pre[l]];
    if(m > l_) cal(l + 1, l_, m - 1);
    if(m < r_) cal(l - l_ + m + 1, m + 1, r_);
    nxt[++pn] = pre[l];
}
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%d",&pre[i]);
    for (int i = 1; i <= n; i++){
        scanf("%d",&mid[i]);
        midx[mid[i]] = i;
    }
    cal(1, 1, n);
    for (int i = 1; i <= n; i++) printf("%d ", nxt[i]);
    return 0;
}