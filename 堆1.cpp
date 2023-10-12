#include <cstdio>
#include <algorithm>
const int N = 1e5 + 5;
struct Heap{
    int data[N], pdata;
    void push(int x){
        data[++pdata] = x;
        int cur = pdata;
        while(cur != 1){
            if(data[cur >> 1] <= data[cur]) break;
            std::swap(data[cur >> 1], data[cur]);
            cur >>= 1;
        }
    }
    int tpop(){
        int ans = data[1], cur = 1;
        data[1] = data[pdata--];
        data[pdata + 1] = 0;
        while(cur <= pdata){
            int l = cur << 1, r = (cur << 1) + 1;
            if(r < pdata && data[r] < data[l]) l = r;
            if(data[l] >= data[cur]) break;
            std::swap(data[l], data[cur]);
            cur = l;
        }
        return ans;
    }
}heap;
int n, m;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int num = 0;
        scanf("%d", &num);
        heap.push(num);
    }
    for (int i = 1; i <= m; i++){
        int op = 0, x = 0;
        scanf("%d", &op);
        if(op == 1){
            scanf("%d", &x);
            heap.push(x);
        }else{
            printf("%d\n", heap.tpop());
        }
    }
    return 0;
}