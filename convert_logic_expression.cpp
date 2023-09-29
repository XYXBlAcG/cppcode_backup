#include <cstdio>
#include <iostream>
#include <string>
const int MAXN = 1e5 + 5;
template <typename T>
struct Stack{
    T data[MAXN]; int pdata;
    void push(T b){data[++pdata] = b;}
    void pop(){if(pdata) pdata--;}
    T operator[](int x){return data[x];}
    T top(){return data[pdata];}
    int size(){return pdata;}
    bool empty(){return pdata;}
    int* begin(){return &data[1];}
    int* end(){return &data[pdata + 1];}
    void add(T x){
        for (int i = 1; i <= pdata; i++) data[i] += x;
    }
};
Stack<int> stack;
std::string input, ans = "";
void solve(){
    // - for ->
    for (int i = 0; i < (int)input.size(); i++){
        char v = input[i];
        if(v == '-'){
            ans.insert(stack.top() + 1, "!");
            
            ans += "||";
            continue;
        }else if(v == '('){
            stack.push(i);
        }else if(v == ')'){
            stack.pop();
        }
        ans += v;
        // std::cout << ans << '\n';
    }
}
int main(){
    // std::cout << start;
    std::cin >> input;
    solve();
    std::cout << ans << '\n';
    return 0;
}