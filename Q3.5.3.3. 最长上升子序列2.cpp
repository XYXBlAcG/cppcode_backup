#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 1e5 + 5;
int n, a[N], l[N], p;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++){
        if(a[i] > l[p]) l[++p] = a[i];
        else l[std::lower_bound(l + 1, l + 1 + p, a[i]) - l] = a[i];
    }
    printf("%d\n", p);
    return 0;
}