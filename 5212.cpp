#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#define int long long
const int N = 3e4 + 5;
int n, m, _0 = 0, _1 = 1, b[N], p[N];
std::bitset<N> vis[N];
std::vector<int> build[N];
struct Node{int pos, step, move;};
std::deque<Node> que;
void solve(){
    que.push_back({b[0], p[0], 0});
    while(!que.empty()){
        Node vv = que.front(); que.pop_front();
        if(vv.pos == b[1]) {printf("%lld\n", vv.move); return;}
        if(vis[vv.pos][vv.step]) continue; vis[vv.pos][vv.step] = 1;
        for (auto v : build[vv.pos]) que.push_front({vv.pos, v, vv.move});
        if(vv.pos - vv.step >= 0) que.push_back({vv.pos - vv.step, vv.step, vv.move + 1});
        if(vv.pos + vv.step <= n) que.push_back({vv.pos + vv.step, vv.step, vv.move + 1});
    }
    puts("-1");
}
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < m; i++){
        scanf("%lld%lld", b + i, p + i);
        if(i == 0) _0 = b[i];
        if(i == 1) _1 = b[i]; 
        build[b[i]].push_back(p[i]);
    }
    if(_0 == _1){
        puts("0"); return 0;
    }
    solve();
    return 0;
}