#include <cstdio>
unsigned long long a = 1 << 64, b = 1 << 65, c = 1 << 63, d = 18446744073709551616
;
int main(){
	printf("%llu %llu %llu %llu\n", a, b, c, d + 114514);
	return 0;
}
