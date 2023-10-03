#include <cstdio>
#include "xyx.h"
int main(){
    printf("%d\n", xyx::max(1, 2, 3, 5, 8, 20));
    for (int i = 1; i <= 100; i++){
        int j = i * i;
        xyx::output(5, "i = ", i, ", j = ", j);
    }
    
    return 0;
}