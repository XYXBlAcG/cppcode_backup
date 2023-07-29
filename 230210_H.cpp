#include <cstdio>
#include <cmath>
int n;
int map[15][15];
int go[15][15];
void gogo(int in, char right, char down, char left, char up){
    if (in == n){
        printf("%c%c%c",right,down,left);
        return;
    }
    // if (in % 2 == 0){
    gogo(in+1,'R','D','L','U');
    printf("D");
    gogo(in+1,'D','R','U','L');
    printf("R");
    gogo(in+1,'D','R','U','L');
    printf("U");
    gogo(in+1,'L','U','R','D');
    // }else{
    // gogo(in+1,'R','D','L','U');
    // printf("D");
    // gogo(in+1,'D','R','U','L');
    // printf("R");
    // gogo(in+1,'D','R','U','L');
    // printf("U");
    // gogo(in+1,'L','U','R','D');
    // }
}
int main(){
    scanf("%d",&n);
    gogo(1,'D','R','U','L');
    return 0;
}

// L → + R F - L F L - F R +
// R → − L F + R F R + F L −
// F ： 向前
// - ： 右转90°
// + ： 左转90°