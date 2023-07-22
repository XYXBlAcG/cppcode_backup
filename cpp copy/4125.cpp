#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
using std::swap;
using std::min;
using std::max;
// int x0, x1, x2, y0, y1, y2, dep1, dep2;
struct Node{
    int x, y, z, depth;
    bool operator==(const Node& other) const { return x == other.x && y == other.y && z == other.z; }
}st, ed;
void sort_(int &a, int &b, int &c){
    if(a > b) swap(a, b);
    if(a > c) swap(a, c);
    if(b > c) swap(b, c);
}
int dep = 0;
Node calRoot(Node a, int tmp){
    int step = 0;
    printf("!");
    for (dep = 0; tmp; dep += step){
        int yx = a.y - a.x, zy = a.z - a.y, sm = 0, bg = 0;
        if(yx == zy) return a;
        sm = min(yx, zy); bg = max(yx, zy);
        tmp -= (step = min((bg - 1) / sm, tmp)), a.x += (bg == yx) ? step * sm : 0, a.y += (bg == yx) ? step * sm : -step * sm, a.z += (bg == yx) ? 0 : -step * sm;
    }
    return a;
}
int main(){
    scanf("%d%d%d%d%d%d", &st.x, &st.y, &st.z, &ed.x, &ed.y, &ed.z);
    sort_(st.x, st.y, st.z), sort_(ed.x, ed.y, ed.z);
    printf("!\n"); fflush(stdout);
    Node A = calRoot(st, INF); st.depth = dep;
    Node B = calRoot(ed, INF); ed.depth = dep;
    if(!(A == B)) puts("NO\n");
    else{
        puts("YES\n");
        if(st.depth < ed.depth) swap(st, ed);
        int minus = st.depth - ed.depth, l = 0, r = ed.depth, mid;
        st = calRoot(st, minus);
        while(l < r){
            mid = (l + r) >> 1;
            if(calRoot(st, mid) == calRoot(ed, mid)) r = mid; else l = mid + 1;
        }
        printf("%d\n", l);
    }
    return 0;
}