#include <cstdio>
template<typename T>
void read(T& x) {
    T w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    x *= w;
}
template<typename T>
void fin(T& cur){cur = 0, read(cur);}
template<typename T, typename... Args>
void fin(T& cur, Args&... args){
    cur = 0;
    read(cur);
    if(sizeof...(args) > 0){
        fin(args...);
    }
}
// fast output
template<typename T>
void write(T x) {
    T sta[40];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48);
}
template<typename T>
void fout(T cur){write(cur); }
template<typename T, typename... Args>
void fout(T cur, Args... args){
    write(cur);
    if(sizeof...(args) > 0){
        fout(args...);
    }
}
int main(){
    int a, b, c, d, e, f, g;
    fin(a, b, c, d, e, f, g);
    a++, b++, c++, d++, e++, f++, g++;
    fout(a, b, c, d, e, f, g);
    return 0;
}