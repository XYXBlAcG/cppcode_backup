#include <cstdio>
#include <iostream>
#include <string>
const int N = 15;
int n, a[N]; std::string str[N], st;
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) std::cin >> str[i];
    std::cin >> st;
    
    return 0;
}