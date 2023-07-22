#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
const int N = 4e5 + 5;
typedef long long ll;
struct Edge{int v; ll w; int id;};
struct Node{int idx;ll dep,val;};
bool operator<(const Node& a, const Node& b){
    if(a.val != b.val)return a.val > b.val;
    return a.dep > b.dep;
}
std::priority_queue<Node> heap;
int n, k, cnt, sts[N*2];
std::vector<Edge> st[N * 2];
std::vector<int> ans[N*2];
inline long long read(){
	long long num=0,f=1;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar()){
		if(c=='-') f=-1;
	}
	for(;c>='0'&&c<='9';c=getchar()){
		num=num*10+c-'0';
	}
	return num*f;
}
int F[20];
inline void print(int x){
	if(!x){
		putchar('0');
		putchar(' ');
		return;
	}
    int cnt = 0;
    while (x > 0) {
        F[cnt++] = x % 10 + '0';
        x /= 10;
    }
    while (cnt > 0) putchar(F[--cnt]);
    putchar(' ');
    return;
}
void output(int u, int len){
    if(st[u].empty()){
        for (int i = 1; i <= len; i++){
            ans[u].push_back(sts[i]);
        }
        return;
    }else{
        for (auto v : st[u]){
            sts[len + 1] = v.id;
            output(v.v, len + 1);
        }
    }
}
int main(){
    scanf("%d%d", &n, &k); 
    for (int i = 1; i <= n; i++){
        heap.push((Node){i, 1,read()});
    }
    int we = n;
    while(((n - 1) % (k - 1)) != 0){
        heap.push((Node){++n,1, 0});
    }
    cnt = n + 1;
    while(heap.size() > 1){
        // printf("!"); fflush(stdout);
        ll tsum = 0, mdep = 0;
        for (int i = 0; i < k; i++){
            if(heap.empty()) break;
            tsum += heap.top().val;
            mdep = std::max(mdep,heap.top().dep);
            st[cnt].push_back((Edge){heap.top().idx, heap.top().val, i});
            // printf("%d -> %d %lld %d\n", cnt, heap.top().idx, heap.top().val, i);
            heap.pop();
        }
        if(heap.empty()) break;
        // printf("cnt:%d \n", cnt);
        heap.push((Node){cnt++,mdep,tsum});
    }
    output(cnt, 0);
    for (int i = 1; i <= n; i++){
        // printf("%d ", (int)ans[i].size());
        print((int)ans[i].size());
        for (auto v : ans[i]){
            // printf("%d ", v);
            print(v);
        }putchar('\n');
    }
    return 0;
}