#include <cstdio>
int n;
char accept[120],word[120][120];
char start;
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        scanf("%s",&accept[i]);
    }
    for (int i = 1; i <= n; i++){
        // char c;
        char c = getchar();
        // scanf("%c",&word[i]);
        // if (i == n + 1){
        //     // getchar();
        //     start = getchar();
        //     break;
        // }
        for (int z = 1; z <= 20; z++){
        word[i][z] = c;
        if (0 <= c && c < 32){
            break;
        }
        
        
        printf("%s ",&word[i][z]);
        }
        printf("\n");
    }
    // getchar();
    scanf("%c\n",&start);
    printf("%c\n",start);
    return 0;
}