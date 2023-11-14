#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 1e5 + 5;
int n, ans, len;
int getlen(int x){
    int len = 0;
    while(x) x /= 10, len++;
    return len;
}
int main(){
    scanf("%d", &n), len = getlen(n);
    for (int i = 1; i <= len - 1; i++){
        ans += 10 * (i * 10)
    }
    return 0;
}