#include <cstdio>
#include <cmath>
#include <algorithm>
const int N = 100000;
int f, aa, bb;
char res[20];
int leng(int a){
    if(a == 0) return 1;
    int cnt = 0;
    while(a)
        a /= 10, cnt++;
    return cnt;
}
void read(int &az){
    int fuu = 0;
    for (char c = getchar(); c != '.'; c = getchar()){
        if(c <= 32) continue;
        if(c == '-') {fuu = 1; continue;}
        (az *= 10) += (c - '0');
    }
    // printf("%d\n", f);
    for (char c = getchar(); c > 32; c = getchar()){
        (az *= 10) += (c - '0');
    }
    az *= 100;
    // az *= 10;
    if(fuu) az *= -1;
}
void output(int ans){
    int fu = (ans < 0);
    ans = std::abs(ans);
    if(ans % 10 >= 5) {
        ans /= 10;
        ans++;
    }else{
        ans /= 10;
    }
    if(fu) putchar('-');
    int tmp = ans;
    for (int i = 1; i <= leng(ans); i++){
        if(i >= 5) {
            if(i == 5) res[i] = '.';
            res[i + 1] = (tmp % 10) + '0', tmp /= 10;
        }else{
            res[i] = (tmp % 10) + '0', tmp /= 10;
        }
    }
    if(leng(ans) <= 4){
        // int tmp = ans;
        for (int i = leng(ans) + 1; i <= 6; i++){
            if(i == 5) res[i] = '.';
            else if(i == 6) res[i] = '0';
            else res[i] = '0';
        }
    }
    for (int i = std::max(6, leng(ans) + 1); i ; i--){
        putchar(res[i]);
    }putchar('\n');
}
int main(){
    read(aa), read(bb);
    printf("%d %d\n", aa, bb);
    aa *= N, bb *= N;
    // printf("%d\n", f);
    int ans = aa + bb;
    printf("%d\n", ans);
    output(ans);
    ans = aa - bb;
    output(ans);
    ans = aa * bb;
    output(ans);
    ans = aa / bb;
    output(ans);
    
    
    // printf("%d\n", ans);
    // if(fu) ans *= -1;
    // int len = leng(ans);
    // if(len <= 4)
    return 0;
}