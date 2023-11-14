#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
typedef long long ll;
const int N = 105;
int T, n, S, num;
struct Pos{
	int x, y;
}pos[N];
struct Node{
	Pos a, b;
}node[N];
bool cmp(Pos a, Pos b){
	if(a.x == b.x) return a.y > b.y;
	return a.x < b.x;
}
bool cmp2(Pos a, Pos b){
    return a.y > b.y;
}
void clean(){
	memset(pos, 0, sizeof(pos));
	memset(node, 0, sizeof(node));
	num = 0;
}
bool chk(Pos x){
	for (int i = 1; i <= num; i++){
		Node z = node[i];
		if(z.a.x <= x.x && z.a.y <= x.y && x.x <= z.b.x && x.y <= z.b.y){
			return 1;
		}
	}
	return 0;
}
int solve(){
	std::sort(pos + 1, pos + 1 + n, cmp);
	for (int i = 1; i <= n; i++){
		Pos x = pos[i];
		if(chk(x)) continue;
		node[++num] = (Node){(Pos){x.x, 0}, (Pos){x.x + S / x.y, x.y}};
	}
	return num;
}
bool dir(){
    for (int i = 1; i <= n; i++){
        
    }
}
int solve2(){
    std::sort(pos + 1, pos + 1 + n, cmp2);
    for (int i = 1; i <= n; i++){
        Pos x = pos[i];
        if(chk(x)) continue;
        
    }
}
int main(){
	// freopen("scene.in", "r", stdin);
	// freopen("scene.out", "w", stdout);
	
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &S);
		for (int i = 1; i <= n; i++){
			scanf("%d%d", &pos[i].x, &pos[i].y);
		}
		printf("%d\n", solve());
		clean();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
