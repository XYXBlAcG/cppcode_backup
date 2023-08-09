#include <cstdio>
#include <algorithm>
struct Num{
    int zheng, xiao;
};
int leng(int x){
        int cnt = 0;
        if(x == 0) return 1;
        for (; x; cnt++) x /= 10;
        return cnt;
    }
    void samelen(Num &a, Num &b){
        if(leng(a.xiao) > leng(b.xiao)) std::swap(a, b);
        while(leng(a.xiao) ^ leng(b.xiao)) a.xiao *= 10;
    }
    int power(int a, int b){
        int ans = 1;
        for (int i = 1; i <= b; i++){
            ans *= a;
        }
        return ans;
    }
    Num add(Num a, Num b){
        samelen(a, b);
        int xiaos = a.xiao + b.xiao, tmp = xiaos, zhengs = a.zheng + b.zheng;
        if(leng(xiaos) > std::max(leng(a.xiao), leng(b.xiao))){
            for (int i = 1; i < leng(xiaos); i++){
                tmp /= 10;
            }
            zhengs += tmp;
        }
        return (Num){zhengs, xiaos};
    }
    Num sub(Num a, Num b){
        samelen(a, b);
        int xiaos = a.xiao - b.xiao, tmp = xiaos, zhengs = a.zheng - b.zheng;
        if(xiaos < 0){
            zhengs--;
            xiaos += power(10, leng(xiaos) + 1);
        }
        return (Num){zhengs, xiaos};
    }
    Num time(Num a, Num b){
        samelen(a, b);
        int xiaos = a.xiao * b.xiao, tmp = xiaos, zhengs = a.zheng * b.zheng;
        
    }
int main(){

    return 0;
}