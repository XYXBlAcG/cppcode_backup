#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#define p(...) printf(__VA_ARGS__)
#define rd(x) scanf("%s", &x)
const int N = 1e5 + 5;
int n, q;
std::string str[N];
int main(){
    scanf("%d%d", &n, &q);
    p("%d", n);
    for (int i = 1; i <= n; i++) std::cin >> str[i];
    return 0;
}