#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <deque>
#include <iostream>
#include <cstring>
#define INF 0x3f3f3f3f
const int N = 1e3 + 5;
int n, m, ans = INF, rec[N][N][6];
bool vis[N][N][6];
std::string ma[N];
struct Pos{
	int x, y, dir, ene;
	bool operator==(Pos a) const{
		return a.x == x && a.y == y;
	}
}st, ed;
int ph[N][N];
std::deque<Pos> que;
bool chk(Pos x){
	return x.x < 1 || x.y < 1 || x.x > n || x.y > m || ph[x.x][x.y] == 1;
}
void bfs(){
	que.push_back({st.x, st.y, 5, 0});
	while(que.size()){
		Pos top = que.front(); que.pop_front();
        if(chk(top)) continue;
		if(top == ed){
			ans = std::min(ans, top.ene);
			continue;
		}
        if(vis[top.x][top.y][top.dir]) continue;
        vis[top.x][top.y][top.dir] = 1;
		for (int i = 0; i < 4; i++){
			int tx = top.x + "0211"[i] - '1';
			int ty = top.y + "1102"[i] - '1';
            
			if(i == top.dir || top.dir == 5) que.push_front({tx, ty, i, top.ene});
			else que.push_back({tx, ty, i, top.ene + 1});
		}
	}
}
int main(){
    #ifdef ONLINE_JUDGE
        freopen("turn.in", "r", stdin);
        freopen("turn.out", "w", stdout);
    #else
    #endif
	memset(rec, INF, sizeof(rec));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		std::cin >> ma[i];
		for (int j = 1; j <= m; j++){
			if(ma[i][j - 1] == '#'){
				ph[i][j] = 1;
			}else if(ma[i][j - 1] == '.'){
				ph[i][j] = 0;
			}else if(ma[i][j - 1] == 'X'){
				ph[i][j] = 0;
				st = {i, j, 0, 0};
			}else if(ma[i][j - 1] == 'M'){
				ph[i][j] = 0;
				ed = {i, j, 0, 0};
			}
		}
	}
	bfs();
	printf("%d\n", ans);
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
