///max-difference=80
#include <cstdio>
#include <algorithm>

typedef long long lld;
const int N = 1000011;
int n;
lld d[N], tmp[N];
char buff[N * 19];
int pbuff;

void read(lld &a) {
	a = 0;
	char c = buff[pbuff++];
	for (; c <= 32; c = buff[pbuff++]);
	for (; c > 32; c = buff[pbuff++])
		a = a * 10 - '0' + c;
}

void write(lld &a) {
	static char st[23];
	int p = 0;
	for (; a != 0; a /= 10)
		st[p++] = a % 10 + '0';
	for (int i = p - 1; i >= 0; i--)
		buff[pbuff++] = st[i];
}

void init(){
	fread(buff, 1, N * 19, stdin);
	lld t = 0;
	read(t);
	n = t;
	for(int i = 1; i <= n; i++)
		read(d[i]);
}

void msort(){
	//排序范围[1..n]
	lld *curr = tmp;
	lld *last = d;
	for(int step = 1; step <= n; step *= 2){
		for(int lef = 1; lef <= n; lef += 2 * step){
			int mid = std::min(lef + step, n + 1);
			int rig = std::min(mid + step, n + 1);
			//归并区间为[lef..mid)和[mid..rig)
			for(int i = lef, j = mid, p = lef; p < rig;)
				if(i < mid && last[i] < last[j] || j == rig)
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

void output(){
	pbuff = 0;
	for(int i = 1; i <= n; i++){
		write(d[i]);
		buff[pbuff++] = '\n';
	}buff[pbuff]=0;
	fputs(buff, stdout);
}

int main(){
	init();
	msort();
	output();
	return 0;
}
