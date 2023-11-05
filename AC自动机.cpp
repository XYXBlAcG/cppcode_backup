#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using std::string;
const int N = 1e6 + 5;
int n, tr[N][26], fail[N], ed[N], cnt;
string str[N], t;
char rd[N];
std::queue<int> q;
void build(string st){
    int p = 0;
    for (auto v : st){
        int vv = v - 'a';
        if(!tr[p][vv]) tr[p][vv] = ++cnt;
        p = tr[p][vv];
    }
    ed[p]++;
}
void get_fail(){
    for (int i = 0; i < 26; i++) if(tr[0][i]) q.push(tr[0][i]);
    while(q.size()){
        int u = q.front(); q.pop();
        for (int i = 0; i < 26; i++){
            if(tr[u][i]) fail[tr[u][i]] = tr[fail[u]][i], q.push(tr[u][i]);
            else tr[u][i] = tr[fail[u]][i];
        }
    }
}
int query(string st){
    int p = 0, res = 0;
    for (auto v : st){
        int vv = v - 'a';
        p = tr[p][vv];
        for (int t = p; t && ed[t] != -1; t = fail[t]){
            res += ed[t], ed[t] = -1;
        }
    }
    return res;
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%s", rd), str[i] = rd, build(str[i]);
    scanf("%s", rd), t = rd;
    get_fail();
    printf("%d\n", query(t));
    return 0;
}