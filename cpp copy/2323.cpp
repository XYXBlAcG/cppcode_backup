#include <cstdio>
#include <algorithm>
using std::max;
using std::min;
//使用链表

typedef long long ll;

// const int inf = 1e10 + 3;
const int N = 1e6 + 3;
// const int M = 1e9 + 3;
struct Node{
    ll con;
    int pre;
    int nxt;
}list[N];
ll x;
int n, m, len;
int cur = 0;
const int inf = 2e32 - 1;
int main(){
    scanf("%d%d",&n, &m);
    list[0] = (Node){-inf , 0, 0};
    for (int i = 1; i <= n; i++){
        scanf("%lld",&x);
        // list[i].con = x;
        // cur = i - 1;
        // list[i] = (Node){cur, list[cur].nxt, x};
        // printf("%d ",cur);
        if (x < list[cur].con){
            for(; list[cur].con > x; cur = list[cur].pre);
            list[i] = (Node){x, cur, list[cur].nxt};
        }else{
            for(; list[cur].con < x && cur; cur = list[cur].nxt);
            list[i] = (Node){x, list[cur].pre, cur};
        }
        list[list[cur].nxt].pre = i;
        list[list[cur].pre].nxt = i;
        printf("%d ",i + cur);
        // list[i - 1].nxt = x;
        // for (int j = ;;){
            
        // }
        // if (max(list[cur].con,x) == x){
        //     for (int j = 1; j <= m; j++){
        //         cur = list[cur].nxt;
        //         if (list[cur].con == x){
        //             printf("%d",i - cur);
        //         }
        //     }
        //     //nxt
        // }else{
        //     //pre
        //     for (int j = 1; list[cur].con ; j++){
        //         cur = list[cur].pre;
        //         if (list[cur].con == x){
        //             printf("%d",i - cur);
        //         }
        //     }
        // }
        
    }
    // for (ll j = cur; list[j].con; j = list[j].nxt){
    //     printf("%lld\n",list[j].con);
    // }
    return 0;
}