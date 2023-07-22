#include <cstdio>
#include <algorithm>
#include <cmath>
#define EPS 1e-6
const int N = 1e4 + 5;
int n, k, cnt, fath[N], jihe;
struct Node{
    int x, y, idx;
}pos[N];
struct Dis{
    int id1, id2; double val;
}dis[N * N];
bool cmp(Dis a, Dis b){
    return a.val < b.val - EPS;
}
int power(int num){
    return num * num;
}
int find(int x){
    return fath[x] != x ? fath[x] = find(fath[x]) : x;
}
void merge(int x, int y){
    int a = find(x), b = find(y);
    if(a == b) return;
    fath[a] = fath[b];
    jihe--;
}
int main(){
    scanf("%d%d",&n,&k); jihe = n;
    for (int i = 1; i <= n; i++){
        fath[i] = i;
    }
    for (int i = 1; i <= n; i++){
        int x, y;
        scanf("%d%d",&x,&y);
        pos[i] = (Node){x, y, i};
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(i == j) continue;
            int x1 = pos[i].x, y1 = pos[i].y, x2 = pos[j].x, y2 = pos[j].y;
            dis[++cnt] = (Dis){pos[i].idx, pos[j].idx, (double)sqrt((double)power((x1 - x2)) + (double)power((y1 - y2)))};
        }
    }
    std::sort(dis + 1, dis + 1 + cnt, cmp);
    for (int i = 1; i <= cnt; i++){
        if(jihe > k){
            merge(dis[i].id1, dis[i].id2);
        }else{
            if(find(dis[i].id1) != find(dis[i].id2)){
                printf("%.2lf\n", dis[i].val);
                return 0;
            }
        }
    }
    return 0;
}