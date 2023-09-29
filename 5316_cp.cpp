#include <cstdio>
#include <vector>
typedef long long ll;
const int N = 1047199, L = 100;
int pr, r[411], a[7], ans;
struct Node{
    int cnt; ll val;
};
std::vector<Node> st[N];
ll p(int a) {return ll(r[a]) * r[a] * r[a]; }
int que(ll vv){
    int h = (vv % N + N) % N, ans = 0;
    for (auto v : st[h])
        if(v.val == vv) return ans += v.cnt;
    return 0;
}
void add(ll vv){
    int h = (vv % N + N) % N;
    for (auto &v : st[h])
        if(v.val == vv) {v.cnt++; return;}
    st[h].push_back({1, vv});
}
int main(){
    for (int i = 1; i <= 5; i++) scanf("%d", a + i);
    for (int i = -L; i <= L; i++) if(i) r[++pr] = i;
    for (int i = 1; i <= pr; i++)
        for (int j = 1; j <= pr; j++)
            add(p(i) * a[1] + p(j) * a[2]);   
    for (int i = 1; i <= pr; i++)
        for (int j = 1; j <= pr; j++)
            for (int k = 1; k <= pr; k++)
                ans += que(- p(i) * a[3] - p(j) * a[4] - p(k) * a[5]);
    printf("%d\n", ans);
    return 0;
}