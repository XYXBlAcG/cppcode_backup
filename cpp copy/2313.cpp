#include <cstdio>
const int N = 1e5 + 5;
int n, m;
struct Node
{
    int next;
    int pass;
}o[N];

int tmp;//cursor

int ans[N];

int main(){
    //input
    scanf("%d%d", &n, &m);
    //main
    for (int i = 1; i <= n; i++){
        o[i].next = i + 1;
        o[i].pass = i - 1;
    }
    o[n].next = 1;
    o[1].pass = n;
    tmp = n;
    for (int i = 1 ; i <= n; i++){
        for (int j = 1; j <= m; j++){
            tmp = o[tmp].next;
        }
        //del
        o[o[tmp].pass].next = o[tmp].next;
        o[o[tmp].next].pass = o[tmp].pass;
        ans[i] = tmp;
    }
    //output
    for (int i = 1; i <= n; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}