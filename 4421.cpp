#include <cstdio>
#define ls(u) u << 1
const int N = 5e4 + 5;
int n, y[N], r[N], m;
struct Tree{
    int sum;
};
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d%d", y + i, r + i);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++){
        int xx, yy;
        scanf("%d%d", &xx, &yy);

    }
    return 0;
}