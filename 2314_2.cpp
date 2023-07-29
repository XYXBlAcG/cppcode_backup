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
    // len1 = len;
    // for (int i = 1; i <= len; i++){
    //     res[i].next = i + 1;
    //     res[i].pass = i - 1;
    // } 
    res[1].pass = 0;
    res[1].next = 0;
    for (int i = 1; i <= len; i++){
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
            res[++len1] = (Node){cur,res[cur].next,order[i]};
            res[res[cur].next].pass = res[res[cur].pass].next = cur;
        }
    }

    for (int i = 1; i <= len; i++){
        printf("%c ",res[i].con);
    }
    for (int i = 1; i <= len; i++){
        printf("%d ",res[i].next);
    }
    for (int i = 1; i <= len; i++){
        printf("%d ",res[i].pass);
    }
    // for (int i = 1; i <= len; i++){
    //     printf("%c",res[i].con);
    // }
    // int j = 1;
    // printf("%d \n",len1);
    // for (int j = 1; j != 0; j = res[j].next){
    //     printf("%c", res[j].con);
    // }
    printf("\n");
    return 0;
}
