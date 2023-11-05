#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
const int mod = 10007;
int n, m;
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}
bool isp(int x){
    for (int i = 2; i * i <= x; i++){
        if(x % i == 0) return 0;
    }
    return 1;
}
int get(int x){
    int cnt = 0;
    for (int i = 1; i * i <= x; i++){
        if(x % i == 0){
            if(i * i == x) cnt++;
            else cnt += 2;
        }
    }
    return cnt;
}
namespace pt25{
	std::vector<int> num;
	int getans(){
		int gc = 0;
		for (int i = 0; i < (int)num.size(); i++){
			gc = gcd(gc, num[i]);
		}
//		printf("gc = %lld\n", gc);
		return get(gc);
	}
	int qry(int x){
		if(x == n + 1) {
			return getans();
		}
		int ans = 0;
		for (int i = 1; i <= m; i++){
			num.push_back(i);
			ans += qry(x + 1);
			ans %= mod;
			num.pop_back();
		}
		return ans;
	}
	void main(){
        // printf("n = %lld, m = %lld\n", n, m);
		printf("%lld, ", qry(1));
	}
};
namespace pt20 {
    int res = 0;
    void main() {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                (res += get(gcd(i, j))) %= mod;
            }
        }
        printf("%lld\n", res);
    }
} 
signed main(){
    // for (int i = 1; i <= 1000; i++){
    //     n = 2, m = i;
    printf("mp[11][11] = {");
    for (int i = 1; i <= 10; i++){
        printf("{");
        for (int j = 1; j <= 10; j++){
            n = i, m = j;
            pt25::main();
        }
        printf("}, \n");
    }
    printf("};");
    // }
    
    return 0;
}