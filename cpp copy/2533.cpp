#include <cstdio>
#include <algorithm>
const double EPS2 = 1e-4;
double b, c, d;
double calu(double x){
    return (x * x * x 
            + x * x * b
            + x * c
            + d);
}
int main(){
    scanf("%lf%lf%lf", &b, &c, &d);
    int all = 0;
    for (int i = -100; i < 100; i++){
        double l = i;
        double r = i + 1;
        double a = calu(l);
        if(a < EPS2 && a > -EPS2){
            ++all;
            printf("%.8lf\n", l);
        }
        if(calu(l) * calu(r) < 0){
            double mid = 0;
            while(r - l >= EPS2){
                mid = (l + r) * 0.5;
                if(calu(mid) * calu(r) < 0){
                    l = mid;
                }else {
                    r = mid;
                }
            }
            printf("%.8lf ", mid);++all;
        }
        if(all == 3) break;
    }
   
    return 0;
}
