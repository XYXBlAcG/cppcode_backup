#include <cstdio>
#include "inline_moder.cpp"
const long long N = 1e9 + 7;
long long a[10] = {114514, 1919810, 129323123, 3098723423, 1209312, 12334234, 87687687};
int main(){
    printf("%lld\n", moder(N, 114514ll, 1919810ll, 129323123, 3098723423, 1209312, 12334234, 87687687));
    return 0;
}