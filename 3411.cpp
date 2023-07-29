#include <cstdio>
#include <string>
const int N = 1e6 + 5;
int n, op, cnt, vis[N];
struct Node{
    int son[26];
}node[N];
void add(std::string a){
    int cur = 0;
    for (int i = 0; i < a.size(); i++){
        int tmp = a[i] - 'a';
        if(!node[cur].son[tmp]) node[cur].son[tmp] = ++cnt;
        cur = node[cur].son[tmp];
    }
    vis[cur] = 1;
}
int find(std::string a){
    int cur = 0;
    for (int i = 0; i < a.size(); i++){
        int tmp = a[i] - 'a';
        if(!node[cur].son[tmp]) return 0;
        cur = node[cur].son[tmp];
    }
    return vis[cur];
}
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        scanf("%d",&op); 
        if(op == 1){
            std::string tmp = "";
            for (char c = getchar(); c != '\n'; c = getchar()){
                if(c >= 33 && c <= 126) tmp += c;
            } add(tmp);
        }else{
            std::string tmp = "";
            for (char c = getchar(); c != '\n'; c = getchar()){
                if(c >= 33 && c <= 126) tmp += c;
            } printf("%d\n", find(tmp));
        }
    }
    return 0;
}