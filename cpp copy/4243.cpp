#include <cstdio>
int t, n, s[2], ans;
int main(){
    scanf("%d", &t);
    for (int i = 1; i <= t; i++){
        scanf("%d", &n);
        ans = 0;
        for (int j = 1; j <= n; j++){
            int cur = (j & 1) ^ 1;
            scanf("%d", s + cur);
            if(cur){
                int A = ((s[1] - 1) | (s[0] - 1)), c = 0;
                while(A & 1) A >>= 1, c++;
                ans ^= c;
            }
        }
        puts(ans ? "YES" : "NO");
    }
    return 0;
}