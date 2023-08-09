#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#define str(x) std::cout << #x << " = " << x << std::endl
#define INF 0x3f3f3f3f
const int N = 105;
using std::string;
string zifu;
char zic[N];
bool vis[N][N];
int rec[N][N];
int leng(int x){
    int cnt = 0;
    if(x == 0) return 1;
    for (; x; cnt++) x /= 10;
    return cnt;
}
bool is(int l, int r, int len){
    for (int i = l; i <= r - len; i++) if(zic[i] != zic[i + len]) return 0;
    return 1;
}
int dp(int l, int r){
    if(l == r) return 1;
    if(vis[l][r]) return rec[l][r];
    vis[l][r] = 1;
    int ans = r - l + 1, len = ans;
    for (int i = l; i < r; i++) ans = std::min(dp(l, i) + dp(i + 1, r), ans);
    for (int i = l; i < r; i++)
        if(!(len % (i - l + 1)) && is(l, r, i - l + 1))
            ans = std::min(ans, dp(l, i) + leng(len / (i - l + 1)) + 2);
    return rec[l][r] = ans;
}
int main(){
    std::cin >> zifu;
    strcpy(zic, zifu.c_str());
    printf("%d\n", dp(0, zifu.size() - 1));
    return 0;
}

// compb = "";
// if(j + (int)compa.size() > r) break;
// for (int oo = j; oo <= std::min(j + (int)compa.size(), r); oo++){
//     compb += zifu[oo];
// }

// for (int i = l; i <= ((l + r + 1) >> 1); i++){
//     // for (int i = l; i <= r; i++){
//         compa += zifu[i];
//         str(compa);
//         for (int j = i + 1, cnt = 2; j <= r; j += compa.size(), cnt++){
//             // int pri = r - l + 1;
//             if(j + (int)compa.size() - 1 <= r) compb = zifu.substr(j, compa.size());
//             else break;
//             str(compb);
//             if(compa != compb) break;
//             // else ans = std::min(ans, pri - (int)compa.size() * cnt + leng(cnt) + 2);
//             else ans = std::min(ans, dp(l, i) * cnt + leng(cnt) + 2);
//             // if(compa == compb) puts("same!");
//         }
//     }