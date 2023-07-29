#include <cstdio>
#include <algorithm>
const int N = 1e6 + 10;
int n, m, y;
struct Node{
	int x;
	int v;
	double md;
}me[N];
struct Note{
	int a;
	int b;
}rock[N];
//int w[N];
//int v[N];
//double md[N];
bool cmpd(const Node& a, const Node& b){
	return a.md > b.md;
}
bool cmpt(const Note& a, const Note& b){
	if (a.a == b.a) return a.b > b.b;
	return a.a < b.a;
}
int b[N];
int a[N];
typedef long long ll;
int vis[N][N];
int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') { 
    if (ch == '-') w = -1;       
    ch = getchar();              
  }
  while (ch >= '0' && ch <= '9') {  
    x = x * 10 + (ch - '0');  
    ch = getchar();  
  }
  return x * w;  
}
int main(){
	n = read(); m = read(); y = read();
	for (int i = 1; i <= n; i++){
		me[i].x = read();
	}
	for (int i = 1; i <= n; i++){
		me[i].v = read();
		me[i].md = (double)me[i].x / (double)me[i].v;
	}
	std::sort(me + 1, me + n + 1, cmpd);
	for (int i = 1; i <= m; i++){
		rock[i].a = read();
	}
	for (int i = 1; i <= m; i++){
		rock[i].b = read();
	}
	std::sort(rock + 1, rock + 1 + m, cmpt);
    int l = 1, r = rock[m].a;
	while (l <= r){
		int mid = (l + r) >> 1;
        if (mid == 1){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
	}
	return 0;
}
