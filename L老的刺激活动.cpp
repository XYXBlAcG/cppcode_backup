#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define EPS 1e-6
const int N = 300 + 5;
typedef long double d;
int n, m, p, q, e[N][N], in[N];
d a[N][N];
void gg(){
	for (int i = 1; i <= n; i++){
		int mx = -1;
		for (int j = i; j <= n; j++)
			if(a[j][i] != 0.0) {
                mx = j;
                break;
            }
		if (mx == -1) continue;
		std::swap(a[i], a[mx]);
        // if(a[i][i] > -EPS && a[i][i] < EPS) return;
		for (int j = 1; j <= n; j++){
			if (i != j){
				d val = a[j][i] / a[i][i];
				for (int k = 1; k <= n + 1; k++)
					a[j][k] -= a[i][k] * val;
			}
		}
	}
    for (int i = 1; i <= n; i++)
        a[i][n + 1] /= a[i][i];
}
struct FileIO{
    FileIO(){
        freopen("exciting.in", "r", stdin);
        freopen("exciting.out", "w", stdout);
    }
    ~FileIO(){
        fclose(stdin);
        fclose(stdout);
    }
}FileIO;
int main(){
    scanf("%d%d%d%d", &n, &m, &p, &q);
    for (int i = 1; i <= m; i++){
        int u = 0, v = 0;
        scanf("%d%d", &u, &v);
        if(u == v) in[v]--;
        e[u][v] = e[v][u] = 1;
        in[u]++, in[v]++;
    }
    a[1][n + 1] = (d)p / (d)q;
    for (int i = 1; i <= n; i++){
        a[i][i] = 1;
        for (int j = 1; j <= n; j++){
            if(e[i][j]){
                a[i][j] -= (1.0 - (d)p / (d)q) / (d)in[j];
            }
        }
    }
    gg();
    for (int i = 1; i <= n; i++){
        printf("%.6Lf\n", a[i][n + 1]);
    }
    return 0;
}