///max-difference=50
/*
	思路：将填n个数的操作拆解为先填一个数，再填余下n-1个数。
	每次填数的时候，选择和前一个数之和是质数且没有用过的数。
	由于题目是环排列，所以固定第一个数是a[0]，避免重复计算。
	边界时，还要注意检查最后一个数和第一个数之和是否为质数。
*/

#include <cstdio>
/*
	定义变量：保证这一段没有错误，无需修改
*/
const int N = 21, M = 110;
int n, ans;
// a[x]记录第x个数的值（下标0~n-1）
int a[N];
// b[x]记录第x个位置填的数（下标0~n-1）
int b[N];
// isprime[x]为true表示x是质数
bool isprime[M];
// use[x]为true表示第x个数已经被使用（下标0~n-1）
bool use[N];

/*
	dfs(i)：表示当前在枚举第i个位置的填数
*/
void dfs(int i){
	// 边界：注意检查最后一个数和第一个数之和是否为质数
	if(i == n){
		if(isprime[b[n ] + b[0]]){
			++ans;
			return;
		}
	}
	// 填写第i个位置的数：选择和前一个数之和是质数且没有用过的数
	for(int j = 1; j < n; ++j)
		if(!use[j] && isprime[b[i - 1] + a[j]]){
			use[j] = true;
			b[i] = a[j];
			dfs(i + 1);
			b[i] = 0;
		}
}

int main(){
	// 预先算好哪些数是质数：保证这一段没有错误，无需修改
	for(int i = 2; i < M; ++i)
		isprime[i] = true;
	for(int i = 2; i < M; ++i){
		if(!isprime[i])
			continue;
		for(int j = i; j * i < M; ++j)
			isprime[j * i] = false;
	}
	
	// 输入
	scanf("%d", &n);
	for(int i = 0; i <= n; ++i)
		scanf("%d", &a[i]);
	
	// 调用搜索函数，由于是环排列，所以固定把a[0]放在第一个位置，避免重复计算
	b[0] = a[0];
	dfs(1);
	
	printf("%d\n", ans);
}
