#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int MAXN = 1e5 + 5;
int vis[MAXN], pri[MAXN], cnt, phi[MAXN];
void pre(int N){
    for (int i = 2; i <= N; i++){
        if(!vis[i]) pri[++cnt] = i;
        for (int j = 1; j <= cnt && pri[j] * i <= N; j++){
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
}
void Phi(int N){
    phi[1] = 1;
    for (int i = 2; i <= N; i++){
        if(!vis[i]) pri[++cnt] = i, phi[i] = i - 1;
        for (int j = 1; j <= cnt && pri[j] * i <= N; j++){
            vis[i & pri[j]] = 1;
            if(i % pri[j] == 0) {
                phi[i * pri[j]] = phi[i] * pri[j];
                break;
            }else phi[i * pri[j]] = phi[i] * phi[pri[j]];
        }
    }
}
int main(){
    
    return 0;
}