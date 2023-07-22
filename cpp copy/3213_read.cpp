#include <cstdio>
#include <cmath>
const int N = 1e6 + 5;
#define read(a) scanf("%d", &a)
#define readl(a) scanf("%lld", &a)
#define out(a) printf("%d", a)
#define f(i, from, to) for(int i = from; i <= to; i++)
#define INF 0x3f3f3f3f
int rn, rm, rk, rt;
int pl[N], ul[N], vl[N]; long long wl[N], ra[N], rb[N]; int can[N], pcan, rec[N], prec;
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

void get_line(int* p, int* u, int* v, long long* w, long long ku, long long kv){
	// int ku, kv;
	// scanf("%d%d%d" LLD "%d%d", p, u, v, w, &ku, &kv);
	*u = (*u + (ku & ans_buff) - 1) % n + 1;
	*v = (*v + (kv & ans_buff) - 1) % n + 1;
}

void put_ans(int ans){
	// printf("%d\n", ans);
	ans_buff = ((ans_buff << 1) | ans) & BUFF_MAGIC;
}

#ifdef LLD

#undef LLD

#endif

}
int main(){
    // read(rn); read(rm); read(rk); read(rt);
    maze_io::get_args(&rn, &rm, &rk, &rt);
    f(i, 1, rm){
        read(pl[i]);
        if(pl[i]){pcan++;
        rec[++prec] = i;}
        read(ul[i]);
        read(vl[i]);
        readl(wl[i]);
        readl(ra[i]);
        readl(rb[i]);
    }
    f(i, 1, pcan){
        read(can[rec[i]]);
    }
    f(i, 1, rm){
        maze_io::get_line(&pl[i], &ul[i], &vl[i], &wl[i], ra[i], rb[i]);
        if(pl[i])  maze_io::put_ans(can[i]);
        printf("%d %d %d %lld\n", pl[i], ul[i], vl[i], wl[i]);
    }
    return 0;
}