#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
const int N = 1e6 + 5;
std::string str;
std::vector<std::string> st;
char s[N];
int n, op, cnt, vis[N];
struct Node{
    int son[26];
}node[N];
void add(std::string a){
    int cur = 0;
    for (int i = 0; i < (int)a.size(); i++){
        int tmp = a[i] - 'a';
        if(!node[cur].son[tmp]) node[cur].son[tmp] = ++cnt; 
        vis[cur]++;
        cur = node[cur].son[tmp];
    }
    vis[cur]++;
}
int find(std::string a){
    int cur = 0;
    for (int i = 0; i < (int)a.size(); i++){
        int tmp = a[i] - 'a';
        if(!node[cur].son[tmp]) return 0;
        cur = node[cur].son[tmp];
    }
    return vis[cur];
}
signed main(){
    scanf("%d",&n), getchar();
    for (int i = 1; i <= n; i++){
        char c = getchar();
        int j;
        for( j = 0; c != '\n';c = getchar()){
            s[j++] = c;
        }
        s[j] = '\0';
        str = s;
        st.push_back(str);
        add(str);
    }
    // for (int i = 0; i < n; i++){
    //     printf("%d:%s\n", i,st[i].c_str());
    // }
    for (int i = 0; i < n; i++){
        printf("%d\n", find(st[i]) - 1);
    }
    return 0;
}