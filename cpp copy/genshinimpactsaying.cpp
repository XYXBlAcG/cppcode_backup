#include <cstdio>
#define f(type, val, from, to) for(type val = from; val <= to; val++)
#define p(var) printf("%d ", var)
#define name #name
int main(){
    f(int, i, 1, 100) p(i);
    return 0;
}
