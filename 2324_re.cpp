#include <cstdio>
#include <algorithm>
const int N = 500005;
int n, ord[N];
struct Node{
    int l, r;
}num[N], ans[N];
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", ord + i);
        num[i] = (Node){i - 1, i + 1};
    }num[n].r = 0;
    std::reverse(ord + 1, ord + 1 + n);
    for (int i = 1; i <= n; i++){
        int tmp = ord[i];
        ans[i] = num[tmp];
        num[num[tmp].r].l = num[tmp].l;
        num[num[tmp].l].r = num[tmp].r;
    }
    std::reverse(ans + 1, ans + 1 + n);
    for (int i = 1; i <= n; i++){
        printf("%d %d\n", ans[i].l, ans[i].r);
    }
    return 0;
}