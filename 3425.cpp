#include <cstdio>
#include <bitset>
const int N = 1005;
int n, T;
std::bitset<N> A[N];
unsigned long long tmp;
int main(){
    scanf("%d%d ",&n,&T);
    for (int i = 1, j = 1; i <= n; i++, j = 1){
        for (char c = getchar(); c > 32; c = getchar(), j++){
            A[i][j] = (c == '1');
        }
    }
    for (int i = 1; i <= 64; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                
            }
        }
    }
    return 0;
}