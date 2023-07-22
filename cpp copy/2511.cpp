#include <cstdio>
#include <algorithm>
const int N = 1e3 + 10;
int n;
int count;
int a[N];
void bsort(int l, int r){
	for(int i = r; i >= l; --i){
		bool flag = false;
		for(int j = l; j < i; ++j){
			++count;
			if(a[j] > a[j + 1]){
				std::swap(a[j], a[j + 1]);
				flag = true;
			}
		}
		if(!flag)
			break;
	}
}
void isort(int l, int r){
	for(int i = l; i <= r; ++i)
		for(int j = i; j > l && a[j] < a[j - 1]; --j){
			++count;
			std::swap(a[j], a[j - 1]);
		}
}
void qsortf(int l, int r){
	if(l >= r) return;
	int pivot = a[l];
	int i = l, j = r;
	while(i <= j){
		while(a[j] > pivot && i <= j){
			--j; ++count;
		}
		while(a[i] < pivot && i <= j){
			++i; ++count;
		}
		if(i <= j){
			std::swap(a[i], a[j]);
			++i; --j;
		}
	}
	qsortf(l, j);
	qsortf(i, r);
}
void qsortm(int l, int r){
	if(l >= r) return;
	int pivot = a[(l + r) / 2];
	int i = l, j = r;
	while(i <= j){
		while(a[j] > pivot && i <= j){
			--j; ++count;
		}
		while(a[i] < pivot && i <= j){
			++i; ++count;
		}
		if(i <= j){
			std::swap(a[i], a[j]);
			++i; --j;
		}
	}
	qsortm(l, j);
	qsortm(i, r);
}

inline int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {  // ch 不是数字时
        if (ch == '-') w = -1;        // 判断是否为负
        ch = getchar();               // 继续读入
    }
    while (ch >= '0' && ch <= '9') {  // ch 是数字时
        x = x * 10 + (ch - '0');  // 将新读入的数字’加’在 x 的后面
        // x 是 int 类型，char 类型的 ch 和 ’0’ 会被自动转为其对应的
        // ASCII 码，相当于将 ch 转化为对应数字
        // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
        ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}
int main(){
    for(int i = 1; i <= 1000; i++){
        a[i] = read();
    }
    qsortf(1, 1000);
    printf("%d ",count);
    return 0;
}