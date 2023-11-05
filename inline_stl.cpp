#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
const int STL_MAXN = 1e5 + 5;
namespace xyx{
    template <typename T, size_t _Size>
    struct Heap{
        T data[_Size]; int pdata = 0;
        void push(T b){
            data[++pdata] = b;
            std::push_heap(data + 1, data + 1 + pdata);
        }
        void pop(){std::pop_heap(data + 1, data + 1 + pdata--);}
        T top(){return data[1];}
        int size(){return pdata;}
        bool empty(){return pdata;}
        T* begin(){return &data[1];}
        T* end(){return &data[pdata + 1];}
    };
    template <typename T, size_t _Size>
    struct Stack{
        T data[_Size]; int pdata = 0;
        void push(T b){data[++pdata] = b;}
        void pop(){if(pdata) pdata--;}
        T operator[](int x){return data[x];}
        T top(){return data[pdata];}
        int size(){return pdata;}
        bool empty(){return pdata;}
        int* begin(){return &data[1];}
        int* end(){return &data[pdata + 1];}
    };
    template <typename T, size_t _Size>
    struct Queue{
        T data[_Size]; int l = 0, r = 0;
        void push(T b){data[++r] = b;}
        void pop(){l++;}
        T tail(){return data[l + 1];}
        T head(){return data[r];}
        int size(){return r - l;}
        bool empty(){return r - l;}
        int* begin(){return &data[l + 1];}
        int* end(){return &data[r + 1];}
    };
    template <typename T>
    void swapINT(T& a, T& b){
        a ^= b ^= a ^= b;
    }
    template <size_t Size = (unsigned int)(1e5 + 10)>
    struct UFS{
        private:
            int fa[Size];
        public:
            UFS(int n, int st = 1){
                for (int i = st; i <= n; i++) fa[i] = i;
            }
            int find(int x, int zip = 1){
                if(zip == 1) return fa[x] == x ? x : fa[x] = find(fa[x]);
                else return fa[x] == x ? x : find(fa[x]);
            }
            bool same(int x, int y){
                return find(x) == find(y);
            }
            void merge(int x, int y){
                x = find(x), y = find(y);
                if(x == y) return;
                fa[y] = x;
            }
    };

    template <typename T2, size_t Size, int top>
    struct BITS{
        private:
            T2 d[Size];
        public:
            int lowbit(int x){
                return x & -x;
            }
            void add(int x, T2 val){
                for (int i = x; i <= top; i += lowbit(i)){
                    d[i] += val;
                }
            }
            T2 sum(int x){
                int ans = 0;
                for (int i = x; i; i -= lowbit(i)){
                    ans += d[i];
                }
                return ans;
            }
    };
    template<size_t Size, int p>
    struct Edge{
        struct Node{
            int nxt, ver, w, f;
        }node[Size * 4];
        int head[Size], pedge = p;
        void addsignle(int u, int v, int w = 0, int f = 0){
            node[++pedge] = {head[u], v, w, f};
            head[u] = pedge;
        }
        void addtwo(int u, int v, int w = 0, int f = 0){
            addsignle(u, v, w, f);
        }
        void adinic(int u, int v, int w, int f = 0){
            addsignle(u, v, w, f);
            addsignle(v, u, 0, -f);
        }
    };
    // template<size_t Size>
    // struct SPFA{
    //     std::queue<int> que;
    //     int dis[Size];
    //     void spfa(int n, int s, int t){
    //         que = {};
    //         memset(dis, 0x3f, sizeof(dis));
            
    //     }
    // };
    // template<size_t Size>
    // struct DJ{

    // };
    // template<size_t Size>
    // struct Floyd{

    // };
    // template<size_t Size>
    // struct LCA{
    //     void predfs(int u, int fa){
            
    //     }
    // };
    // template<size_t Size>
    // struct Dinic{
    //     #define int long long
    //     #define INF 0x3f3f3f3f3f3f3f3f
    //     int dis[Size], que[Size];
    //     bool bfs(){

    //     }
    //     int dfs(int u, int w){

    //     }
    //     int dinic(){
            
    //     }
    //     #undef int
    //     #undef INF
    // };
};