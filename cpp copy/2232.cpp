#include <cstdio>
int x, y, n, m;
unsigned long long f1[1010][1010];
bool vis[1010][1010];
int ans;
int sum(int in){
    int sum1 = 0;
    for (; in > 0;){
        sum1 += in % 10;
        in /= 10;
    }
    return sum1;
}
unsigned long long f(int i, int j){
    if (j == 0){
        if (i == y){
            return 1;
        }else{
            return 0;
        }
    }
    if(i > m)return 0;
    if(vis[i][j])return f1[i][j];
    vis[i][j] = true;
    int fl = 0;
    //1
    for (int t = 0; t < 7; t++){
            fl += f(7 * i + t, j - 1);
            fl %= 1000000007;
    }
    //2
        fl += f(sum(i), j - 1);
        fl %= 1000000007;

    return f1[i][j] = fl;
}
int main(){
    scanf("%d%d%d%d", &x, &y, &n, &m);
    printf("%llu",f(x,n));
    return 0;
}