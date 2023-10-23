#include <iostream>
main(){__int64_t x,p,m,a=1;std::cin>>x>>p>>m;for(;p;x=x*x%m,p/=2)a=p&1?a*x%m:a;std::cout<<a;}