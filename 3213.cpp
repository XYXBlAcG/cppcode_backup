#include <cstdio>
#include <algorithm>
using std::abs;
namespace maze_io{

#ifdef WIN32

#define LLD "%I64d"

#else

#define LLD "%lld"

#endif

typedef long long lld;
const int BUFF_MAGIC = (1 << 30) - 1;
int n, m, k, t;
int ans_buff = 0;
	
void get_args(int* n, int* m, int* k, int* t){
	scanf("%d%d%d%d", n, m, k, t);
	maze_io::n = *n;
	maze_io::m = *m;
	maze_io::k = *k;
	maze_io::t = *t;
}

void get_line(int* p, int* u, int* v, long long* w){
	int ku, kv;
	scanf("%d%d%d" LLD "%d%d", p, u, v, w, &ku, &kv);
	*u = (*u + (ku & ans_buff) - 1) % n + 1;
	*v = (*v + (kv & ans_buff) - 1) % n + 1;
}

void put_ans(int ans){
	printf("%d\n", ans);
	ans_buff = ((ans_buff << 1) | ans) & BUFF_MAGIC;
}

#ifdef LLD

#undef LLD

#endif

}
typedef long long ll;
const int N = 1e6 + 5;
int n, m, k, t;
int fath[N]; ll dist[N], ans[N];
ll _gcd_(ll a, ll b) { return b == 0 ? a : _gcd_(b, a % b); }
int find(int x){
	if(fath[x] == x) return x;
	int y = fath[x]; fath[x] = find(fath[x]);
	dist[x] += dist[y];
	return fath[x];
}
void merge(int x, int y, ll w){
    int a = find(x), b = find(y);
    if(a == b){
        ans[a] = _gcd_(ans[a], abs(dist[x] - dist[y] - w));
    }else{
        fath[a] = b; dist[a] = dist[y] + w - dist[x];
        ans[b] = _gcd_(ans[a], ans[b]);
    }
}
void output(int u, int v, ll w){
    int a = find(u), b = find(v); ll tmp = abs(dist[u] - dist[v] - w);
    maze_io::put_ans(((a == b) ? (int)((!ans[a] && !tmp) || (ans[a] && tmp % ans[a] == 0)) : 0));
}
int main(){
    maze_io::get_args(&n, &m, &k, &t); 
    for (int i = 1; i <= n; i++){
        fath[i] = i;
    }
    int p, u, v; ll w;
    for (int i = 1; i <= m; i++){
        maze_io::get_line(&p, &u, &v, &w);
        if(!p){
            merge(u, v, w);
        }else{
            output(u, v, w);
        }
    }
    return 0;
}
