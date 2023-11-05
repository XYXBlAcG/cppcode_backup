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
int n, tr[N][26], cnt, ed[N], fail[N], num[N];
string str[N];
char rd[N];
void read(string& x){
    scanf("%s", rd), x = rd;
}
void build(int id){
    int p = 0;
    for (auto v : str[id]){
        if(!tr[p][v - 'a']) tr[p][v - 'a'] = ++cnt;
        p = tr[p][v - 'a'];
        num[p]++;
    }
    ed[id] = p;
}
std::queue<int> que;
std::vector<int> st;
void get_fail(){
    for (int i = 0; i < 26; i++) if(tr[0][i]) que.push(tr[0][i]), st.push_back(tr[0][i]);
    while(que.size()){
        int u = que.front(); que.pop();
        for (int i = 0; i < 26; i++){
            if(tr[u][i]) fail[tr[u][i]] = tr[fail[u]][i], que.push(tr[u][i]), st.push_back(tr[u][i]);
            else tr[u][i] = tr[fail[u]][i];
        }
    }
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) read(str[i]), build(i);
    get_fail();
    for (int i = (int)st.size() - 1; ~i; i--)
        num[fail[st[i]]] += num[st[i]];
    for (int i = 1; i <= n; i++) printf("%d\n", num[ed[i]]);
    return 0;
}