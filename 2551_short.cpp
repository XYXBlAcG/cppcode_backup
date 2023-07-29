#include <iostream>
__uint64_t x,p,m,a;int main(){std::cin>>x>>p>>m;for(;p;x=x*2%m,p/=2)a=p&1?(a+x)%m:a;std::cout<<a;}