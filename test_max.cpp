#include <cstdio>
#include <algorithm>
#include "inline_max.cpp"
int main(){
    printf("%d\n", xyx::max(1, 2, 5, 3, 10, 2, 7, 114));
    printf("%d\n", std::max({1, 2, 5, 3, 10, 2, 7, 114}));
    return 0;
}