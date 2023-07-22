#include <cstdio>
#include <string>
int n, p, q, num[37], l = 1, r = 1; std::string que[(int)1e6 + 5];
int main(){
    scanf("%d%d%d ",&n,&p,&q);
    for (int i = 1; i <= n; i++) que[r++] = (num[i] = getchar() - '0');
    while(l < r){
        for (int i = 1; i <= n; i++){
            que[r] = que[r - n] + (char)num[i];
            if(que[r - n])
        }
    }
    return 0;
}
