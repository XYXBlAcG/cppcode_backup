#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
const int N = 305, M = 300, byteMax = 1e18;
struct Num{ // 取第 1 位为末尾
    int c[N]; 
    Num operator+ (Num a){
        Num ans; memset(ans.c, 0, sizeof(ans.c));
        for (int i = 1; i <= M; i++)
            ans.c[i] = a.c[i] + c[i], ans.c[i + 1] += ans.c[i] / byteMax, ans.c[i] %= byteMax;
        return ans;
    }
    // Num operator- (Num a){

    // }
    // Num operator* (Num a){

    // }
    // Num operator== (Num a){

    // }
    // Num maxNum (Num a){

    // }
    void toNum(int a){
        memset(c, 0, sizeof(c));
        for (int i = 1; a; i++)
            c[i] = a % byteMax, a /= byteMax;
    }
    void rev(int l){
        std::reverse(c + 1, c + l + 1);
    }
    void input(){
        // for (char rd = getchar(); rd < '0' || rd > '9'; rd = getchar());
        int i = 1, l = 0;
        for (char rd = getchar(); rd >= '0' && rd <= '9'; rd = getchar(), l++){
            if(c[i] > byteMax) i++;
            (c[i] *= 10) += (rd - '0'); 
        }
        for (int i = 1; i <= M; i++){
            printf("%lld", c[i]);
        }putchar('\n');
        rev(l);
    }
    void output(){
        bool fl = 0;
        for (int i = M; i; i--){
            if(c[i]) fl = 1;
            if(fl) printf("%lld", c[i]);
        }
    }
}test, test2, test3;
signed main(){
    test.input();
    test2.input();
    test3 = test + test2;
    test3.output();
    return 0;
}