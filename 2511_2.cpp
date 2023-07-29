#include <cstdio>
#include <algorithm>
const int N = 1000;
int a[N];
int cnt;
int count;
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

int main(){
    // for (int i = 1; i <= 1000; i++){
    //     scanf("%d ",&a[i]);
    // }
    // // qsortm(1 , 1000);
    // for (int i = 1; i <= 1000; i++){
    //     printf("%d ",a[i]);
    // }
    for (int i = 1; i <= 1000; i++){
        
    }


    return 0;
}