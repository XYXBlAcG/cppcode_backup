#include <iostream>
// #include <windows.h>
// #include <conio.h>
#include <ncurses.h>
#include <stdlib.h>
using namespace std;
 
int main() {
    
    int n;
    cout << "请输入点击次数:" << endl;
    cin >> n;
	
	for(int i = 1; i <= n; i++) {
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//按下左键
		Sleep(10);                                   //要给电脑休息的时间，没有也可以，但会更卡！
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//松开左键
	}
    
    return 0;
}
