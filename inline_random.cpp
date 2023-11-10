#include <cstdio>
#include <random>
#include <iostream>
#include <ctime>
#include <unordered_map>
#include <algorithm>
namespace xyx{
    std::mt19937 frand(time(0));
    /*
    使用方法:
    random(type 下界, type 上界)
    */
    template <typename T>
    T random(T a = 0, T b = 0x7fffffff){
        return (frand() % (b - a + 1)) + a;
    }
    /*
    使用方法:
    randA(int 随机排列的元素个数)
    this part is from oi.wiki
    */
    template <size_t Size>
    void randA(int n){
        printf("%d\n", n);
        std::vector<int> v = {};
        for (int i = 1; i <= n; i++)
            v.push_back(i);
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(v.begin(), v.end(), g);
        std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
        putchar('\n');
    }
    
    template <size_t Size = (unsigned int)(1e5 + 10)>
    struct MakeTree{
        private:
            int fa[Size];
            void init(int n){
                for (int i = 1; i <= n; i++) fa[i] = i;
            }
            int find(int a){
                return fa[a] == a ? a : fa[a] = find(fa[a]);
            }
            bool same(int a, int b){
                return find(a) == find(b);
            }
            void merge(int a, int b){
                a = find(a), b = find(b);
                fa[a] = b;
            }
        public:
            /*
            使用方法:
            makeTree(int 点数, int 起点, bool 是否启用随机边权, int 随机数下界, int 随机数上界)
            */
            void makeTree(int n, int st, int randVal = 0, int randL = 0, int randR = 0){
                init(n);
                for (int i = 1; i < n; i++){
                    int a = random(st, n - 1 + st), b = random(st, n - 1 + st);
                    while(same(a, b)) a = random(st, n - 1 + st), b = random(st, n - 1 + st);
                    merge(a, b);
                    printf("%d %d", a, b);
                    if(randVal) printf(" %d", random(randL, randR));
                    putchar('\n');
                }
            }
            /*
            使用方法:
            makeLian(int 点数, bool 是否启用随机边权, int 随机数下界, int 随机数上界)
            */
            void makeLian(int n, int randVal = 0, int randL = 0, int randR = 0){
                for (int i = 1; i < n; i++){
                    printf("%d %d", i, i + 1);
                    if(randVal) printf(" %d", random(randL, randR));
                    putchar('\n');
                }
            }
    };

    template <size_t Size = (unsigned int)(1e5 + 10)>
    struct MakeGraph{
        private:
            struct Node{
                int u, v;
            };
            int a[Size], n, m;
            std::unordered_map<long long, bool> mp;
            long long get(Node edge){
                return 1ll * edge.u * (n + 1) + edge.v;
            }
            Node newedge(int self){
                int u = 0, v = 0;
                if(!self){
                    u = random(1, n - 1);
                    v = random(u + 1, n);
                }else{
                    u = random(1, n);
                    v = random(u, n);
                }
                return {u, v};
            }
        public:
            /*
            使用方法:
            DAG(int 点数, int 边数, bool 是否有重边, bool 是否有自环)
            Warning: 启用没有重边可能会降低程序的运行速度.
            */
            void DAG(int Point, int Edge, int Chong = 1, int Self = 0){
                n = Point, m = Edge;
                if(Chong == 0 && Self == 0 && m > n * (n - 1) / 2){
                    puts("在该点数和边数下无法构建没有重边和自环的DAG.");
                    return;
                }
                for(int i = 1; i <= n; i++) a[i] = i;
                std::shuffle(a + 1, a + n + 1, frand);
                // printf("%d %d\n", n, m);
                mp.clear();
                for(int i = 1; i <= m; i++){
                    Node newe = newedge(Self);
                    if(Chong == 0){
                        while(mp.find(get(newe)) != mp.end()){
                            newe = newedge(Self);
                        }
                        mp[get(newe)] = 1;
                        
                    }
                    printf("%d %d\n", a[newe.u], a[newe.v]);
                    if(Chong == 0){
                        std::swap(newe.u, newe.v);
                        mp[get(newe)] = 1;
                    }
                }
            }
            void directedNoCircleGraph(int Point, int Edge, int Chong = 1, int Self = 0){
                DAG(Point, Edge, Chong, Self);
            }
            void undirectedGraph(int Point, int Edge, int Chong = 1, int Self = 0){
                puts("this tool has not been build yet.");
            }
    };
    

};
