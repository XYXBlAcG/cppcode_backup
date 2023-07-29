#include <cstdio>
#include <algorithm>
// const int N = 0;
typedef unsigned long long llu;
int n;
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
    return 0;
}