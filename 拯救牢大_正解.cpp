#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 0x3f3f3f3f
const int N = 2e3 + 5;
int n, k, ld = INF, lu = INF, rd = -INF, ru = -INF, ppos; char ans[N][N];
struct Pos{
    int x, y, dis;
}pos[N * N];
bool cmp(Pos a, Pos b){return a.dis > b.dis;}
bool chk(Pos a){return a.x + a.y + k < ru || a.x - a.y + k < rd || a.y + a.x - k > lu || a.x - a.y - k > ld;}
struct FileIO{
    FileIO(){
        #ifdef ONLINE_JUDGE
            freopen("chopper.in", "r", stdin);
            freopen("chopper.out", "w", stdout);
        #else
        #endif
    }
    ~FileIO(){
        fclose(stdin);
        fclose(stdout);
    }
}fio;
int main(){
    scanf("%d%d", &n, &k);
    for (int i = 1, val; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            scanf("%d", &val), pos[++ppos] = {i, j, val};
    std::sort(pos + 1, pos + 1 + ppos, cmp);
    for (int i = 1; i <= ppos; i++){
        bool ca(!chk(pos[i]));
        if(ca){
            ru = std::max(ru, pos[i].x + pos[i].y);
            rd = std::max(rd, pos[i].x - pos[i].y);
            lu = std::min(lu, pos[i].x + pos[i].y);
            ld = std::min(ld, pos[i].x - pos[i].y);
            ans[pos[i].x][pos[i].y] = 'K';
        }else{
            ans[pos[i].x][pos[i].y] = 'B';
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            printf("%c%c", ans[i][j], " \n"[j == n]);
        }
    }
    return 0;
}