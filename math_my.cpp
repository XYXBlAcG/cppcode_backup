#include <cstdio>
typedef double d;
d abs(d a){ return a > 0 ? a : -a; }
d max(d a, d b){ return a > b ? a : b; }
int main(){
    printf("%lf", abs(-3.0));
    return 0;
}