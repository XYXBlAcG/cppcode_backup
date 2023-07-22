#include <cstdio>
unsigned long long n;
unsigned long long list[25];
unsigned long long result = 9223372036854775807;
unsigned long long tmp = 0;
unsigned long long a[25] ;
void dfs(unsigned long long in){
    // if (a[in] == 1){

    // }
    
    
    if (in > n){
        unsigned long long x1 = 1;
        unsigned long long x2 = 1;
        unsigned long long x3 = 1;
        
    for (int i = 1; i <= n; i++){
        if (a[i] == 1){
            x1*=list[i];
        }else if (a[i] == 2){
            x2*=list[i];
        }else if (a[i] == 3){
            x3*=list[i];
        }
    }
    // printf("%llu",xx[1]);
    if (x1 == 1 || x2 == 1 || x3 == 1){
        return;
    }
    // printf("%llu ",x1);
    // printf("%llu ",x2);
    // printf("%llu ",x3);
    tmp = x1 + x2 * 2 + x3 * 3;
    if (tmp < result){
        result = tmp;
    }
    // if (in > )
    // for (int i = 1; i <= n; i++){
    //     printf("%lld",xx[i]);
    // }
    // for (int i = 1; i <= n; i++){
    //     for (a[i] = 0; a[i] <= list[i] ;a[i]++){

    //     }
    // }
    return;
    }
    for (a[in] = 1; a[in] <= 3; a[in]++){
        // for (int x = 1; x <= n; x++){
        //     // xx[i][list[x]] = list[x];
        // }
        // for (int x = 1; x <= n; x++){
        //     printf("")
        // }
        // printf("%llu",a[in]);
        dfs(in + 1);
    }
}
int main(){
    scanf("%llu",&n);
    for (int i = 1; i <= n; i++){
        scanf("%llu",&list[i]);
    }
    dfs(1);
    printf("%llu",result);
    return 0;
}