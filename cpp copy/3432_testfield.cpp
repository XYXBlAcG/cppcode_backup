#include <bitset>
#include <cstdio>
int main(){
    std::bitset<1005> bits((1 << 1000));
    printf("%llu\n",  bits.to_ulong());
    return 0;
}