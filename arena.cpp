#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#define int long long
#define INF 0x3f3f3f3f
#define EPS 1e-6
#define pi2 acos(0)
typedef double d;
const int N = 200 + 5;
int q, n, m, hh;
int xy[N], cm[N], jx[N];
bool die[N];
struct Ispack{
	int st, ed;
}isxy[N], iscm[N], isjx[N];
struct Dis{
	int x, y;
};
struct Mo{
	Dis mdf;
	Dis org;
	d h;
}mst[N];
void clean(){
	memset(mst, 0, sizeof(mst));
	memset(die, 0, sizeof(die));
	memset(xy, 0, sizeof(xy));
	memset(cm, 0, sizeof(cm));
	memset(jx, 0, sizeof(jx));
	memset(isxy, 0, sizeof(isxy));
	memset(isjx, 0, sizeof(isjx));
	memset(iscm, 0, sizeof(iscm));
	hh = 0;
}
bool chkxy(int id, int t){
	return isxy[id].ed >= t;
}
bool chkjx(int id, int t){
	return isjx[id].ed >= t;
}
bool chkcm(int id, int t){
	return iscm[id].ed >= t;
}
Dis curdis(int id, int t){
	// fuck 
	Mo x = mst[id];
	int efftim = t;
	if(chkxy(id, t)){
		efftim -= (xy[id] - (isxy[id].ed - t));
	}else efftim -= xy[id];
	return (Dis){x.org.x + x.mdf.x * efftim, x.org.y + x.mdf.y * efftim};
	
//	return (Dis){x.org.x + x.mdf.x * t, x.org.y + x.mdf.y * t};
}
int p2(int x){
	return x * x;
}
d odis(Dis a, Dis b){
	return sqrtl(p2(a.x - b.x) + p2(a.y - b.y));
}
int odis2(Dis a, Dis b){
	return (p2(a.x - b.x) + p2(a.y - b.y));
}
int mdis(Dis a, Dis b){
	return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}
bool chksg(int id){
	return mst[id].h <= 0;
}
void rmvsg(int id){
	die[id] = 1;
}
d gethp(){
	d sum = 0.0;
	for (int i = 1; i <= n; i++){
		if(die[i]) continue;
		sum += mst[i].h;
	}
	return sum;
}
void print(){
	for (int i = 1; i <= n; i++)
		printf("%.2lf ", mst[i].h);
	putchar('\n');
}
bool eql(d a1, d a2){
	return fabsl(a1 - a2) < EPS;
}
bool samefu(int a, int b){
	if(a >= 0 && b >= 0) return 1;
	if(a < 0 && b < 0) return 1;
	return 0;
}
bool chkdir(int id1, int id2, int t){
	// id2 must be target!!!
	Dis d1 = curdis(id1, t);
	Dis d2 = curdis(id2, t);
	d ag1, ag2;
	if(d2.y != d1.y) ag1 = (d)(d2.x - d1.x) / (d)(d2.y - d1.y);
	else ag1 = 0;
	
	if(mst[id1].mdf.y != 0) ag2 = (d)(mst[id1].mdf.x) / (d)(mst[id1].mdf.y);
	else ag2 = 0;
//	if(eql(ag1, ag2)) printf("cha = {%lld, %lld}, a = {%lld, %lld}\n", d2.x - d1.x, d2.y - d1.y, mst[id1].mdf.x, mst[id1].mdf.y);
    if(eql(ag1, ag2) && samefu((d2.x - d1.x), mst[id1].mdf.x)) return 1;
    return 0;
//	return eql(ag1, ag2);
}
//bool lepi(d a1, d a2){
//	return fabsl(a1 - a2) < pi2;
//}
//bool chkvec(int id1, int id2, int t){
//	Dis d1 = curdis(id1, t);
//	Dis d2 = curdis(id2, t);
//	d ag1 = (d)(d2.x - d1.x) / (d)(d2.y - d1.y);
//	d ag2 = (d)(mst[id1].mdf.x) / (d)(mst[id1].mdf.y);
//	return lepi(ag1, ag2);
//}

