#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
const int N = 3e5 + 5;
int n, m, in[N], vis[N];
std::vector<int> st[N], rec;
std::queue<int> q;
void topo(){
    while(q.size()){
        int u = q.front(); q.pop();
        rec.push_back(u);
        for (auto v : st[u]){
            if(!(--in[v])) q.push(v);
        }
    }
    if((int)rec.size() == n) 
        for (auto v : rec) printf("%d ", v);
    else puts("No solution");
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; i++){
        scanf("%d%d", &u, &v);
        st[u].push_back(v), in[v]++;
    }
    for (int i = 1; i <= n; i++){
        if(!in[i]) q.push(i);
    }
    topo();
    return 0;
}