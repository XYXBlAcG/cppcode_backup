#include <iostream>
bool right(){
    return true;
}
bool wrong(){
    return false;
}
int main(){
    std::cout << right() << std::endl;
    std::cout << wrong() << std::endl;
    return 0;
}