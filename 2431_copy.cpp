#include<cstdio>
#include<queue>
using namespace std;
const int N=300002;
int n;
priority_queue<int> lkynum;
priority_queue<int> de;
struct Passenger {
	int luckynum;
} pas[N];
int ppas,k;
int seat[N];
int main() {
	scanf("%d",&n);
	int op,x,y,deloc;
	for(int i=1; i<=n; i++) {
		scanf("%d",&op);
		if(op==1) {
			scanf("%d",&x);
			lkynum.push(x);
			pas[++ppas].luckynum=x;
			seat[++k]=ppas;
			if(!de.empty()&&!lkynum.empty()){
				while(de.top()==lkynum.top()&&!de.empty()&&!lkynum.empty()){
					de.pop();
					lkynum.pop();
				}
			}
			printf("%d\n",lkynum.top());
		} else {
			if(!de.empty()&&!lkynum.empty()){
				while(de.top()==lkynum.top()&&!de.empty()&&!lkynum.empty()){
					de.pop();
					lkynum.pop();
				}
			}
			deloc=lkynum.top()%k+1;
			printf("%d\n",pas[seat[deloc]].luckynum);
			de.push(pas[seat[deloc]].luckynum);
			seat[deloc]=seat[k];
			seat[k]=0;
			k--;
		}
	}
	return 0;
}
