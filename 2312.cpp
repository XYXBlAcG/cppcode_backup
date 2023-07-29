#include <cstdio>
#include <iostream>
using std::sort;
using std::swap;
const int N = 1e5 + 5;
int n, m;
struct Node
{
    int pass;
    int next;
}list[N];

int head[N];

int order[N][3];

int res[N];

int main(){
    scanf("%d%d",&n, &m);
    int len = n;
    for (int i = 1; i <= n; i++){
        list[i].pass = i + n;
        list[i].next = i + n;
        list[i + n].pass = i;
        list[i + n].next = i;
    }
    for (int i = 1; i <= m; i++){
        scanf("%d%d",&order[i][1],&order[i][2]);
        list[order[i][2]].pass = order[i][1];
        list[order[i][2]].next = list[order[i][1]].next;
        list[list[order[i][1]].next].pass = order[i][2]; 
        list[order[i][1]].next = order[i][2];
    }
    
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (/*!list[i].next ||*/list[i].next == i + n) cnt++;
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++){
        if (/*!list[i].next*/list[i].next == i + n) continue;
        res[1] = i;
        int len1 = 1;
        for (int j = 2; j <= n; j++){
            res[j] = list[res[j - 1]].next;
            if (/*!res[j]*/res[j] == i + n) break;
            len1++;
        }
        for (int j = 1; j <= len1; j++){
            printf("%d ",res[j]);
        }
    printf("\n");
    }


    // for (int i = 1; i <= m; i++){
        
    // }
    // for (int i = 1; i <= n; i++){
    //     printf("pass:%d ",list[i].pass);
    // }printf("\n");
    // for (int i = 1; i <= n; i++){
    //     printf("next:%d ",list[i].next);
    // }printf("\n");
    
    // int len1 = 0;
    // for (int i = 1; i <= n; i++){
    //     if (!list[i].next) {len1++;}
    // }printf("\n");
    // printf("%d\n",len1);
    // for (int i = 1; i <= n; i++){
    //     if (!list[i].next || list[i].next == i + n) continue;
    //     res[1] = i;
    //     for (int j = 1; j <= n; j++){
    //         res[j] = list[res[j]].next;
    //         if (!res[j]) break;
    //         printf("%d ",res[j]);
    //     }
    //     printf("\n");
    // }
    
    return 0;
}