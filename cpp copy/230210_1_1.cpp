#include <iostream>
using namespace std;

int getSum(int n);

int main() {

    int n;
    cin >> n;
    
    cout << getSum(n) << endl; //输出结果

    return 0;
}

int getSum(int n) {
    if(n == 1 || n == 2) //n=1或2跳出递归
        return 1;
    return getSum(n - 1) + getSum(n - 2); //返回前两个月相加
}

