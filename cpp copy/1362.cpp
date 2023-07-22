#include <iostream>
int main(){unsigned long long x,p,m,a=0;std::cin>>x>>p>>m;for(;p;x=x*2%m,p>>=1)a=p&1?(a+x)%m:a;std::cout<<a;}