#include <cstdio>
#include <algorithm>
#include <map>
#define int long long
const int N = 105;
int n;
struct Node{
    int x, y, id, to;
}pos[N], st;
bool hcmp(Node a, Node b){
    return a.to < b.to;
}
struct Heap{
	Node heap[N * N]; int pheap;
	void push(Node x){
		heap[++pheap] = x;
		std::push_heap(heap + 1, heap + 1 + pheap, hcmp);
	}
	Node top(){
		return heap[1];
	}
	void pop(){
		std::pop_heap(heap + 1, heap + 1 + pheap--, hcmp);
	}
	int size(){
		return pheap;
	}
}t;
bool cmp(Node a, Node b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
bool cmp2(Node a, Node b){
    return a.id < b.id;
}
struct FIO{
    FIO(){
        freopen("delite.in", "r", stdin);
        freopen("delite.out", "w", stdout);
    }
    ~FIO(){
        fclose(stdin);
        fclose(stdout);
    }
}fio;
signed main(){
    scanf("%lld", &n);
    for (int i = 0; i < n; i++){
        int tx, ty;
        scanf("%lld%lld", &tx, &ty);
        if(i)
            pos[i] = {tx, ty};
        else
            st = {tx, ty};
        
    }
    
    return 0;
}