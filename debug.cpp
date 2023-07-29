#include <cstdio>
#define NAME(var) (#var)
void debug(int x){
    printf("%s = %d\n", NAME(x), x);
}
int main(){
    int abc = 1;
    debug(abc);
    return 0;
}