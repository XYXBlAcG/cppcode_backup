#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100; //顶点数最大值
vector<int> G[MAXN]; //邻接表存图
int inDegree[MAXN]; //记录顶点的入度
int n, m; //n为顶点数，m为边数

vector<int> topoSort(){
    vector<int> ans; //存放拓扑序列
    for(int i = 1; i <= n; i++){
        if(inDegree[i] == 0){ //找到入度为0的顶点
            ans.push_back(i); //将其加入拓扑序列
        }
    }
    for(int i = 0; i < ans.size(); i++){ //遍历拓扑序列中的每个顶点
        int u = ans[i];
        for(int j = 0; j < G[u].size(); j++){ //遍历与该顶点相邻的所有顶点
            int v = G[u][j];
            inDegree[v]--; //将与之相邻的顶点的入度减1
            if(inDegree[v] == 0){ //如果入度为0，则将其加入拓扑序列
                ans.push_back(v);
            }
        }
    }
    return ans;
}

void dfs(int u, vector<int>& ans, bool vis[], bool flag[]){
    vis[u] = true; //标记当前顶点已经被访问过
    flag[u] = true; //标记当前顶点在这个dfs搜索中被访问过
    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(flag[v]){ //如果出现了环，则将环上的顶点加入答案中并返回
            ans.push_back(v);
            return;
        }
        if(!vis[v]){ //如果相邻的顶点未被访问过，则进行递归搜索
            dfs(v, ans, vis, flag);
        }
    }
    flag[u] = false; //重置flag数组，回溯时取消标记
}

vector<int> topoSort_dfs(){
    vector<int> ans;
    bool vis[MAXN] = {false}; //初始化所有顶点均未被访问过
    bool flag[MAXN] = {false}; //初始化所有顶点均未被访问过（在当前dfs搜索中）
    for(int i = 1; i <= n; i++){
        if(!vis[i] && inDegree[i] == 0){ //从未被访问过并且入度为0的顶点出发进行dfs搜索
            dfs(i, ans, vis, flag);
            if(!ans.empty()){ //如果存在环，则直接返回答案
                return ans;
            }
        }
    }
    reverse(ans.begin(), ans.end()); //由于是逆序加入拓扑序列，需要将其翻转为正序
    return ans;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int bo, u, v;
        cin >> bo >> u >> v;
        G[u].push_back(v); //建立有向边
        if(bo){ G[v].push_back(u); inDegree[u]++;}
        inDegree[v]++; //计算每个顶点的入度
    }
    vector<int> ans = topoSort_dfs();
    if(ans.empty()){
        cout << "No cycle!" << endl;
    }
    else{
        cout << "Cycle detected: ";
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
