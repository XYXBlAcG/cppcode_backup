#include <cstdio>
#include <algorithm>
#include <map>
const int N = 5e4 + 5;
int n, y[N], r[N], m, stt[N][20];
std::map<int, int> to;
void st(){
    for (int i = 1; i <= 20; i++){
        for (int j = 1; j + (1 << i) - 1 <= n; j++){
            stt[j][i] = std::max(stt[j][i - 1], stt[j + (1 << i)][i - 1]);
        }
    }
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d%d", y + i, r + i);
        to.insert(y[i], r[i]);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++){
        int xx, yy;
        scanf("%d%d", &xx, &yy);

    }
    return 0;
}