#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
const int N = 305, M = 9e4 + 5;
struct Node{
    int v, w;
}dui[N];
std::vector<int> w[M]; std::vector<Node> st[N];
int r, c, n, m, map[N][N], dis[N], pdui;
bool cmp(Node a, Node b){
    return a.w < b.w;
}
inline void push(Node x){
    dui[++pdui] = x;
    std::push_heap(dui + 1, dui + 1 + pdui, cmp);
}
inline int pop(){
    int ans = dui[1].v; std::pop_heap(dui + 1, dui + 1 + pdui--, cmp);
    return ans;
}
void dj(int s, int id){
    if(id == 1) memset(dis, INF, sizeof(dis)), dis[s] = 0;
    push((Node){s, dis[s]});
    while(pdui){
        int u = pop();
        for (auto ed : st[u]){
            int v = ed.v, w = ed.w;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                push((Node){v, dis[v]});
            }
        }
    }
}
int main(){
    scanf("%d%d%d%d", &r, &c, &n, &m);
    for (int i = 1; i <= r; i++){
        std::string a;
        std::cin >> a;
        for (int j = 0; j < a.size(); j++){
            map[i][j + 1] = a[j];
        }
    }
    for (int i = 1; i <= n; i++){
        int x, y;
        scanf("%d%d", &x, &y);
    }
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            int ww; scanf("%d", &ww);
            w[i].push_back(ww);
        }
    }

    return 0;
}