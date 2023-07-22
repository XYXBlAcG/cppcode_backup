#include <cstdio>
#include <algorithm>
// const int N = 0;
typedef unsigned long long llu;
int n;
int main(){
    // printf("5000 7497\n");
    // n = 5000;
    // for (int i = 2; i <= 2499; i++){
    //     printf("%d %d 10\n", i, i + 1);
    // }
    // for (int i = 2; i <= 2500; i++){
    //     printf("%d 1 %d\n", i, (int)1e9 - 100 * (i - 2));
    // }
    // for (int i = 2501; i <= 5000; i++){
    //     printf("1 %d 10\n", i);
    // }
    printf("5000 *\n");
    for (int i = 1; i <= 4998; i += 2){
        printf("%d %d 100\n", i, i + 1);
        printf("%d %d 100\n", i + 1, i + 2);
        printf("%d %d 10000\n", i, i + 2);
    }

    return 0;
}