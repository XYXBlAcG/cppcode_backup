#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using std::string;
const int N = 1e6 + 5, M = 155;
int n, tr[N][26], cnt, fail[N], ed[N];
string str[M], t;
char rd[N];
struct Ans{
    int val, idx;
}res[M];
void build(int i){
    int p = 0;
    for (auto v : str[i]){
        if(!tr[p][v - 'a']) tr[p][v - 'a'] = ++cnt;
        p = tr[p][v - 'a'];
    }
    ed[p] = i;
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
        for (int t = p; t; t = fail[t])
            res[ed[t]].val++;
    }
}
void clean(){
    memset(tr, 0, sizeof(tr));
    que = {};
    memset(fail, 0, sizeof(fail));
    memset(ed, 0, sizeof(ed));
    memset(res, 0, sizeof(res));
}
bool cmp(Ans a, Ans b){return (a.val ^ b.val) ? a.val > b.val : a.idx < b.idx;}
int main(){
    while(1){
        scanf("%d", &n);
        if(n == 0) break;
        for (int i = 1; i <= n; i++) scanf("%s", rd), str[i] = rd, build(i);
        scanf("%s", rd), t = rd;
        get_fail();
        query(t);
        for (int i = 1; i <= n; i++) res[i].idx = i;
        std::sort(res + 1, res + 1 + n, cmp);
        printf("%d\n", res[1].val);
        printf("%s\n", str[res[1].idx].c_str());
        for (int i = 2; i <= n; i++){
            if(res[i].val ^ res[i - 1].val) break;
            printf("%s\n", str[res[i].idx].c_str());
        }
        clean();
    }
    return 0;
}