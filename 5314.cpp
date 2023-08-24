#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
typedef unsigned long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f, N = 2005;
ll n, P, M, qp[3][N], sum[7][N][N], sum2[7][N][N];
std::string str[7];
void pre(){
    qp[0][0] = qp[1][0] = 1;
    for (int i = 1; i <= N - 5; i++){
        qp[0][i] = qp[0][i - 1] * 7 % 52009;
        qp[1][i] = qp[1][i - 1] * 2 % 9223372036854775807;
    }
    ll fh = INF, th = 0, T = 0;
    P = 52009, M = 7, T = 0;
    for (int i = 1; i <= n; i++){
        th = 0;
        for (int j = 0; j < (int)str[i].size(); j++){
            ll tmp = 0;
            for (int k = j; k < (int)str[i].size(); k++){
                tmp += str[i][j] - 'a' + 1;
                sum[i][j][k] = (th += (tmp) * qp[T][j + 1] % P);
            }
        }
    }
    P = 9223372036854775807, M = 2, T = 1;
    for (int i = 1; i <= n; i++){
        th = 0;
        for (int j = 0; j < (int)str[i].size(); j++){
            ll tmp = 0; th = 0;
            for (int k = j; k < (int)str[i].size(); k++){
                tmp += str[i][j] - 'a' + 1;
                sum2[i][j][k] = (th += (tmp) * qp[T][j + 1] % P);
            }
        }
    }
}
struct NN{
    ll id, h0, h1;
};
struct Node{
    NN a;
    ll nxt;
}L[N];
ll head[N], nL;
void insert(ll h0, ll h1, ll ii){
    L[++nL] = {{ii, h0, h1}, head[h0]};
    head[h0] = nL;
}
ll lisan(int i, int j, int k){
    return i * 2001 * 2001 + j * 2001 + k;
}
NN query(ll h0, ll h1, ll ii){
    for (int i = head[h0]; i; i = L[i].nxt){
        if(L[i].a.h1 == h1){
            return L[i].a;
        }
    }
    return L[nL].a;
}
bool check(int l, int r){

}
int main(){
    pre();
    scanf("%llu", &n);
    for (int i = 1; i <= n; i++){
        std::cin >> str[i];
    }
    if(n == 1){
        printf("%llu\n", (ll)str[1].size());
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < (int)str[1].size(); i++){
        for (int j = i; j < (int)str[1].size(); j++){
            insert(sum[1][i][j], sum2[1][i][j], ++cnt);
        }
    }
    int ans = 0;
    int r = str[2].size();
    for (int i = 2; i <= n; i++){
        for (int l = 0; l < (int)str[i].size(); l++){
            int mid = (l + r) >> 1;
            if(check(l, r)) l = mid + 1;
            else r = mid; 
        }
    }
    
    return 0;
}