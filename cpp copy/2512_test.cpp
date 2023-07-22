#include <cstdio>
#include <algorithm>
// const int N = 0;
int n;
int d[1000000];
int tmp[1000000];
void msort(){
	//排序范围[1..n]
	int *curr = tmp;
	int *last = d;
	for(int step = 1; step <= n; step *= 2){
		for(int lef = 1; lef + step <= n; lef += 2 * step){
			int mid = lef + step;
			int rig = std::min(mid + step, n + 1);
			//归并区间为[lef..mid)和[mid..rig)
			for(int i = lef, j = mid, p = lef; p < rig;)
				if(j == rig || i < mid && last[i] < last[j] )
					curr[p++] = last[i++];
				else
					curr[p++] = last[j++];
		}
		std::swap(curr, last);
	}
	if(last != d)
		for(int i = 1; i <= n; i++)
			d[i] = last[i];
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
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        d[i] = read();
    }
    msort();
    for (int i = 1; i <= n; i++){
        printf("%d\n",d[i]);
    }
    return 0;
}