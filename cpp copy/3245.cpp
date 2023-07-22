#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
const int N = 505;
std::vector<int> st[N], st2[N];
std::string str1, str2, ans1, ans2;
int stack[N], ps;
int pre[N], pp, mid[N], pm;
std::string dfs(int x){
    std::string ans = "{", tmp[N];
    if(!st[x].size()) return "{}";
    for (int i = 0; i < st[x].size(); i++){
        tmp[i] = dfs(st[x][i]);
    }
    std::sort(tmp, tmp + st[x].size());
    for (int i = 0; i < st[x].size(); i++){
        if(i){
            if(tmp[i - 1] != tmp[i]){
                ans += tmp[i];
            }
        }else ans += tmp[i];
    }
    ans += '}';
    return ans;
}
std::string dfs2(int x){
    std::string ans = "{", tmp2[N];
    if(!st2[x].size()) return "{}";
    for (int i = 0; i < st2[x].size(); i++){
        tmp2[i] = dfs2(st2[x][i]);
    }
    std::sort(tmp2, tmp2 + st2[x].size());
    for (int i = 0; i < st2[x].size(); i++){
        if(i){
            if(tmp2[i - 1] != tmp2[i]){
                ans += tmp2[i];
            }
        }else ans += tmp2[i];
    }
    ans += '}';
    return ans;
}
int main(){
    std::cin >> str1 >> str2;
    for (int i = 0; i < str1.size(); i++){
        if(str1[i] == '{'){
            stack[++ps] = i;
            if(stack[ps - 1] != i) st[stack[ps - 1]].push_back(i);
        }else if(str1[i] == '}'){
            stack[ps--] = 0;
        }
    }
    ps = 0;
    for (int i = 0; i < str2.size(); i++){
        if(str2[i] == '{'){
            stack[++ps] = i;
            if(stack[ps - 1] != i) st2[stack[ps - 1]].push_back(i);
        }else if(str2[i] == '}'){
            stack[ps--] = 0;
        }
    }
    ans1 = dfs(0);
    ans2 = dfs2(0);
    printf("%d\n", ans1 == ans2);
    

    return 0;
}