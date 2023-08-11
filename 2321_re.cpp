#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define de(x) std::cout << #x << " = " << x << std::endl
const int N = 2005;
int n, m, list[N][N], i, j, a, tmp[N], tmp2[N];
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
        scanf("%d%d%d", &i, &j, &a);
        memset(tmp, 0, sizeof(tmp));
        Node pj = find(j);
        // de(pj.x), de(pj.y);
        int cnt = 1;
        for (int p = pj.y; list[pj.x][p] && cnt <= a; p++, cnt++){
            tmp[cnt] = list[pj.x][p];
            list[pj.x][p] = 0;
        }
        for (int p = pj.y + cnt + 1, az = pj.y; list[pj.x][p]; p++, az++){
            list[pj.x][az] = list[pj.x][p];
        }
        Node pi = find(i);
        memset(tmp2, 0, sizeof(tmp2));
        for (int p = pi.y + 1; list[pi.x][p]; p++){
            tmp2[p + cnt] = list[pi.x][p];
        }
        for (int p = pi.y + 1; list[pi.x][p]; p++){
            list[pi.x][p + cnt] = tmp2[p + cnt];
        }
        for (int p = pi.y + 1, ct = 1; p <= pi.y + 1 + cnt; p++, ct++){
            list[pi.x][p] = tmp[ct];
        }
        
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