#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string.h>
const int N = 1e6 + 5;
char str[N];
int l, s1, m1, ll, ans;
int get(char *a, int op){
    int n = strlen(a), i = 0, j = 1, k = 0;
    while(i < n && j < n){
        while(k < n && a[(i + k) % n] == a[(j + k) % n]) k++;
        if(k == n) {
            if(op == 2) return std::abs(j - i); else break;
        }
        if(!op) a[(i + k) % n] > a[(j + k) % n] ? i += k + 1 : j += k + 1;
        else a[(i + k) % n] < a[(j + k) % n] ? i += k + 1 : j += k + 1;
        if(i == j) j++;
        k = 0;
    }
    if(op == 2) return -1;
    return std::min(i, j);
}
int main(){
    scanf("%s", str), l = strlen(str);
    s1 = get(str, 0), m1 = get(str, 1), ll = get(str, 2);
    // printf("ll = %d\n", ll);
    if(ll == -1) ans = 1;
    else ans = l / ll;
    // ans = l / ll;
    printf("%d %d %d %d\n", s1 + 1, ans, m1 + 1, ans);
    return 0;
}