#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using std::string;
const int N = 2e5 + 5, M = 2e6 + 5;
int n, tr[N][26], fail[N], ed[N], cnt;
string str[N], s;
char rd[M];
void build(int x){
    int p = 0;
    for (auto v : str[x]){
        if(!tr[p][v - 'a']) tr[p][v - 'a'] = ++cnt;
        p = tr[p][v - 'a'];
    }
    ed[p]++;
}
std::queue<int> que;
void get_fail(){
    for (int i = 0; i < 26; i++) if(tr[0][i]) que.push(tr[0][i]);
    while(que.size()){
        int u = que.front(); que.pop();
        for (int i = 0; i < 26; i++){
            if(tr[u][i]) fail[tr[u][i]] = tr[fail[u]][i], que.push(tr[u][i]);
            else tr[u][i] = tr[fail[u]][i];
        }
    }
}
void query(string st){
    int p = 0;
    for (auto v : st){
        p = tr[p][v - 'a'];
        for (int t = p; t; t = fail[t]){
            
        }
    }
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%s", rd), str[i] = rd, build(i);
    scanf("%s", rd), s = rd;
    return 0;
}