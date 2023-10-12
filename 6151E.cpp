#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#define pi acos(-1.0)
typedef double d;
const int N = 5e5 + 5;
int n; d ans = 1e18;
struct Node{d x, y;}pos[N];
bool cmp(Node a, Node b){return a.x < b.x;}
d dis(Node a, Node b){return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);}
void cal(){
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= std::min(i + 5, n); j++)
            ans = std::min(ans, dis(pos[i], pos[j]));
}
void c(d angle){
    d an = angle / 180.0 * pi;
    for (int i = 1; i <= n; i++){
        d x = pos[i].x, y = pos[i].y, xx = x * cos(an) - y * sin(an), yy = x * sin(an) + y * cos(an);
        pos[i] = {xx, yy};
    }
    std::sort(pos + 1, pos + 1 + n, cmp);
    cal();
}
int main(){
    srand(114514);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf", &pos[i].x, &pos[i].y);
    c(0.0), c(rand() % 360), c(rand() % 360);
    printf("%d\n", (int)round(ans));
    return 0;
}