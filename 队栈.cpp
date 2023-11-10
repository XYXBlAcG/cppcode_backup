#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <deque>
const int N = 1e5 + 5;
int n, a[N], q, cur;
std::deque<int> deq;
std::vector<int> box;
int main(){
	freopen("staqueue.in", "r", stdin);
	freopen("staqueue.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	scanf("%d", &q);
    if(q == 0) {
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	for (int i = 1, op = 0; i <= q; i++){
		op = ch - '0';
		if(op == 1){
			cur++;
			if(cur == n + 1) cur = 1;
			deq.push_back(a[cur]);
		}else if(op == 2){
			int top = deq.front();
			deq.pop_front();
			box.push_back(top);
		}else if(op == 3){
			int top = deq.back();
			deq.pop_back();
			box.push_back(top);
		}else{
			int flag = 0, nonum = 1;
			for (int i = 0; i < (int)box.size(); i++){
				if(box[i] > 0) nonum = 0;
			}
			if(nonum == 1){
				printf("0");
			}else{
				for (int i = 0; i < (int)box.size(); i++){
					if(box[i] == 0 && flag == 0) continue;
					flag = 1;
					printf("%d", box[i]);
				}
			}
			
			box.clear();
			putchar('\n');
		}
		if(i != q) ch = getchar();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
