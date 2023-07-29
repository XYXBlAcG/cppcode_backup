#include <cstdio>
#include <algorithm>
#include <math.h>
typedef double ld;
using std::abs;
using std::max;
using std::min;
ld lx;
ld rx;
ld ly;
ld ry;
ld v1, v2;
ld EPS = 1e-3;
struct Node
{
    ld x;
    ld y;
}pos[3];
ld po(ld x){
    return x * x;
}
ld cal(ld x){
    ld y = 0;
        y = (ly - ry) / (lx - rx) * x + 
        ry - rx * (ly - ry) / (lx - rx);
    ld a = sqrt(po(x - pos[0].x)
            + po(y - pos[0].y));
    ld b = sqrt(po(x - pos[2].x)
    + po(y - pos[2].y));
    return a / v1 + b / v2;
}
ld cal2(ld y){
    ld a = abs(y - ly);
    ld b = sqrt(po(lx - pos[2].x) + po(y - pos[2].y));
    return a / v1 + b / v2;
}
int main(){
    for (int i = 0; i < 3; i++){
        scanf("%lf%lf", &pos[i].x, &pos[i].y);
    }scanf("%lf%lf", &v1, &v2);
    lx = min(pos[0].x, pos[1].x);
    rx = max(pos[0].x, pos[1].x);
    ly = min(pos[0].y, pos[1].y);
    ry = max(pos[0].y, pos[1].y);
    ld mid = 0;
    ld lx2 = lx, rx2 = rx;
    ld mid1 = 0, mid2 = 0;
    if(rx2 != lx2){
        while(rx2 - lx2 > 1e-6){
            mid1 = (-lx2 + rx2) * 0.49 + lx2;
            mid2 = (-lx2 + rx2) * 0.51 + lx2;
            if(cal(mid1) - cal(mid2) < 0){
                rx2 = mid2;
            }else{
                lx2 = mid1;
            }
        }
        printf("%.6lf\n", cal(lx2));
    }else{
        ld ry2 = ry, ly2 = ly;
           while(ry2 - ly2 > 1e-6){
            mid1 = (-ly2 + ry2) * 0.49 + ly2;
            mid2 = (-ly2 + ry2) * 0.51 + ly2;
            if(cal2(mid1) - cal2(mid2) < 0){
                ry2 = mid2;
            }else{
                ly2 = mid1;
            }
        }
        printf("%.6lf\n",cal2(ly2));
    }
    return 0;
}