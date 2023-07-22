#include <cstdio>
typedef long long ll;
const int N = 1e6 + 10;
const int M = 1e2 + 10;
int n, m;
struct Node{
	char val;
	int pre;
	int nxt;
	int idx;
}doc[N][M];
int cur[N];
int lend[N];
int docn = 1, curn = 1;
int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') { 
    if (ch == '-') w = -1;     
    ch = getchar();           
  }
  while (ch >= '0' && ch <= '9') {  
    x = x * 10 + (ch - '0');  
    ch = getchar();  
  }
  return x * w;  
}
int main(){
	n = read(); m = read();
	for (int i = 1; i <= m; i++){
		char me[12], op[5]; int len = 0; 
		for (char c = getchar(); c > 32; c = getchar()){
			me[++len] = c;
		}
		//switch
		if(me[1] == 's'){
			int x = read();
			cur[docn] = curn;
			docn = x;
			curn = cur[docn];
		}else //type
		if(me[1] == 't'){
			for (char c = getchar(); c > 32; c = getchar()){
				op[1] = c;
			}
			doc[docn][curn].idx = lend[docn];
			doc[docn][++lend[docn]].val = op[1];
			doc[docn][lend[docn]].pre = curn;
			doc[docn][lend[docn]].nxt = doc[docn][curn].nxt;
			doc[docn][doc[docn][curn].nxt].pre = lend[docn];
			doc[docn][curn].nxt = lend[docn];
			curn++;
		}else
		if(me[1] == 'l'){
			if(curn > 1) curn--;
		}else
		if(me[1] == 'r'){
			if(curn < lend[docn]) curn++;
		}else
		if(me[1] == 'h'){
			curn = 1;
		}else
		if(me[1] == 'e'){
			curn = lend[docn];
		}else
		if(me[1] == 'b'){
			if(curn > 1) {
				doc[docn][doc[docn][curn].pre].nxt = doc[docn][curn].nxt;
				doc[docn][doc[docn][curn].nxt].pre = doc[docn][curn].pre;
				curn--; lend[docn]--;
			}
		}else
		if(me[1] == 'd'){
			if(curn < lend[docn]) {
				doc[docn][doc[docn][doc[docn][curn].nxt].nxt].pre = doc[docn][curn].nxt;
				doc[docn][curn].nxt = doc[docn][doc[docn][curn].nxt].nxt;
				lend[docn]--;
			}
		}
		// printf("cur:%d doc:%d\n", curn, docn);
	}		
	for (int i = 1; i <= n; i++){
		for (int j = i, aaa = 1; aaa <= lend[i]; j = doc[i][j].nxt, aaa++){
			printf("%c",doc[i][j].val);
		}printf("\n");
	}
	return 0;
}
