#include <cstdio>
typedef double d;
d f(d x){
    printf("processing : %lf\n", x);
    if(x < 0) return -x;
    else return f(x - f(x - 1)) * 0.5;
}
int main(){
    printf("%lf\n", f(3));
    return 0;
}