// project 1
#include <cstdio>
#include <algorithm>

struct FileIO{
    FileIO(){
        freopen("file.in", "r", stdin);
        freopen("file.out", "w", stdout);
    }
    ~FileIO(){
        fclose(stdin);
        fclose(stdout);
    }
}IO;

template <typename T>
struct FastIO{
    inline T read() {
        T x = 0, w = 1;
        char ch = 0;
        while (!isdigit(ch)) {
            if (ch == '-') w = -1;
            ch = getchar();
        }
        while (isdigit(ch)) {  
            x = (x << 3) + (x << 1) + (ch - '0'); 
            ch = getchar(); 
        }
        return x * w;  
    }

    inline void out(T& x){
        
    }
};

FastIO<int> intIO;
FastIO<long long> longIO;

int main(){
    int a = intIO.read();
    long long b = longIO.read();
    return 0;
}