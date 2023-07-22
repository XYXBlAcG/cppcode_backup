const int V = 1e5;
const int E = 3e5;
int head[V], cur[V];
int pans, ans[E];
bool used[E];
struct Edge{
    int ver, nxt; 
}
edge[E * 2 + 1]; //必须从2开始编号
void dfs(int a){ //i一定是引用，保证不重复枚举 
    for(int &i = cur[a]; i;){
        Edge &e = edge[i]; //一对边用同一个used 
        bool &u = used[i >> 1]; i = e.nxt;//删掉当前边 
        if(!u){//这条边没有用过
            dfs(e.ver); 
        }//否则反边用过就直接跳过
    }
    ans[++pans] = a;
}
int main(){
        for(int i = 1; i <= n; i++)
            cur[i] = head[i];
        for(int i = 1; i <= n; i++)
        u = 1;
        if(cur[i] != 0){
    break; 
}
}