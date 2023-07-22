#include <cstdio>
//结合
int n;
const int N = 1e6 + 3;
struct Node
{
    int nxt;
    int pre;
    int con;
}list[N];

int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n ;i++){
        scanf("%d",&list[i].con);
        list[i].nxt = i + 1;
        list[i].pre = i - 1;
        int a1 = 0, a2 = 0;
        for (int j = 1; !a1 || !a2 || j <= i; j++){
            // if (list[i + j - 1].con || list[i - j + 1].con){
                if (list[i + j - 1].con && !a1 && i + j - 1 != i) {printf("%d ",list[i + j - 1].con); a1++;}
                if (list[i - j + 1].con && !a2 && i - j + 1 != i) {printf("%d ", list[i - j + 1].con); a2++;}
            // }
        }
        printf("\n");
    }
    return 0;
}