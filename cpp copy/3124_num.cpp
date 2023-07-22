#include <cstdio>
#include <algorithm>
// const int N = 0;
typedef unsigned long long llu;
int n, a[1000006];
inline int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
  }
  return x * w;
}
int main(){
    n = read();
    for (int i = 1; i <= n; i++){
        a[i] = i;
        a[i + n] = i;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 6; j++){
            printf("%d ",a[i + j]);
        }printf("\n");
    }
    return 0;
}