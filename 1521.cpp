#include <cstdio>
int n;
char c;
int main(){
    freopen("pfile.in", "r", stdin);
    freopen("pfile.out", "w", stdout);
    while(c != '\n') c = getchar();
    scanf("%d", &n);
    freopen("pfile.in", "r", stdin);
    while(n--) c = getchar();
    printf("%c\n", c);
    return 0;
}