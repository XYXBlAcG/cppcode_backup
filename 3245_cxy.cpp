#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
// using namespace std;
using std::string;
using std::vector;
using std::cin;
const int N = 505;
string s1, s2;
int fa1[N], fa2[N];
vector<int> st1[N], st2[N];
int stack[N], top;
string dfs1(int x) {
    if (st1[x].empty()) {
        return "{}";
    }
    std::string ans = "{";
    vector<string> son;
    for (int i = 0; i < (int)st1[x].size(); i++) {
        son.push_back(dfs1(st1[x][i]));
    }
    sort(son.begin(), son.end());
    for (int i = 0; i < (int)son.size(); i++) {
        if (i == 0) {
            ans += son[i];
        } else {
            if (son[i] != son[i - 1])
                ans += son[i];
        }
    }
    ans += "}";
    return ans;
}
string dfs2(int x) {
    if (st2[x].empty()) {
        return "{}";
    }
    string ans = "{";
    vector<string> son;
    for (int i = 0; i < (int)st2[x].size(); i++) {
        son.push_back(dfs2(st2[x][i]));
    }
    sort(son.begin(), son.end());
    for (int i = 0; i < (int)son.size(); i++) {
        if (i == 0) {
            ans += son[i];
        } else {
            if (son[i] != son[i - 1])
                ans += son[i];
        }
    }
    ans += "}";
    return ans;
}
int main() {
    cin >> s1 >> s2;
    top = 0;
    for (int i = 0; i < (int)s1.length(); i++) {
        if (s1[i] == '{') {
            stack[++top] = i;
            if (stack[top - 1] != i)
                st1[stack[top - 1]].push_back(i);
        } else {
            top--;
        }
    }
    top = 0;
    for (int i = 0; i < (int)s2.length(); i++) {
        if (s2[i] == '{') {
            stack[++top] = i;
            if (stack[top - 1] != i)
                st2[stack[top - 1]].push_back(i);
        } else {
            top--;
        }
    }
    if (dfs1(0) == dfs2(0)) {
        putchar('1');
    } else {
        putchar('0');
    }
    return 0;
}