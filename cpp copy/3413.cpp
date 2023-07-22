#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
const int N = 1e6 + 5;
std::string str, S, S2; char s[N];
std::vector<std::string> st;
int n, cnt, vis[2][N];
struct Node{
    int son[26];
}node[2][N];
void add(std::string a, int t){
    int cur = 0;
    for (int i = 0; i < (int)a.size(); i++){
        int tmp = a[i] - 'a';
        if(!node[t][cur].son[tmp]) node[t][cur].son[tmp] = ++cnt; 
        cur = node[t][cur].son[tmp];
    }
    vis[t][cur]++;
}
bool find(std::string a){
    std::string ss = a, tp1 = "", tp2 = ss;
    reverse(ss.begin(), ss.end()); /*tp2 = ss;*/
    int cur1 = 0, cur2 = a.size();
    // if(((vis[0][cur1] && vis[1][cur2]) || (vis[0][cur2] && vis[1][cur1])) && (tp1 + tp2 == S || tp1 + tp2 == S2)) return 1;
    for (int i = 0; i < (int)a.size(); i++){
        int tmp1 = a[i] - 'a', tmp2 = ss[i] - 'a';
        if(!node[0][cur1].son[tmp1] || !node[1][cur2].son[tmp2]) return 0;
        tp1 += a[i], tp2.pop_back();
        printf("%s %s %s %d %d %d %d\n", (tp1 + tp2).c_str(), S.c_str(), S2.c_str(), vis[0][cur1], vis[1][cur2], vis[0][cur2], vis[1][cur1]);
        if(((vis[0][cur1] && vis[1][cur2]) || (vis[0][cur2] && vis[1][cur1])) && (tp1 + tp2 == S || tp1 + tp2 == S2)) return 1;
        cur1 = node[0][cur1].son[tmp1], cur2 = node[1][cur2].son[tmp2];
    }
    return 0;
}
int main(){
    scanf("%d",&n), getchar();
    for (int i = 1, j; i <= n + 1; i++){
        char c = getchar();
        for(j = 0; c != '\n'; c = getchar()) s[j++] = c;
        s[j] = '\0', str = s;
        if(i == n + 1) S = str;
        else st.push_back(str);
        add(str, 0), reverse(str.begin(), str.end()), add(str, 1);
    }
    S2 = S;
    reverse(S2.begin(), S2.end());
    printf("%s\n", find(S) ? "ture" : "fu");
    return 0;
}