#include <cstdio>
#include <iostream>
#include <string>
int main(){
    std::string str;
    for (int i = 1; i <= 50; i++){
        // std::cin >> str;
        std::getline(std::cin, str);
        // std::cout << "type of " << str << " is " << typeid(str).name() << std::endl;
        printf("std::cout << \"type of \" << (%s) << \" is \" << typeid((%s)).name() << std::endl;\n", str.c_str(), str.c_str());
    }
    return 0;
}