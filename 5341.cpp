#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using std::string;
const int N = 1e7 + 5, M = 1e5 + 5;
int n, m, tr[N][5], cnt, fail[N], vis[N];
string str[M], t;
char rd[N];
int get(char a){
    if(a == 'E') return 0;
    if(a == 'S') return 1;
    if(a == 'W') return 2;
    return 3;
}
void build(string& st){
    int p = 0;
    for (auto v : st){
        if(!tr[p][get(v)]) tr[p][get(v)] = ++cnt;
        p = tr[p][get(v)];
    }
}
std::queue<int> que;
void get_fail(){
    for (int i = 0; i < 4; i++) if(tr[0][i]) que.push(tr[0][i]);
    while(!que.empty()){
        int u = que.front(); que.pop();
        for (int i = 0; i < 4; i++) {
            if(tr[u][i]) fail[tr[u][i]] = tr[fail[u]][i], que.push(tr[u][i]);
            else tr[u][i] = tr[fail[u]][i];
        }
    }
    int p = 0;
    for (auto v : t){
        p = tr[p][get(v)];
        for (int tp = p; tp && !vis[tp]; tp = fail[tp]) vis[tp] = 1;
    }
}
int query(string st){
    int p = 0, res = 0;
    for (int i = 0; i < (int)st.size(); i++){
        p = tr[p][get(st[i])];
        if(vis[p]) res = i + 1;
    }
    return res;
}
int main(){
    scanf("%d%d", &n, &m);
    scanf("%s", rd), t = rd;
    for (int i = 1; i <= m; i++) scanf("%s", rd), str[i] = rd, build(str[i]);
    get_fail();
    for (int i = 1; i <= m; i++){
        printf("%d\n", query(str[i]));
    }
    return 0;
}