#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 105;
int n, m, a[N], b[N], mat[N][N], t;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i), t ^= a[i];
    for (int i = 1; i <= m; i++) scanf("%d", b + i), t ^= b[i];
    if(t) return puts("NO"), 0;
    puts("YES");
    for (int i = 1; i < n; i++) mat[i][m] ^= a[i];
    for (int i = 1; i < m; i++) mat[n][i] ^= b[i];
    int al = b[m];
    for (int i = 1; i < n; i++) al ^= a[i];
    mat[n][m] = al;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            printf("%d ", mat[i][j]);
        }
        putchar('\n');
    }
    return 0;
}