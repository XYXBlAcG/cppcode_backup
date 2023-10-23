#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
const int N = 5e5 + 5;
std::vector<int> st[N];
int n, type[N], ans[N], res, fires;
std::string str;
struct Stack{
    int data[N], pdata;
    void push(int x){
        data[++pdata] = x;
    }
    void pop(){
        pdata--;
    }
    int top(){
        return data[pdata];
    }
    int size(){
        return pdata;
    }
}stack;
void dfs(int u){
    ans[u] = res;
    for (auto v : st[u]){
        int flag = 0;
        if(type[v] && stack.size()) flag = 1, stack.pop(), res++;
        else stack.push(1);
        dfs(v);
        if(flag) stack.push(1), res--;
        else stack.pop();
    }
}
int main(){
    scanf("%d", &n);
    std::cin >> str;
    for (int i = 0; i < (int)str.size(); i++) type[i + 1] = str[i];
    for (int i = 1, fa = 0; i < n; i++){
        scanf("%d", &fa);
        st[fa].push_back(i + 1);
    }
    dfs(1);
    for (int i = 1; i <= n; i++){
        printf("%d ", ans[i]);
        fires ^= i * ans[i];
    }putchar('\n');
    printf("%d\n", fires);
    
    return 0;
}