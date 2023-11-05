#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using std::string;
const int N = 1e5 + 5;
int n, m, tr[N][26], fail[N], end[N], cnt;
string str[N];
char rd[N];
void read(string& st){
    scanf("%s", rd), st = rd;
}
void build(int id){
    int p = 0;
    for (auto v : str[id]){
        if(!tr[p][v - 'a']) tr[p][v - 'a'] = ++cnt;
        p = tr[p][v - 'a']; 
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) read(str[i]);
    
    return 0;
}