#include <cstdio>
#include <cstdlib>
#include <algorithm>

const int N = 100011, ninf = 0x80808080;
int n, m, pt, rt, val;
struct Node{
	int sz, vl, hp, mx, ch[2];
}t[N * 2 + 1];
using std::max;

int ran(){
	// return rand() << 30 ^ rand() << 15 ^ rand();
	return rand();
}

void up(int v){
	t[v].mx = max(max(t[t[v].ch[0]].mx, t[t[v].ch[1]].mx), t[v].vl);
    printf("%d %d %d %d\n", t[v].mx, t[v].vl, t[t[v].ch[0]].mx, t[t[v].ch[1]].mx);
	t[v].sz = t[t[v].ch[0]].sz + t[t[v].ch[1]].sz + 1;
}

void rot(int& v, bool sn){
	int s = t[v].ch[sn];
	t[v].ch[sn] = t[s].ch[!sn];
	t[s].ch[!sn] = v;
	up(v);
	up(s);
	v = s;
}

void ins(int& v, int idx){
	if(!v)
		return void(t[v = ++pt] = {1, val, ran(), val, {0, 0}});
	int rnk = t[t[v].ch[0]].sz + 1;
	bool sn = idx >= rnk;
	ins(t[v].ch[sn], idx - (sn ? rnk : 0));
	if(t[v].hp < t[t[v].ch[sn]].hp)
		rot(v, sn);
	else
		up(v);
}

void mdf(int v, int idx){
	int rnk = t[t[v].ch[0]].sz + 1;
	bool sn = idx >= rnk;
	if(idx == rnk){
        puts("upd");
		t[v].vl = val;
		return up(v);
	}
	mdf(t[v].ch[sn], idx - sn * rnk);
	up(v);
}

int qry(int v, int lef, int rig){
	if(rig < 1 || t[v].sz < lef)
		return ninf;
	if(lef <= 1 && t[v].sz <= rig)
		return t[v].mx;
	int rnk = t[t[v].ch[0]].sz + 1;
	int ret = (lef <= rnk && rnk <= rig ? t[v].vl : ninf);
	for(int i = 0; i <= 1; i++)
		ret = max(ret, qry(t[v].ch[i], lef - i * rnk, rig - i * rnk));
	return ret;
}

void print(int v){
	if(!v)return;
	print(t[v].ch[0]);
	printf("%2d.sz=%2d vl=%2d hp=%11d mx=%2d ch[2]=[%2d,%2d]\n", v, t[v].sz, t[v].vl, t[v].hp, t[v].mx, t[v].ch[0], t[v].ch[1]);
	print(t[v].ch[1]);
}

int main(){
	// srand(19337);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &val);
		ins(rt, i);
		//print(rt);
		//printf("###%d\n", i);
	}
	for(int i = 1; i <= m; i++){
		int op, idx;
		scanf("%d%d%d", &op, &idx, &val);
		if(op == 1)
			ins(rt, idx - 1);
		else if(op == 2)
			mdf(rt, idx);
		else
			printf("%d\n", qry(rt, idx, val));
		//print(rt);
		//printf("###%d\n", i);
		//fflush(stdout);
	}
	return 0;
}
/*
10 9 10 -4557430888798830399
10 10 -4557430888798830399 -4557430888798830399
10 9 10 10
5 5 -4557430888798830399 -4557430888798830399
10 6 10 9
*/