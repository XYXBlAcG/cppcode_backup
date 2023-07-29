#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
const int N = 2e5 + 5;
std::vector<int> st[N];
typedef unsigned long long llu;
int n, vis[N], ans;
int app[N];
void dfs(int u){
    vis[u] = 1;
    for(int i = 0; i < st[u].size(); i++){
        int v = st[u][i];
        if(!vis[v]){
            // printf("%c ", (char)v);
            dfs(v);
        }
    }
}
bool cmp(char c1, char c2) {
    return c1 < c2;
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        std::string a;
        std::cin >> a;
        std::sort(&a[0], &a[a.size()], cmp);
        for (int j = 0; j < a.size(); j++){
            if(!app[(int)a[j]]) app[(int)a[j]] = 1;
            if(j && a[j - 1] != a[j]) {
                st[(int)a[j - 1]].push_back((int)a[j]);
                st[(int)a[j]].push_back((int)a[j - 1]);
            }
        }
    }
    for (int i = 33; i < 128; i++){
        if(!vis[i] && app[i]) {
            // printf("%c ", (char)i); 
            dfs(i); ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}