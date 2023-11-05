#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#define yes "TAK"
#define no "NIE"
using std::string;
const int N = 3e4 + 4;
int n, tr[N][2], cnt, fail[N], vis[N], end[N];
string str[N];
char rd[N];
void read(string& str){
    scanf("%s", rd); str = rd;
}
void build(string str){
    int p = 0;
    for (auto v : str){
        if(!tr[p][v - '0']) tr[p][v - '0'] = ++cnt;
        p = tr[p][v - '0'];
    }
    end[p] = 1;
}
std::queue<int> que;
void get_fail(){
    for (int i = 0; i < 2; i++) if(tr[0][i]) que.push(tr[0][i]);
    while(que.size()){
        int u = que.front(); que.pop();
        for (int i = 0; i < 2; i++){
            if(tr[u][i]) {
                fail[tr[u][i]] = tr[fail[u]][i], que.push(tr[u][i]);
                if(end[tr[fail[u]][i]]) end[tr[u][i]] = 1;
            }else tr[u][i] = tr[fail[u]][i];
        }
    }
}
bool dfs(int u){
    if(vis[u] == 1) return 1;
    if(vis[u] == -1) return 0;
    vis[u] = 1;
    for (int i = 0; i < 2; i++) if(!end[tr[u][i]] && dfs(tr[u][i])) return 1;
    vis[u] = -1;
    return 0;
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) read(str[i]), build(str[i]);
    get_fail();
    puts(dfs(0) ? yes : no);
    return 0;
}