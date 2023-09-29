#include <cstdio>
long long N = 3e6, t, a;
int main(){
	while(N--) scanf("%lld", &t), a ^= t;
	printf("%lld\n", a);
    return 0;
}