#include <cstdio>
int n;
const int N = 1e6 + 3;
// struct Note
// {
//     int top, bottom;
//     // unsigned long long pre;
//     unsigned long long nxt;
//     unsigned long long m;
// }id[N], score[N];
unsigned long long id[N];
unsigned long long score[N];

// int 
void swap(unsigned long long p,unsigned long long q)
{
    unsigned long long temp;
    temp = p;
    p = q;
    q = temp;
}
unsigned long long part(unsigned long long r[], int low, int hight){
    int i = low, j = hight, pivot = r[low]; 
	while (i < j)
	{
		while (i<j && r[j]>pivot) 
		{
			j--;
		}
		if (i < j)
		{
            i++;
			swap(r[i], r[j]);  
		}
		while (i < j && r[i] <= pivot) 
		{
			i++;
		}
		if (i < j)
		{
            j--;
			swap(r[i], r[j]);  
		}
	}
	return i; 

}
void soot(unsigned long long r[], int low, int hight){
    int mid;
	if (low < hight)
	{
		mid = part(r, low, hight);  
		soot(r, low, mid - 1); 
		soot(r, mid+1, hight); 
	}

}


int tot;

int main(){
    scanf("%d",&n);
    for (int i = 1 ; i <= n; i++){
        scanf("%llu%llu", &id[i], &score[i]);
    }

    soot(score, 0, n - 1);
    // soot(id, 0, n - 1);

    for (int i = 1; i <= n; i++){
        printf("%llu %llu\n", id[i], score[i]);
    }
    return 0;
}

