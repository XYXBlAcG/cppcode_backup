#include <cstdio>
#include <algorithm>
int a[8] = {0, 1, 2, 3, 4, 5}, ans;
int main(){
    // std::sort(a + 1, a + 8);
    for (int i = 1; i <= 5; i++){
        for (int j = i + 1; j <= 5; j++){
            for (int k = j + 1; k <= 5; k++){
                if(i != j && j != k){
                    if((a[i] <= a[j] && a[j] <= a[k]) || (a[k] <= a[j] && a[j] <= a[i])) ans += a[j];
                    else if((a[j] <= a[i] && a[i ]<= a[k]) || (a[k] <= a[i] && a[i] <= a[j])) ans += a[i];
                    else if((a[i] <= a[k] && a[k] <= a[j]) || (a[j] <= a[k] && a[k ]<= a[i])) ans += a[k];
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}