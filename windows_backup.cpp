#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
#ifdef WIN_32
#include <windows.h>
#else
#include <unistd.h>
#endif
const int N = 1e5 + 5;

int main(){
    while(1){
        #ifdef WIN_32
            system("copy ./cpp /goto");
            sleep(60 * 1000);
        #else
            system("cp .cpp /goto");
            sleep(60);
        #endif
    }
    return 0;
}