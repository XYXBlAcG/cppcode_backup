#include <cstdio>
#include <algorithm>
int n, res = 0;
int cnt = 1;
struct td{
    int list[60] , p ;
    int pop(){
        return list[p--];
    }
    void push(int a){
        list[++p] = a;
    }
}in, zhan, out, ans[100000] ;
bool operator<(const td& a, const td& b){
    for (int i = 0; i < n; i++){
        if (a.list[i] != b.list[i]){
            return a.list[i] < b.list[i];
        }
    }
    return 0;
}
void chu(){
    if (out.p == n){
        ans[++cnt] = out;
        return;
    }
    if (in.p){
        zhan.push(in.pop());
        chu();
        in.push(zhan.pop());
    }
    if (zhan.p){
        out.push(zhan.pop());
        chu();
        zhan.push(out.pop());
    }  
}
int main(){
    scanf("%d",&n);
    in.p = n;
    for (int i = n; i > 0; i--){
        scanf("%d", &in.list[i]);
    }
    chu();
    std::sort(ans+1, ans+cnt+1);
    for (int i = 1; i <= cnt; i++){
        if (ans[i - 1] < ans[i]){
        for (int z = 1; z <= n; z++){
                printf("%d ", ans[i].list[z]);
        }
        
        printf("\n");
        }
    }
    return 0;
}