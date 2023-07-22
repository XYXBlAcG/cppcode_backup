#include <cstdio>
const int N = 1e6 + 10;
typedef long long ll;
int n;
int h[N];
int a[N];
int cnt;
char list[2010];
int bra[2010];
int col[2010];// red 1 blue 2 no 0
int stk[2010];
int R[2010];
int mod = 1e9 + 7;
int vis[2010][2010];
ll ans[2010][2010]; 
ll f(int a, int b){// a = now, b = past
	if(vis[a][b]) return ans[a][b];
	vis[a][b] = 1;
	
	
	long long ans = 0;
	if(a == cnt) return 1;
	
	if(b == 2) {ans += f(a + 1, 1) + f(a + 1, 0);}
	if(b == 1) {ans += f(a + 1, 0) + f(a + 1, 2);}
	
	return ans[a][b] = ans;
}
int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {  // ch 不是数字时
    if (ch == '-') w = -1;        // 判断是否为负
    ch = getchar();               // 继续读入
  }
  while (ch >= '0' && ch <= '9') {  // ch 是数字时
    x = x * 10 + (ch - '0');  // 将新读入的数字「加」在 x 的后面
    // x 是 int 类型，char 类型的 ch 和 '0' 会被自动转为其对应的
    // ASCII 码，相当于将 ch 转化为对应数字
    // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
    ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}
int main(){
	for (char c = getchar(); c > 32; c = getchar()){
		list[++cnt] = c;
	}
	for (int i = 1; i <= cnt; i++){
		if(list[i] == '('){
			bra[i] = 1;
		}else{
			bra[i] = 0;
		}
	}
	
//	for (int i = 1; i <= cnt; i++){
//		printf("%d ", bra[i]);
//	}
	return 0;
}
