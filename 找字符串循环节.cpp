#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, s2;
    cin >> s;
    int len = s.length();
    s += s;
    int flag = 0;
    int i = 0, j = 1;
    int n = s.length() / 2;
    while (i < n && j < n)
    {
        int k = 0;
        while (k < n && s[i + k] == s[j + k])
            k++;
        if (k == n) // 长度为n时存在循环节
        {
            flag = 1;
            break;
        }
        if (s[i + k] > s[j + k])
            i += k + 1;
        else
            j += k + 1;
        if (i == j)
            j++;
    }
    if (flag == 1)
    {
        int k = min(i, j);
        for (int l = 0; l < abs(i - j); l++)
            cout << s[k + l];
    }
    else
        cout << "NO" << endl;
}
