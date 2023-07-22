#include<cstdio>
#include <iostream>
#define deb(x) std::cout << #x << " = " << x << std::endl
const int N=1<<21;
int n;
double a[21],b[21];
unsigned U;
double suma[N],sumb[N];
bool vis[N];
double rec[N];
double f(unsigned s){
    if(s==0) return 0;
    if(vis[s]) return rec[s];
    vis[s]=true;
    double sum=0;
    for(int i=0;i<n;i++){
        if((s>>i)&1){
            double p=a[i]/suma[s],val=b[i]/sumb[s];
            sum+=p*(val+f(s&(~(1<<i))));
        }
    }
    return rec[s]=sum;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%lf",&b[i]);
    }
    U=(1<<n)-1;
    for(unsigned s=0;s<=U;s++){
        sumb[s]+=1;
        for(int i=0;i<n;i++){
            if((s>>i)&1) suma[s]+=a[i];
            if(!((s>>i)&1)) sumb[s]+=b[i];
        }
        deb(s), deb(suma[s]), deb(sumb[s]);
    }

    printf("%lf\n",f(U));
    return 0;
}