#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#define fail(u) fail[u]
#define nd(u, v) trie[u].ch[v]
using std::string;
const int N = 1e7 + 5, M = 1e5 + 5;
int n, m, cnt, fail[N], vis[N];
char rd[N];
void read(string& x){
    scanf("%s", rd), x = rd;
}
string mu, str[M];
std::queue<int> que;
struct Trie{
    int ch[26];
}trie[M];
struct Tree{
    void build(int id){
        int p = 0;
        for (auto v : str[id]){
            if(!nd(p, v - 'A')) nd(p, v - 'A') = ++cnt;
            p = nd(p, v - 'A');
        }
    }
    void buildfail(){
        for (int i = 0; i < 26; i++) if(nd(0, i)) que.push(nd(0, i));
        while(que.size()){
            int u = que.front(); que.pop();
            for (int i = 0; i < 26; i++){
                if(nd(u, i)) fail(nd(u, i)) = nd(fail(u), i), que.push(nd(u, i));
                else nd(u, i) = nd(fail(u), i);
            }
        }
        int p = 0;
        for (auto v : mu){
            p = nd(p, v - 'A');
            for(int t = p; t && !vis[t]; t = fail(t)){
                vis[t] = 1;
            }
        }
    }
    int query(int id){
        int p = 0, res = 0;
        for (int i = 0; i < (int)str[id].size(); i++){
            p = nd(p, str[id][i] - 'A');
            if(vis[p]) res = i + 1;
        }
        return res;
    }
}tree;
int main(){
    scanf("%d%d", &n, &m);
    read(mu);
    for (int i = 1; i <= m; i++)
        read(str[i]), tree.build(i);
    tree.buildfail();
    for (int i = 1; i <= m; i++){
        printf("%d\n", tree.query(i));
    }
    return 0;
}