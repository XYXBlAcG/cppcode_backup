#include <cstdio>
#include <iostream>
bool func(int p, int q){
    return !((!p || q) && (!q || p)) || (p || q);
}
int main(){
    printf("%d\n", func(0, 0));
    // std::cout << 011 + 11 << '\n';
    return 0;
}