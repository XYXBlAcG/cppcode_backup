#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
const int N = 3e5 + 5;
int n, m;
struct Node{
    int u, v;
};
int edge[N * 2], pedge;
std::vector<int> st[N], st_2[N]; Node ans[N]; int pans;
int in[N], q[N * 2], vis[N]; 
void output(){
    for (int i = 1; i <= m; i++){
        printf("%d %d\n", ans[i].u, ans[i].v);
    }
}
void TopoSort() {
    int front = 1, rear = 0;
    for (int i = 1; i <= n; i++)
        if (!in[i])
            q[++rear] = i;
        while (front <= rear) {
            int x = q[front];
            ++front;
            for (auto y : st[x]){
                if (--in[y] == 0){
                    q[++rear] = y;
                }
            }
            for (auto y : st_2[x]){
                if(!vis[y]){
                    vis[y] = 1;
                    ans[y] = ((Node){x, edge[y] - x});
                }
            }
        }
    if (rear == n){
        printf("YES\n");
        output();
        return;
    }else{
        printf("NO\n");
        return;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    int cnt = 0;
    for (int i = 1; i <= m; i++){
        int bo, u, v;
        scanf("%d%d%d",&bo,&u,&v);
        if(bo){
            st[u].push_back(v);
            ans[i] = (Node){u, v};
            in[v]++;
        }else{
            // st_2[u].push_back(v);
            // st_2[v].push_back(u);
            st_2[u].push_back(i);
            st_2[v].push_back(i);
            edge[i] = u + v;
        }
        
    }
    TopoSort();
    return 0;
}