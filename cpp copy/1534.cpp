#include <cstdio>
int n = 0;
void dfs(char c, int m){
    
	for(int i = 1; i <= m; i++){
		putchar('.');
    }
	putchar(c);
	putchar('\n');
	if(m != n) {
		if(c == 'r'){
			dfs('R', m + 1);
		}else{
			dfs('r', m + 1);
            dfs('R', m + 1);
		}
        return;
    }
}

int main(){
	scanf("%d", &n);
	dfs('r', 0);
	return 0;
}
