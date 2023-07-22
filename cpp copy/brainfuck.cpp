#include <iostream>
using namespace std;
string translate(char c)
{
    switch (c)
    {
    case '>':
        return "p++";
    case '<':
        return "p--";
    case '+':
        return "*p = *p + 1";
    case '-':
        return "*p = *p - 1";
    case '.':
        return "cout<<char(*p)";
    case ',':
        return "*p=getchar()";
    case '[':
        return "while(*p){";
    case ']':
        return "}";
    default:
        return "";
    }
}
 
 
int main()
{
    char c;
    while (cin >> c) {
        cout << translate(c);
        if (c != '[')cout << ";\n";
    }
    return 0;
} 
