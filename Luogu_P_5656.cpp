#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
int t, a, b, c;
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}
int exgcd(int a, int b, int& x, int& y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int tmp = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
    return tmp;
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &a, &b, &c);
        
    }
    return 0;
}