#include <cstdio>
#include <algorithm>
using std::max;
using std::min;
using std::swap;
//使用数组
typedef unsigned long long ull;
const int N = 2e5 + 3;
int n, m, op;
ull x;
ull list[N];
int main(){
    scanf("%d%d",&n, &m);
    int len = 0;
    for (int i = 1; i <= n; i++){
        scanf("%d%llu", &op, &x);
        if (!op){
            //add
            list[++len] = x;
            for (int j = 1; j <= m; j++){
                // swap(max(list[len - j + 1],list[len - j]),min(list[len - j + 1],list[len - j]));
                if (min(list[len - j + 1],list[len - j]) == list[len - j + 1]){
                    swap(list[len - j + 1],list[len - j]);
                }else{
                    break;
                }
            }
        }else{
            //ask
            printf("%llu\n",list[len - x + 1]);
        }
    }
    return 0;
}