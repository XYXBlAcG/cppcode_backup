#include <cstdio>
int n;
int a1, a2, a3, a4, a5, a6;
void chai(int a){
    a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0;
    a6 = a / 100000 % 100000;
    a5 = a / 10000 % 10000;
    a4 = a / 1000 % 1000;
    a3 = a / 100 % 100;
    a2 = a / 10 % 10;
    a1 = a % 10;
}
int getlen(int a){
    int len = 0;
    for (; a > 0; ++len){
        a /= 10;
    }
    return len;
}
int ppoo(int a, int b){
    int ret = 1;
    while (b > 0){
        ret *= a;
        --b;
    }
    return ret;
}
int main(){
    // for (int i = 1; i <= 1e6; i++){

    // }
    // int n;
    // scanf("%d", &n);
    // chai(n);
    for (int j = 1; j <= 1e6; j++){
        chai(j);
        int sum = 0;
        int leen = getlen(j);
        for (int i = 1; i <= leen; i++){
            sum = ppoo(a1, leen) + ppoo(a2, leen) + ppoo(a3, leen) + ppoo(a4, leen) + ppoo(a5, leen) + ppoo(a6, leen);
        }
        if(sum == j) printf("%d ", j);
    }
    
    // printf("%d%d%d%d%d%d", a6, a5, a4, a3, a2, a1);
    return 0;
}