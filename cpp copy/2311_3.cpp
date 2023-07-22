#include <cstdio>

const int N = 1e6 + 3;

struct Note
{
    unsigned long long id;
    int score;
    unsigned long long nxt;
}stu[N];

int head[100];
unsigned long long res[N];

int main(){
    int n;
    scanf("%d",&n);
    int max = -0x7fffffff;
    for (int i = 1; i <= n; i++){
        unsigned long long id2;
        int score2;
        scanf("%llu%d",&id2,&score2);
        if (max < score2) max = score2;
        stu[i].score = score2;
        stu[i].nxt = head[score2];
        head[score2] = i;
        stu[i].id = id2;
    }

    for (int i = max; i >= 0; i--){
        int j = head[i];
        while (j){
            printf("%llu %d\n", stu[j].id, i);
            j = stu[j].nxt;
        }
    }
    return 0;
}
