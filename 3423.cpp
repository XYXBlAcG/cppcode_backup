#include <cstdio>
#include <bitset>
const int N = 2005;
int n;
std::bitset<N> A[N], B[N];
void floyd(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(A[j][i]) A[j] |= A[i];
        }
    }
}
int main(){
    scanf("%d ",&n);
    for (int i = 1, j = 1; i <= n; i++, j = 1){
        for (char c = getchar(); c > 32; c = getchar(), j++){
            A[i][j] = (c == '1');
        }
    }
    floyd();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            printf("%d", (i == j) ? 1 : (int)A[i][j]);
        }printf("\n");
    }
    return 0;
}