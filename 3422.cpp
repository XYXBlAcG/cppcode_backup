#include <cstdio>
#include <bitset>
const int N = 2e5 + 5;
std::bitset<N> A, C;
int main(){
    int cnt1 = 0, cnt2 = 0, last = 0, i;
    for (char c = getchar(); c > 32; c = getchar()){
        A[cnt1++] = (c == '1');
    }
    for (char c = getchar(); c > 32; c = getchar(), cnt2++){
        if(c == '1'){
            A <<= cnt2 - last;
            C ^= A;
            last = cnt2;
        }
    }
    for (i = cnt2 + cnt1 - 2; i && !C[i]; i--);
    for (int j = 0; j <= i; j++){
        putchar('0' + C[j]);
    }putchar('\n');
    return 0;
}