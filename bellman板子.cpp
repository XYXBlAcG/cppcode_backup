#include <cstdio>
#include <cstring>
#include <vector>
#define INF 0x3f3f3f3f
const int N = 1e5 + 5;
struct Edge{
    int v, w;
};
std::vector<Edge> st[N];
int dis[N];
int bellman(int n, int s){
    memset(dis, INF, sizeof(dis));
    dis[s] = 0;
    bool flag = 0;
    for (int i = 1; i <= n; i++){
        flag = 0;
        for (int u = 1; u <= n; u++){
            if(dis[u] == INF) continue;
            for (auto v : st[u]){
                if(dis[v.v] > dis[u] + v.w){
                    dis[v.v] = dis[u] + v.w;
                    flag = 1;
                }
            }
        }
        if(!flag) break;
    }
    return flag;
}
int main(){

    return 0;
}