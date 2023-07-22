#include <cstdio>
#include <algorithm>
const int N = 1e6 + 10;
int n;
int H;
struct Node{
	int idx;
	int h;
	int a;
}ad[N];
int line[N];
int full[N];
int ans[N], pans;
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
	scanf("%d%d", &n, &H);
	for (int i = 1; i <= n; i++){
		ad[i] = (Node){i - 1, read(), read()};
	}
	for (int i = 1; i <= H; i++){
		line[ad[i].h] += ad[i].idx;
		line[ad[i].h + ad[i].a + 1] -= ad[i].idx; 
	}
	for (int i = 1; i <= H; i++){
		full[i] = full[i - 1];
		if(full[i - 1] <= line[i])
			full[i] += line[i];
	}
	// printf("!");
	printf("H:%d \n", H);
	for (int i = 1; i <= H; i++){
		printf("%d ", full[i]);
	}printf("\n");
	std::sort(full + 1, full + 1 + H);
	for (int i = 1; i <= H; i++){
		if(full[i - 1] != full[i]){
			ans[++pans] = full[i];
		}
	}
	for (int i = 1; i <= pans; i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
