#include <cstdio>
#include <algorithm>
const int N = 1e5 * 2 + 10;
int n;
int H;
struct Node{
	int idx;
	int l;
    int r;
}ad[N];
struct Note{
    int idx;
    int val;
}llist[N], rlist[N];
int llen;
int rlen;
int ansl[N], ansr[N];
int aans[N], pans;
void output(int x){
    // if(ansl[x] == 1 && ansr[x] == 1){
    //     aans[++pans] = x;
    //     // printf("%d ", x);
    //     ansl[x] = ansr[x] = 0;
    // }
    if(ad[x].l >= ad[x].r){
        aans[++pans] = x;
        // ad[x].l = -1e9;
        // ad[x].r = 1e9;
    }
}
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
	scanf("%d%d", &n, &H);
	for (int i = 1; i <= n; i++){
        int lll = read(); int aaa = read();
		ad[i] = (Node){i - 1, lll, lll + aaa};
	}
    
    std::sort(aans + 1, aans + 1 + pans);
    for (int i = 1; i <= pans; i++){
        if(aans[i] == aans[i - 1] && i > 1) continue;
        printf("%d ", aans[i]);
    }
    
	return 0;
}

        // ad[i] = (Node){i - 1, lll, lll + aaa};
        // while(ad[i].r >= rlist[rlen].val && rlen > 0){
        //     ad[rlist[rlen].idx].r = std::min(ad[i].l, ad[rlist[rlen].idx].r);
        //     rlist[rlen--].val = 0;
        //     // ansr[rlist[rlen + 1].idx] = 1;
        //     output(rlist[rlen + 1].idx);
        //     // rlist[rlen + 1].idx = 0;
        // }
        // rlist[++rlen].val = ad[i].r;
        // rlist[rlen].idx = i - 1;
        // while(ad[i].l <= llist[llen].val && llen > 0){
        //     ad[llist[llen].idx].l = std::max(ad[i].r, ad[llist[llen].idx].l);
        //     llist[llen--].val = 0;
        //     // ansl[llist[llen + 1].idx] = 1;
        //     output(llist[llen + 1].idx);
        //     // llist[llen + 1].idx = 0;
        // }
        // llist[++llen].val = ad[i].l;
        // llist[llen].idx = i - 1;
        // // for (int j = 1; j <= n; j++){
        // //     printf("%d ", ans[j]);
        // // }printf("\n");

        // printf("\n");
        // for (int i = 1; i <= n; i++){
        //     printf("%d ", ad[i].l);
        // }printf("\n");
        // for (int i = 1; i <= n; i++){
        //     printf("%d ", ad[i].r);
        // }printf("\n");
        // for (int i = 1; i <= n; i++){
        // 	printf("%d ", llist[i].val);
        // }printf("\n");
        // for (int i = 1; i <= n; i++){
        // 	printf("%d ", rlist[i].val);
        // }printf("\n");