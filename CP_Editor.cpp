#include <cstdio>
#include <string>
#include <iostream>
#define p(x) printf("%d\n", x)
const int MAXN = 1e5 + 5;
template <typename T>
struct Queue{
    T data[MAXN]; int l, r;
    void push(T b){data[++r] = b;}
    void pop(){l++;}
    T tail(){return data[l + 1];}
    T head(){return data[r];}
    int size(){return r - l;}
    bool empty(){return r - l;}
    int* begin(){return &data[l + 1];}
    int* end(){return &data[r + 1];}
};
Queue<int> a;
int n, elm;
std::string op;
void solve(){
	std::cin >> op;
	if(op == "push"){
		scanf("%d", &elm);
		a.push(elm);
	}else if(op == "pop"){
		a.pop();
	}else if(op == "head"){
		printf("%d\n", a.head());
	}else if(op == "tail"){
		printf("%d\n", a.tail());
	}else if(op == "all"){
		for (auto v : a){
			printf("%d ", v);
		}putchar('\n');
	}else if(op == "end"){
		puts("exited successfully.");
		exit(0);
	}else{
		puts("invalid argument.");
	}
}
int main(){
	scanf("%d", &n);
	if(n != -1){
		for (int i = 1; i <= n; i++)
			solve();
	}else{
		while(true) solve();
	}
	return 0;
}