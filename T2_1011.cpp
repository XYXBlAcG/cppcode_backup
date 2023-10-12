#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 0x3f3f3f3f
const int N = 1e7 + 5;
int n, k, a[N], b[N], s1[N], r1, s2[N], r2, l = 1, l1, l2, ans = INF;
template<typename T>
void read(T& x) {
    T w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    x *= w;
}
template<typename T>
void write(T x) {
    T sta[40];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48);
    putchar('\n');
}
int main(){
    freopen("biloc.in", "r", stdin);
    freopen("biloc.out", "w", stdout);
    read(n), read(k);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i++) read(b[i]);
    for (int i = 1; i <= n; i++){
        while(l1 < r1 && a[s1[r1 - 1]] >= a[i]) --r1;
        s1[r1++] = i;
        while(l2 < r2 && b[s2[r2 - 1]] <= b[i]) --r2;
        s2[r2++] = i;
        while(a[s1[l1]] + k <= b[s2[l2]] && l <= i){
            ans = std::min(ans, i - l + 1), l++;
            while(l1 < r1 && s1[l1] < l) l1++;
            while(l2 < r2 && s2[l2] < l) l2++;
        }
    }
    if(ans == INF) puts("So Sad!"); else write(ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}