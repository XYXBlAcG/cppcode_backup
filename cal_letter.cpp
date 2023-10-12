#include <cstdio>
#include <iostream>
#include <string>
std::string str;
int ans = 0;
int d(char a){
    return a - 'a' + 1;
}
int main(){
    std::cin >> str;
    for (auto v : str)
        ans += d(v);
    printf("%d\n", ans);
    return 0;
}