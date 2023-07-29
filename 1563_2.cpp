#include <cstdio>
int n, m, timer = 1;
int mem[10000][10000];
void f(int p, int l){
    if (p == m + 1){
        printf("\n");
        ++timer;
        return;
    }
    for(int i = l + 1; i <= p + n - m; i++){
        
        if (mem[timer - 1][p] != i){ 
            printf("%c->%d ", (char)('A' + p - 1), i);
        }
        mem[timer][p] = i;
        f(p + 1, i);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    f(1,0);
    return 0;
}