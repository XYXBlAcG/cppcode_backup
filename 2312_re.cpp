#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define de(x) std::cout << #x << " = " << x << std::endl
const int N = 1005;
int n, m, list[N][2 * N], i, j, tmp[N];
struct Node{
    int x, y;
};
std::vector<int> res[N];
Node find(int num){
    for (int i = 1; i <= n; i++){
        for (int j = 1; list[i][j]; j++){
            if(list[i][j] == num) return (Node){i, j};
        }
    }
    return (Node){0, 0};
}

int main(){
    scanf("%d%d", &n, &m);
    for (int o = 1; o <= n; o++) list[o][1] = o;
    for (int o = 1; o <= m; o++){
        scanf("%d%d", &i, &j);
        Node pj = find(j);
        // de(pj.x), de(pj.y);
        list[pj.x][pj.y] = 0;
        for (int p = pj.y; list[pj.x][p + 1]; p++){
            list[pj.x][p] = list[pj.x][p + 1];
            list[pj.x][p + 1] = 0;
        }
        Node pi = find(i);
        memset(tmp, 0, sizeof(tmp));
        for (int p = pi.y + 1; list[pi.x][p]; p++){
            tmp[p + 1] = list[pi.x][p];
        }
        for (int p = pi.y + 1; list[pi.x][p]; p++){
            list[pi.x][p + 1] = tmp[p + 1];
        }
        list[pi.x][pi.y + 1] = j;
    }
    int ans = 0;
    for (int o = 1; o <= n; o++){
        if(list[o][1]) ans++;
    }
    printf("%d\n", ans);
    int ccnt = 0;
    for (int o = 1; o <= n; o++){
        if(!list[o][1]) continue;
        ccnt++;
        for (int k = 1; list[o][k]; k++){
            res[ccnt].push_back(list[o][k]);
            // printf("%d ", list[o][k]);
        }
        // putchar('\n');
    }
    std::sort(res + 1, res + 1 + ccnt);
    for (int o = 1; o <= ccnt; o++){
        for (auto v : res[o]){
            printf("%d ", v);
        }putchar('\n');
    }
    return 0;
}