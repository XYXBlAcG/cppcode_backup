#include <cstdio>
#include <cmath>
// const int N = 0;
typedef double d;
int n;
int main(){
    scanf("%d",&n);
    printf("%lf\n", (d)pow(3, (d)n) + (d)((d)(n - 2) / (d)(n + 1)));
    return 0;
}