void solve(){
	for (int _ = 1, t, x, y, j, q; _ <= m; _++){
		scanf("%lld%lld%lld%lld%lld", &t, &x, &y, &j, &q);
		if(die[x]) {
			printf("%.2lf\n", gethp());
			continue;
		}
//		if(chkcm(x, t) && y != 0) {
//			printf("%.2lf\n", gethp());
//			continue;
//		}
//		if(chkjx(x, t) && y == 0) {
//			printf("%.2lf\n", gethp());
//			continue;
//		}
		if(chkxy(x, t)) {
			printf("%.2lf\n", gethp());
			continue;
		}
		if(y == 0){
			d mndis = INF; int mnid = 0;
			for (int i = 1; i <= n; i++){
				if(i == x) continue;
				if(die[i]) continue;
				d ndis = odis(curdis(x, t), curdis(i, t));
				if(mndis > ndis)
					mndis = ndis, mnid = i;
			}
//			printf("mnid = %lld, mndis = %.2lf\n", mnid, mndis);
			if(mnid != 0){
				mst[mnid].h -= (j + q);
				if(chksg(mnid)) rmvsg(mnid);
			}
		}else if(y == 1){
			for (int i = 1; i <= n; i++){
				if(i == x) continue;
				if(die[i]) continue;
				d ndis = odis(curdis(x, t), curdis(i, t));
				mst[i].h -= std::max(0.0, (d)j - (d)q * ndis);
				if(chksg(i)) rmvsg(i);
			}
		}else if(y == 2){
			for (int i = 1; i <= n; i++){
				if(i == x) continue;
				if(die[i]) continue;
				int ndis = mdis(curdis(x, t), curdis(i, t));
				mst[i].h -= std::max(0ll, j - q * ndis);
				if(chksg(i)) rmvsg(i);
			}
		}else if(y == 3){
			for (int i = 1; i <= n; i++){
				if(i == x) continue;
				if(die[i]) continue;
				d ndis = odis(curdis(x, t), curdis(i, t));
				mst[i].h -= std::min((d)j, (d)q * ndis);
				if(chksg(i)) rmvsg(i);
			}
		}else if(y == 4){
			for (int i = 1; i <= n; i++){
				if(i == x) continue;
				if(die[i]) continue;
				d ndis = odis(curdis(x, t), curdis(i, t));
				d eft = (d)j - (d)q * ndis;
				mst[i].h -= std::max(0.0, eft);
				if(chksg(i)) rmvsg(i);
				if(!die[i] && eft > 0){
					if(chkxy(i, t)){
						isxy[i].ed += j;
					}else{
						isxy[i].st = t;
						isxy[i].ed = t + j;
					}
					xy[i] += j;
				}
			}
		}else if(y == 5){
			d mndis = INF; int mnid = 0;
			for (int i = 1; i <= n; i++){
				if(i == x) continue;
				if(die[i]) continue;
                if(mst[x].mdf.x == 0 && mst[x].mdf.y == 0) continue;
				if(!chkdir(x, i, t)) continue;
				d ndis = odis(curdis(x, t), curdis(i, t));
				if(mndis > ndis)
					mndis = ndis, mnid = i;
			}
//			printf("mnid = %lld, mndis = %.2lf\n", mnid, mndis);
			if(mnid != 0){
				d eft = (d)j - (d)q * mndis;
				mst[mnid].h -= std::max(0.0, eft);
				if(chksg(mnid)) rmvsg(mnid);
				if(!die[mnid] && eft > 0){
					if(chkxy(mnid, t)){
						isxy[mnid].ed += j;
					}else{
						isxy[mnid].st = t;
						isxy[mnid].ed = t + j;
					}
					xy[mnid] += j;
				}
			}
		}else if(y == 6){
			
		}else if(y == 7){
			
		}
		printf("%.2lf\n", gethp());
	}
}
signed main(){
    #ifdef ONLINE_JUDGE
    #else
	freopen("/Users/xiexie/Downloads/related_file_S15.23.11.2/9.in", "r", stdin);
	freopen("/Users/xiexie/Downloads/related_file_S15.23.11.2/9.out", "w", stdout);
    #endif
	
	scanf("%lld", &q);
	while(q--){
		scanf("%lld%lld", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%lld%lld%lld%lld%lf", &mst[i].mdf.x, &mst[i].mdf.y, &mst[i].org.x, &mst[i].org.y, &mst[i].h);
		solve();
		print();
		clean(); 
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
