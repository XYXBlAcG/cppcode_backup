#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>

int main(){
    int n = 1024;
    for (int i = 1; i < n; i++){
        printf("%d %d\n", i, i + 1);
    }
    return 0;
}