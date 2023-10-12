#include <cstdio>
#include <random>
namespace xyx{
    std::mt19937 frand(time(0));
    template <typename T>
    T random(T a = 0, T b = 0x7fffffff){
        return (frand() % (b - a + 1)) + a;
    }
};
using namespace xyx;
int main(){
    // freopen("6142_gen.in", "r", stdin);
    // freopen("6142_gen.out", "w", stdout);
    int T = 10;
    printf("%d\n", T);
    for (int i = 1; i <= T; i++){
        int Q = 5e4;
        printf("%d\n", Q);
        for (int i = 1; i <= Q; i++){
            int op = random(1, 2);
            printf("%d ", op);
            if(op == 1){
                int a = random((int)5e8, (int)1e9), b = random((int)5e8, (int)1e9), c = random((int)5e8, (int)1e9);
                printf("%d %d %d\n", a, b, c);
            }else{
                int a = random((int)5e8, (int)1e9), b = random((int)5e8, (int)1e9), c = random((int)5e8, (int)1e9);
                int a1 = random((int)5e8, (int)1e9), b1 = random((int)5e8, (int)1e9), c1 = random((int)5e8, (int)1e9);
                printf("%d %d %d %d %d %d\n", a, b, c, a1, b1, c1);
            }
        }
    }
    return 0;
}