// #include <cstdio>
// int n;
// char list[10000];
// void dot(int in){
//     for (int i = 1; i <= in; i++){
//         printf(".");
//     }
// }
// //大兔子为1，小兔子为0
// void dfs(int in){
//     if (in == 0){
//         printf("r\n");
//         return;
//     }
//     if (in == 1){
//         printf("r\n.R\n");
//         return;  
//     }
//     if (in == 2){
//         printf("r\n.R\n..r\n..R\n");
//     }
//     if (in < 0){
//         return;
//     }
//     // dot(in-3);
//     dfs(1);
//     // dot(in-2);
//     // printf("r\n.R");
//     for (int i = n; i > 0; i--){
//         dfs(i);
//         printf("R\n");
//     }
//     // dfs(in-2);
//     // printf("R\n");
//     // // dot(in-1);
//     // dfs(in-3);
//     // printf("R\n");
//     // // dot(in-1);
//     // dfs(in-4);
//     // printf("R\n");
//     // dfs(in-5);
//     // printf("R\n");
//     }
// int main(){
//     scanf("%d",&n);
//     dfs(n-1);
//     return 0;
// }


#include <cstdio>

int n;

int dfs(char c, int m){
	for(int i = 1; i <= m; i++)
		putchar('.');
	// putchar('\n');
	putchar(c);
	putchar('\n');
	if(m != n) {
		if(c == 'r'){
			dfs('R', m + 1);
            dfs('r', m + 1);
		}else{
			dfs('r', m + 1);
		}
	}
}

int main(){
	scanf("%d", &n);
	dfs('r', 1);
	return 0;
}
