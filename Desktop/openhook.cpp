#include <cstdio>
#include <algorithm>
#define int unsigned long long
const int N = 1e6 + 5;
// mod!!!!!
// score/64/100
int n, cnt, kk[N], ans;
bool flaga = 1, flagb = 1;
struct Node{
	int a, b;
}pa[N], tmp[N], tmp2[N];
bool cmp(Node a, Node b){
	return a.b < b.b;
}
bool cmp2(Node a, Node b){
	return a.a < b.a;
}
signed main(){
	// freopen("openhook.in", "r", stdin);
	// freopen("openhook.out", "w", stdout);
	
	scanf("%llu", &n);
	for (int i = 1; i <= n; i++){
		scanf("%llu", &pa[i].a);
		if(i != 1){
			flaga *= (pa[i].a == pa[i - 1].a);
		}
	}
	for (int i = 1; i <= n; i++){
		scanf("%llu", &pa[i].b);
		if(i != 1){
			flagb *= (pa[i].b == pa[i - 1].b);
		}
	}
		
	for (int i = 1; i <= n; i++)
		tmp2[i] = tmp[i] = pa[i];
	std::sort(pa + 1, pa + 1 + n, cmp);
	std::sort(tmp + 1, tmp + 1 + n, cmp2); 
	if(n <= 3){
		if(n == 1){
			printf("0\n");
		}else if(n == 2){
			if(pa[1].a == pa[2].a){
				printf("%llu\n", pa[1].b);
			}else{
				printf("0\n");
			}
		}else if(n == 3){
			bool flag = 0;
			if(pa[1].a == pa[2].a && pa[2].a == pa[3].a){
				printf("%llu\n", pa[1].b * 2 + pa[2].b);
			}else if(pa[1].a == pa[2].a){
				flag = 1;
				// printf("%llu\n", pa[1].b + pa[2].b);
			}else if(pa[2].a == pa[3].a){
				flag = 1;
				std::swap(pa[1].a, pa[3].a);
				// printf("%llu\n", std::min(pa[2].b, pa[3].b));
			}else if(pa[1].a == pa[3].a){
				flag = 1;
				std::swap(pa[2].a, pa[3].a);
				// printf("%llu\n", std::min(pa[1].b, pa[3].b));
			}else{
				printf("0\n");
			}
			if(flag){
				if(pa[1].a + 1 == pa[3].a){
					printf("%llu\n", 2 * pa[1].b);
				}else{
					printf("%llu\n", pa[1].b);
				}
			}
		}
	}else if(flaga){
		ans = 0;
		for (int i = 1; i <= n; i++){
			ans += (pa[i].b) * (n - i);
		}
		printf("%llu\n", ans);
	}else if(flagb){
		int tmpl = 0;
		// for (int i = 1; i <= n; i++){
		// 	tmpl += (i - pa[i].a);
		// }
		
		printf("%llu\n", pa[1].b * tmpl);
	}
	// fclose(stdin);
	// fclose(stdout);
	return 0;
} 
