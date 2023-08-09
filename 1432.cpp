#include <cstdio>
#include <iostream>
#include <string>
int main(){
double az = 0;
std::string azz;
for (int i = 1; i <= 15; i++){
    scanf("%lf", &az);
    printf("%.70f\n", az);
    // std::cin >> azz;
    // // printf("%ld\n", azz.size());
    // if(azz.size() > 64) printf("0"); else printf("1");
}

}