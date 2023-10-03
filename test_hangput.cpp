#include <cstdio>
#include "inline_put.cpp"
int main(){
    for (int i = 1; i <= 100; i++){
        int j = i * i;
        xyx::output(5, "i = ", i, "j = ", j);
    }
    // for (int i = 1; i <= 100; i++){
    //     int j = i * i;
    //     intIO.ele_2("i 和 i * i 的值为: ", i, j, 10);
    // }
    // for (long long i = 1000000; i <= 1001000; i++){
    //     long long j = i * i;
    //     longIO.ele_2("i 和 i * i 的值为: ", i, j, 20);
    // }
    return 0;
}