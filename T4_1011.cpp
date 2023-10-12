#include <cstdio>
#include <algorithm>
const int N = 1e5 + 5;
int T, n, m, a[N], b[N], cnt[N], lan[N];
int main(){
	freopen("internationalization.in", "r", stdin);
	freopen("internationalization.out", "w", stdout);
	
	scanf("%d", &T);
	while(T--){
		int sum = 0, all = 0;
		scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++) lan[i] = 0, cnt[i] = 0;
		for (int i = 1; i <= n; i++){
			scanf("%d", a + i);
		}
		for (int i = 1; i <= n; i++){
			scanf("%d", b + i);
			sum += b[i];
			lan[a[i]]++;
			if(b[i]){
				cnt[a[i]]++;
			}
		}
		if(sum == 0){
			puts(">-<");
			continue;
		}
		for (int i = 1; i <= m; i++){
			if(cnt[i] > 0) all++;
		}
		if(all > 1){
			puts("^v^");
			continue;
		}else{
			for (int i = 1; i <= m; i++){
				if(cnt[i] > 0){
					if(cnt[i] == lan[i]){
						printf("%d\n", i);
					}else{
						puts("^v^");
					}
					break;
				}
			}
		}
		
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
