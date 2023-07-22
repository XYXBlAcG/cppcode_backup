#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using std::sort;
const int N = 4e5 + 5;
struct Note{
    std::string str;
    int idx;
    bool if1;
    bool if2;
    int if3;
}a[4][N];
int ans2[N];
int cnt[N], clen;
bool cmp(const Note& a, const Note& b){
    return a.str < b.str;
}
bool cmp2(const Note& a, const Note& b){
    if (a.str == b.str) return a.if2 < b.if2;
    return a.str < b.str;
}
bool cmp3(const Note& a, const Note& b){
    if (a.str == b.str) return a.if3 > b.if3;
    return a.str < b.str;
}
int old[N];
char cha[N];
int n, m, p;
int main(){
    //q1
    {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%s",cha);
        a[1][i].str = cha;
        a[1][i].idx = i;
        a[1][i].if1 = 1;
        a[2][i].str = cha;
        a[2][i].idx = 0;
        a[2][i].if1 = 1;
        a[2][i].if2 = 0;
        a[3][i].str = cha;
        a[3][i].idx = i;
        a[3][i].if3 = 0;
    }
    std::sort(a[1] + 1, a[1] + 1 + n, cmp);
    for (int i = 1; i <= n; i++){
        printf("%d ", a[1][i].idx);
        old[i] = a[1][i].idx;// i -> idx
    }printf("\n");
    }
    //q2
    {
    scanf("%d", &m);
    for (int i = 1; i <= m; i++){
        scanf("%s",cha);
        a[2][i + n].str = cha;
        a[2][i + n].idx = i;
        a[2][i + n].if2 = 1;
    }
    std::sort(a[2] + 1, a[2] + 1 + n + m, cmp2);
    // printf("\n");
    
    int rank = 0;
    for (int i = 1; i <= n + m; i++){
        if(!a[2][i].if2){
            rank++;
        }else{
            ans2[a[2][i].idx] = rank;
        }
    }
    for (int i = 1; i <= m; i++){
        printf("%d ",ans2[i]);
    }
    printf("\n");
    }
    // //q3
    scanf("%d", &p);
    for (int i = n + 1; i <= n + p; i++){
        scanf("%s",cha);
        a[3][i].str = cha;
        a[3][i].if3 = 1;
        a[3][i].idx = i;
        a[3][i + p].str = cha;
        a[3][i + p].str += '~';
        a[3][i + p].if3 = 2;
        a[3][i + p].idx = i;
    }
    std::sort(a[3] + 1, a[3] + 1 + n + 2 * p, cmp3);
    // for (int i = 1; i <= n + 2 * p; i++){
    //     printf("(%d, %s, %d) \n",a[3][i].idx ,a[3][i].str.c_str(), a[3][i].if3);
    // }printf("\n");
    // clen = n;
    int symbol = 0;
    // printf("!!!");
    // fflush(stdout);
    int l[N], r[N];
    for (int i = 1; i <= n + 2 * p; i++){
        if(a[3][i].if3 == 0){
            symbol++;
        }else if(a[3][i].if3 == 1){
            l[a[3][i].idx] = symbol;
        }else if(a[3][i].if3 == 2){
            r[a[3][i].idx] = symbol - l[a[3][i].idx];
        }
    }
    for (int i = n + 1; i <= n + p; i++){
        printf("%d ",r[i]);
    }printf("\n");
    return 0;
}