#include <cstdio>
#include <vector>
#include <algorithm>
const int N = 1e6 + 5;
int n;
int vis[N], ans[N], fath[N], answ[N], to[N];
int find(int x){
    return fath[x] == x ? x : fath[x] = find(fath[x]);
}
void merge(int u, int v){
    int U = find(u), V = find(v);
    if(U == V) return;
    fath[U] = fath[V];
}
void seatout(int a){
    printf("# %d : ", a);
    for (int i = 1; i <= n ; i++){
        printf("%d ", ans[i]);
    }printf("\n");
    printf("link: ");
    for (int i = 1; i <= n; i++){
        printf("%d -> %d\n", i, find(fath[i]));
    }
}
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        fath[i] = i;
    }
    for (int i = 1; i <= n; i++){
        int seat;
        scanf("%d",&seat);
        answ[i] = seat;
        int fa = find(seat);
        // merge(seat, (seat == n) ? 1 : seat + 1);
        ans[fa] = !ans[fa] ? i : ans[seat - 1];
        to[ans[fa]] = fa;
        fath[fa] = fa == n ? 1 : fa + 1;
        // seatout(i);
    }
    for (int i = 1; i <= n; i++){
        // printf("%d ", std::abs(to[i] - answ[i]) + 1);
        printf("%d ", (to[i] >= answ[i]) ? to[i] - answ[i] + 1 : n - answ[i] + to[i] + 1);
    }printf("\n");
    for (int i = 1; i <= n; i++){
        printf("%d ", ans[i]);
    }
    return 0;
}

// if(!ans[seat]) {
//     ans[seat] = i;
//     to[i] = seat;
// }else{
//     ans[fa] = i;
//     to[i] = fath[seat];
//     fath[fa] = (seat == n) ? 1 : seat + 1;
// }