#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#define int long long
const int N = 105, M = 305;
int n, dis[M], vis[M], backx[M], backy[M];
struct Node{
    int x, y, id;
}pos[N], s, tag[M * M];
struct Edge{
    int v, dis;
};
bool cmp(Node a, Node b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
std::vector<Edge> st[M * M]; 
std::map<int, int> xi, yi;
int lisan(int x, int y){
    return x * N + y;
}
struct Heap{
	Edge heap[N * N]; int pheap;
	void push(Edge x){
		heap[++pheap] = x;
		std::push_heap(heap + 1, heap + 1 + pheap, cmp);
	}
	Edge top(){
		return heap[1];
	}
	void pop(){
		std::pop_heap(heap + 1, heap + 1 + pheap--, cmp);
	}
	int size(){
		return pheap;
	}
}t;
// struct FIO{
//     FIO(){
//         freopen("delite.in", "r", stdin);
//         freopen("delite.out", "w", stdout);
//     }
//     ~FIO(){
//         fclose(stdin);
//         fclose(stdout);
//     }
// }fio;
std::vector<Node> po;
std::vector<int> xx, yy;
void dj(int s){
    t.push({s, 0});
    while(t.size()){
        Edge u = t.top(); t.pop();
        for (auto v : st[u.v]){
            
        }
    }
}
signed main(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++){
        int tx, ty;
        scanf("%lld%lld", &tx, &ty);
        pos[i] = {tx, ty, 0};
        xx.push_back(tx - 1), xx.push_back(tx), xx.push_back(tx + 1);
        yy.push_back(ty - 1), yy.push_back(ty), yy.push_back(ty + 1);
        if(i == 1)
            s = {tx, ty};
    }
    std::sort(xx.begin(), xx.end());
    std::sort(yy.begin(), yy.end());
    std::unique(xx.begin(), xx.end());
    std::unique(yy.begin(), yy.end());
    int cnt = 0;
    for (auto v : xx){
        xi[v] = cnt;
        backx[++cnt] = v;
    }
    cnt = 0;
    for (auto v : yy){
        yi[v] = cnt;
        backy[++cnt] = v;
    }
    for (int i = 1; i <= n; i++){
        Node ttmp = {pos[i].x, pos[i].y, 1};
        tag[lisan(pos[i].x, pos[i].y)] = ttmp;
    }
    for (int i = 0; i < xx.size(); i++){
        for (int j = 0; j < yy.size(); j++){
            int ii = i + 1, jj = j + 1;
            if(tag[lisan(ii, jj)].id == 1) continue;
            tag[lisan(ii, jj)] = {xx[i], yy[j], 0};
        }
    }
    for (int i = 0; i < xx.size(); i++){
        for (int j = 0; j < yy.size(); j++){
            for (int k = 0; k < 4; k++){
                int tx = i + "1102"[k] - '1';
                int ty = j + "2011"[k] - '1';
                if(tx < 0 || ty < 0 || tx > xx.size() - 1 || ty > yy.size() - 1){
                    tag[lisan(i + 1, j + 1)] = {tx, ty, xx[tx] - xx[i] + yy[ty] - yy[i]};
                }
            }
        }
    }
    for (int i = 0; i < xx.size(); i++){
        for (int j = 0; j < yy.size(); j++){
            if(i)
        }
    }
    // for (int i = 0; i < xx.size(); i++){
    //     if(i < xx.size() - 1) st[xi[xx[i]]].push_back({xi[xx[i + 1]], std::abs(xx[i + 1] - xx[i])});
    //     if(i) st[xi[xx[i]]].push_back({xi[xx[i - 1]], std::abs(xx[i + 1] - xx[i])});
    // }
    // for (int i = 0; i < yy.size(); i++){
    //     if(i < yy.size() - 1) st[yi[yy[i]]].push_back({yi[yy[i + 1]], std::abs(yy[i + 1] - yy[i])});
    //     if(i) st[yi[yy[i]]].push_back({yi[yy[i - 1]], std::abs(yy[i + 1] - yy[i])});
    // }
    
    
    return 0;
}