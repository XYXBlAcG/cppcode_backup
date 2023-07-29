#include <cstdio>
#include <algorithm>
#include <vector>
const int N = 1e6 + 5;
int n, id[N];
std::vector<int> st[N];
int ans[N * 2], pans, tou[N], tov[N];
struct Node{
    int idx;
    int val;
}tmp[N];
bool cmp(int a, int b) {
    return a > b;
}
bool cmp2(const Node& a, const Node& b) {
    return a.val > b.val;
}
void dfs(int u){
    for (int i = st[u].size() - 1; i >= 0; i--){
        int v = st[u][i];
        if(!st[u].size()) break;
        st[u].pop_back();
        dfs(v);
    }
    ans[++pans] = u / 10000;
}
int main(){
    scanf("%d ",&n);
    int cnt2 = 0;
    for (int i = 1; i <= n; i++){
        int tmp[8], cnt = 0;
        for (char c = getchar(); c > 32; c = getchar()){
            tmp[++cnt] = (int)(c - '0');
        }
        int u = 0, v = 0;
        for (int j = 1; j <= 6; j++){
            if(j != 6) u = u * 10 + tmp[j];
            if(j != 1) v = v * 10 + tmp[j];
        }tou[i] = u;
        tov[i] = v;
        // id[u] = i;
        st[u].push_back(v);
    }
    for (int i = 0; i <= 1000000; i++){
        if(st[i].size())
            std::sort(st[i].begin(), st[i].end(), cmp);
    }
    for (int i = 0; i <= 1000000; i++){
        if(st[i].size()){
            dfs(i);
            break;
        }
    }
    for (int i = pans; i > 1; i--){
        printf("%d", ans[i]);
    }
    // if(ans[pans] == ans[1] && pans > 1) {
    //     ans[pans--] = 0;
    // }
    // // printf("\n");
    // for (int i = 1; i <= pans; i++){
    //     tmp[i] = (Node){i, ans[i]};
    //     ans[i + pans] = ans[i];
    // }
    // std::make_heap(tmp + 1, tmp + pans + 1, cmp2);
    // // printf("tmp1 = %d\n", tmp[1].val);
    // for (int i = tmp[1].idx + pans; i > tmp[1].idx; i--){
    //     printf("%d", ans[i]);
    // }printf("\n"); 
    return 0;
}