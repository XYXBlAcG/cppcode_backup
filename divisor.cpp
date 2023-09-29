#include <cstdio>
#include <cmath>
#include <map>
#define int long long
int t, a, b, k, ans;
int inv[9][20];
int gcd(int aa, int bb) {return bb ? gcd(bb, aa % bb) : aa; }
void search(int id, int x, int f, int cur){
    int tmp = inv[id][x + 1];
    // printf("id = %lld, x = %lld, f = %lld, cur = %lld, tmp = %lld\n", id, x, f, cur, tmp);
    if(!tmp){
        if(cur == 1) return;
        ans += (b / inv[id][x] - (a - 1) / inv[id][x]) * f;
        // printf("ans = %lld, tmp = %lld, b = %lld, a = %lld\n", ans, inv[id][x - 1], b, a);
        return;
    }
    search(id, x + 1, f, cur), search(id, x + 1, -f, cur * inv[id][x] / gcd(cur, inv[id][x]));
}
signed main(){
	// freopen("divisor.in", "r", stdin);
	// freopen("divisor.out", "w", stdout);

    // inv[1][1] = 1;
    inv[2][1] = 2, 
    inv[3][1] = 3, inv[3][2] = 4, 
    inv[4][1] = 4, inv[4][2] = 6, inv[4][3] = 10, 
    inv[5][1] = 5, inv[5][2] = 6, inv[5][3] = 8, inv[5][4] = 9, inv[5][5] = 14, inv[5][6] = 21, 
    inv[6][1] = 6, inv[6][2] = 8, inv[6][3] = 10, inv[6][4] = 14, inv[6][5] = 44, inv[6][6] = 52, 
    inv[7][1] = 7, inv[7][2] = 8, inv[7][3] = 9, inv[7][4] = 10, inv[7][5] = 12, inv[7][6] = 15, inv[7][7] = 22, inv[7][8] = 33, inv[7][9] = 39, inv[7][10] = 52, inv[7][11] = 55, inv[7][12] = 68, inv[7][13] = 102, inv[7][14] = 114, inv[7][15] = 138;
	scanf("%lld", &t);
	while(t--){
        ans = 0;
		scanf("%lld%lld%lld", &a, &b, &k);
		if(k == 1){
            printf("%lld\n", b - a + 1);
            continue;
        }
        search(k, 1, -1, 1);
        printf("%lld\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
