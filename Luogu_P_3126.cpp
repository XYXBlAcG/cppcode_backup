#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
using std::string;
const int N = 500 + 5;
int n, rec[N][N];
bool vis[N][N];
char rd[N];
void read(string& x){
    scanf("%s", rd), x = rd;
}
string str[N];
bool chk(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= n;
}
std::vector<char> st;
int dp(int x, int y){
    for (int i = 0; i < 2; i++){
        int tx = x + "12"[i] - '1', ty = y + "21"[i] - '1';
        if(chk(tx, ty)) {
            dp(tx, ty);
        }
    }
}
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) read(str[i]);
    
    return 0;
}