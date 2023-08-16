#include <cstdio>

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

int n, m, k, t;



int main(){
    maze_io::get_args(&n, &m, &k, &t);
    for (int i = 1; i <= m; i++){
        int p, u, v; long long w;
        maze_io::get_line(&p, &u, &v, &w); 
        if(p == 0){

        }else if(p == 1){

        }
    }
    return 0;
}