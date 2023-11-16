#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define INF 0x3f3f3f3f
const int N = 305;
int n, m, a[N], b[N], res, ans;
struct Node{
    int l, r;
}seg[N];
std::vector<int> s[N];
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= m; i++) scanf("%d%d", &seg[i].l, &seg[i].r);
    for (int i = 1; i <= n; i++){
        memcpy(b, a, sizeof(a));
        int cnt = 0;
        for (int j = 1; j <= m; j++){
            if(!(seg[j].l <= i && i <= seg[j].r)){
                s[i].push_back(j);
                for (int k = seg[j].l; k <= seg[j].r; k++){
                    b[k]--;
                }
                cnt++;
            }
        }
        int mx = -INF, mn = INF;
        for(int j = 1; j <= n; j++){
            if(mx < b[j]) mx = b[j];
            if(mn > b[j]) mn = b[j];
        }
        if(mx == b[i] && mx - mn > res){
            res = mx - mn;
            ans = i;
        }
    }
    printf("%d\n", res);
    printf("%d\n", (int)s[ans].size());
    for (auto v : s[ans]){
        printf("%d ", v);
    }
    putchar('\n');
    return 0;
}
