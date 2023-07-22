#include <cstdio>
#include <algorithm>
using std::sort;
int n;
struct Re {
    int r[15], p;

    int pop() { return r[p--]; }

    void push(int a) { r[++p] = a; }

} re[5000000];
Re in;
Re out;
Re str;
int tmp = 0;
void dfs() {
    // printf("#%d %d %d\n",in.p,out.p,str.p);
    if (out.p == n) {
        // printf("%d \n",tmp);
        re[++tmp] = out;
        return;
    }

    if (in.p > 0) {
        str.push(in.pop());
        dfs();
        in.push(str.pop());
    }

    if (str.p > 0) {
        out.push(str.pop());
        dfs();
        str.push(out.pop());
    }
}
bool operator<(const Re& a, const Re& c) {
    for (int i = 1; i <= n; i++) {
        if (a.r[i] != c.r[i])
            return a.r[i] < c.r[i];
    }
    return 0;
}
int main() {
    scanf("%d", &n);
    for (int i = n; i >= 1; i--) {
        scanf("%d", &in.r[i]);
    }
    in.p = n;
    dfs();
    std::sort(re + 1, re + 1 + tmp);
    for (int i = 1; i <= tmp; i++) {
        if ((re[i - 1] < re[i])) {
            for (int j = 1; j <= n; j++) {
                printf("%d ", re[i].r[j]);
            }
            printf("\n");
        }
    }

    return 0;
}