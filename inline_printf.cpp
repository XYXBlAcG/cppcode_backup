#include <cstdio>
#include <string>
using std::string;
int printf(string a){
    return printf("%s", a.c_str());
}
int printf(long long x){
    return printf("%lld\n", x);
}
int printf(...){
    printf("Wrong Arg. exit.");
    exit(0);
}