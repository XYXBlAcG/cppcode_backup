#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
int qp(int a, int b, int mod){
    int ans = 1;
    while(b){
        if(b & 1) (ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}

signed main(){
    // printf("%lld\n", qp(1145141919810, 227903996, 19260817));
    printf("%lld\n", qp(1145141919810, 227903996, 19260817));
    return 0;
}

// #include <cstdio>
// #include <map>
// #include <cmath>
// using namespace std;
// long long a,b,p;
// long long power(long long a, long long b, long long c) {//快速幂
//     if(b==0)
//         return 1%c;
//     long long ans=1,t=a;
//     while(b>0) {
//        if(b%2==1) ans=ans*t%c;
//        b/=2; t=t*t%c;
//     }
//     return ans;
// }
// long long bsgs(long long a,long long b,long long p) {//bsgs
// 	map<long long,long long> hash; hash.clear();//建立一个Hash表
// 	b%=p;
// 	long long t=sqrt(p)+1;
// 	for(long long i=0;i<t;++i)
// 		hash[(long long)b*power(a,i,p)%p]=i;//将每个j对应的值插入Hash表
// 	a=power(a,t,p);
// 	if(!a) return b==0?1:-1;//特判
// 	for(long long i=1;i<=t;++i) {//在Hash表中查找是否有i对应的j值
// 		long long val=power(a,i,p);
// 		int j=hash.find(val)==hash.end()?-1:hash[val];
// 		if(j>=0&&i*t-j>=0) return i*t-j;
// 	}
// 	return -1;//无解返回-1
// }
// signed main() {
// 	scanf("%lld%lld%lld",&p,&a,&b);
// 	long long ans=bsgs(a,b,p);
// 	if(ans==-1) printf("no solution\n");
// 	else printf("%lld\n",ans);
// 	return 0;
// }
