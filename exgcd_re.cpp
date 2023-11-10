#include <cstdio>

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