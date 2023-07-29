#include <cstdio>
int n;
const int N = 1e6 + 3;
struct Note
{
    // int top, bottom;
    // unsigned long long pre;
    unsigned long long nxt;
    // unsigned long long con;
    unsigned long long id;
    unsigned long long score;
}stu[N];

// int cnt[N];
// int num[N];
int head[N];
// int next[N];
unsigned long long res[N];

int max = -11451419;
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        unsigned long long id2;
        int score2;
        scanf("%llu%d",&id2,&score2);
        if (max < score2) max = score2;
        // stu[i].score = score2;
        stu[i].nxt = head[score2];
        head[score2] = i;
        stu[i].id = id2;
    }

    for (int i = max; i >= 0; i--){
        // printf("%llu \n",stu[i].id);
        int j = head[i];
        if (j == 0){
            continue;
        }
        int k = 1;
        for (;;){
            // stu[k].nxt = stu[head[i]].nxt;
            res[k] = stu[j].id;
            // printf("score %llu \n",res[k]);
            if (!stu[j].nxt){
                break;
            }j = stu[j].nxt;
            k++;
        }
        for (int o = k; o > 0; o--){
            printf("%llu %d\n", /*stu[j].id*/ res[o],i);
        }
        // printf("%llu %llu\n",stu[res[i]].id, stu[res[i]].score);
    }
    // unsigned long long ans[N];
    
    // for (int i = 1; i <= N ; i++){
    //     int pans = 0;
    //     for (int j = 0; j; j = head[j]){
    //         ans[++pans] = stu[head[i]].score;
    //     }
    //     for (int j = 1; j <= pans; j ++){
    //         printf("%llu %d\n",ans[j],i);
    //     }
    // }
    return 0;
}