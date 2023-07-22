#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 1e5 + 5;
int t, n, x, y, rec[200][200], ans, cnt, mex[N];
bool check(int x, int y){
    return !(!x || !y || x == y);
}
int sg(int x, int y){
    cnt = (x - 1) * 100 + y;
    for (int i = 1; i < x; i++) if(check(x - i, y)) mex[rec[x - i][y]] = cnt;
    for (int i = 1; i < y; i++) if(check(x, y - i)) mex[rec[x][y - i]] = cnt;
    for (int i = 1; i < std::min(x, y); i++) if(check(x - i, y - i)) mex[rec[x - i][y - i]] = cnt;
    for (int i = 0; ; i++) if(mex[i] != cnt) return i;
}
int main(){
    scanf("%d", &t);
    for (int i = 1; i <= 100; i++){
        for (int j = 1; j <= 100; j++){
            rec[i][j] = sg(i, j);
        }
    }
    for (int i = 1; i <= t; i++){
        ans = 0; bool tmp = 0;
        scanf("%d", &n);
        for (int j = 1; j <= n; j++){
            scanf("%d%d", &x, &y);
            if(!tmp){
                if((!x || !y || x == y)){
                    puts("^o^"); 
                    tmp = 1;
                }else{
                    ans ^= rec[x][y];
                }
            }
        }
        if(tmp) continue;
        puts(ans != 0 ? "^o^" : "T_T");
    }
    return 0;
}