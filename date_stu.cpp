#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using std::string;
using std::vector;
bool cmp(string a, string b){
    return a < b;
}
int main(){
    string date;
    int i, j, y;
    char buff[9];
    vector <string> str;
    for (i = 1; i <= 31; i++)
        for (j = 1; j <= 12; j++){
            if (i > 29 && j == 2)
                continue;
            else if (i == 31 && (j == 4 || j == 6 || j == 9 || j == 11))
                continue;
            y = (i % 10) * 1000 + (i / 10) * 100 + (j % 10) * 10 + j / 10;
            if (i == 29 && j == 2 && !((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
                continue;
            sprintf(buff, "%04d%02d%02d", y, j, i);
            str.push_back(buff);
        }
    sort(str.begin(), str.end(), cmp);
    std::cin >> date;
    for (i = 0; i < str.size(); i++)
        if (date < str[i]){
            std::cout << str[i] << "\n";
            for (j = i; j < str.size(); j++)
                if (str[j][0] == str[j][2] && str[j][1] == str[j][3]){
                    std::cout << str[j] << "\n";
                    break;
                }
            break;
        }
    return 0;
}