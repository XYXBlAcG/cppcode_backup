#include <cstdio>

const int N = 1e6 + 3;

struct Node
{
    int pass;
    int next;
    char con;
}res[N];

char order[N];
int cur = 1;//第几个字符的后面那个空隙
int len = 0, len1 = 0;
// char nstr[N];
// char res[N];
int tmp;

int main(){
    for (char i = getchar(); i >= 32 ; i = getchar()){
        order[++len] = i;
    }
    len1 = len;
    // for (int i = 1; i <= len; i++){
    //     res[i].next = i + 1;
    //     res[i].pass = i - 1;
    // } 
    res[1].pass = 0;
    res[1].next = 0;
    for (int i = 1; i <= len1; i++){
        if (order[i] == '}'){//删除这个字符
            if(cur == 0) continue;
            res[res[cur].pass].next = res[cur].next;
            res[res[cur].next].pass = res[cur].pass;
            cur = res[cur].pass;
        }else if (order[i] == '['){
            // order[i] = nstr[cur + 2];
            // order[nstr[cur + 2]].pass = nstr[cur];
            if (cur == 0) continue;
            cur = res[cur].pass;
        }else if (order[i] == ']'){
            if (res[cur].next == 0) continue;
            cur = res[cur].next;
        }else{
            // res[res[cur + 1].pass].next = res[cur].next;
            // res[res[cur + 1].next].pass = res[cur + 2].pass;
            // res[cur].next = cur + 1;
            // res[cur + 2].pass = cur - 1;
            // cur++;
            res[++len] = (Node){cur,res[cur].next,order[i]};
            res[res[cur].next].pass = res[res[cur].pass].next = cur;
        }
    }
    // for (int i = 1; i <= len; i++){
    //     printf("%c",res[i].con);
    // }
    // int j = 1;
    printf("%d \n",len1);
    for (int i = 1; i <= len1; i++){
        // printf("!\n");
        if (res[i].next == 0) continue;
        for (int j = 1; j != 0; j = res[j].next){
            printf("%d ", res[j].con);
        }
        printf("\n");
    }
    // for (int i = 1; i <= n; i++)
    return 0;
}


// order[0].pass = 0;order[0].next = 0;order[len].pass = 0;order[len].next = 0;
    // for (int i = 1; i <= len; i++){
    //     order[nstr[i]].next = nstr[i + 1];
    //     order[nstr[i]].pass = nstr[i - 1];
    // }
    // order[1].pass = 0;
    // order[len].next = 0;