#include <cstdio>
#include <algorithm>
#include <cstring>
const int M = 1e3 + 5;
// cd ..; g++ 3212.cpp -o /Users/xiexie/Desktop/cpp/output/3212 -Wall -Wextra -g3; cd "/Users/xiexie/Desktop/cpp/output"; ./3212 < 3212.in > 3212.out; code 3212.out
int n, m, ans[M], pans;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
struct Node{
    int x, y; // -1 wall \0 air \1 black \2 white
}fath[M][M], go[M][M];
// struct node{
//     int x, y, fx, fy;
// }mem[M * M];
int Type[M][M];
int Air[M][M];
int fathAir[M][M];
int num[3];
bool check(int x, int y){
    if(x > 0 && y > 0 && x < n + 1 && y < n + 1){
        return 1;
    }return 0;
}
Node find(int x, int y){
    // printf("find x:%d y:%d fx:%d fy:%d\n", x, y, fath[x][y].x, fath[x][y].y);
    if(check(x, y) && (fath[x][y].x != x || fath[x][y].y != y)){
        Node Point = find(fath[x][y].x, fath[x][y].y);
        // printf("(%d,%d)是(%d,%d)的父亲\n", Point.x, Point.y, x, y); fflush(stdout);  
        fath[x][y].x = Point.x; fath[x][y].y = Point.y;
        return fath[x][y];
    }
    // printf("(%d,%d)是他自己的父亲\n", x, y); fflush(stdout);   
    return (Node){x, y};
}
void merge(int ax, int ay, int bx, int by){
    Node Point = find(ax, ay);
    Node Check = find(bx, by);
    if(Point.x == Check.x && Point.y == Check.y) return;
    // fath[Point.x][Point.y].x = fath[bx][by].x;
    // fath[Point.x][Point.y].y = fath[bx][by].y;
    num[Type[ax][ay]]--;
    fath[Point.x][Point.y].x = fath[Check.x][Check.y].x;
    fath[Point.x][Point.y].y = fath[Check.x][Check.y].y;
    fathAir[Check.x][Check.y] += fathAir[Point.x][Point.y];
    // mem[++pmem] = (node){bx, by, Point.x, Point.y};
    // Air[Point.x][Point.y] += Air[bx][by];
    // fathAir[Point.x][Point.y] += fathAir[fath[bx][by].x][fath[bx][by].x];
    // printf("(%d,%d)和(%d,%d)联系上了\n(%d,%d)的父亲为(%d,%d)\n(%d,%d)的父亲为(%d,%d)\n",bx,by,ax,ay,bx,by,fath[bx][by].x,fath[bx][by].y,ax,ay,fath[ax][ay].x,fath[ax][ay].y);
}
void update(int x, int y){
    int air = 0, tx = 0, ty = 0;
    for (int i = 0; i < 4; i++){
        tx = x + dir[i][0]; ty = y + dir[i][1];
        if(Type[tx][ty] == 0){
            air++;
        }
    }
    // printf("(%d,%d)的气数为%d\n", x, y, air);
    Node Point = find(x, y);
    // printf("其父亲(%d,%d)的总气数是%d\n", Point.x, Point.y, fathAir[Point.x][Point.y]);
    fathAir[Point.x][Point.y] = (fathAir[Point.x][Point.y] - Air[x][y] + air);
    Air[x][y] = air;
    // printf("其父亲(%d,%d)的气数被更新为了%d\n", Point.x, Point.y, fathAir[Point.x][Point.y]);
}
void add(int x, int y, int type){
    int tx = 0, ty = 0;
    for (int i = 0; i < 4; i++){
        // printf("以(%d,%d)查找(%d,%d)\n",x,y,tx,ty);
        tx = x + dir[i][0]; ty = y + dir[i][1];
        if(check(tx, ty) && Type[tx][ty] == type){
            merge(x, y, tx, ty);
        }
        Node Point = find(tx, ty), Point2 = find(x, y);
        // if(Point.x == Point2.x && Point.y == Point2.y) num[type]--;
    }
    for (int i = 0; i < 4; i++){
        tx = x + dir[i][0]; ty = y + dir[i][1];
        if(check(tx, ty) && (Type[tx][ty] == 1 or Type[tx][ty] == 2)) update(tx, ty);
    } update(x, y);
    // for (int i = 1; i <= pmem; i++){
    //     int px = mem[i].x, py = mem[i].y, fx = mem[i].fx, fy = mem[i].fy;
    //     Node Point = find(fx, fy);
    //     fathAir[Point.x][Point.y] += Air[px][py];
    //     printf("祖先节点(%d,%d)的气数被更新成了%d\n", Point.x, Point.y, fathAir[Point.x][Point.y]);
    // } pmem = 0;
}
void debug(){
    printf("---start---\n");
    for (int i = 0; i <= n + 1; i++){
        for (int j = 0; j <= n + 1; j++){
            printf("%d ", Type[i][j]);
            if(Type[i][j] != -1) printf(" ");
        }printf("\n");
    }
    printf("---air---\n");
    for (int i = 0; i <= n + 1; i++){
        for (int j = 0; j <= n + 1; j++){
            printf("%d ", Air[i][j]);
            if(Air[i][j] != -1) printf(" ");
        }printf("\n");
    }
    printf("---fathAir---\n");
    for (int i = 0; i <= n + 1; i++){
        for (int j = 0; j <= n + 1; j++){
            printf("%d ", fathAir[i][j]);
            if(fathAir[i][j] != -1) printf(" ");
        }printf("\n");
    }
    printf("---end---\n");
    fflush(stdout);
}
void init(){
    // printf("---init---\n");
    for (int i = 0; i <= n + 1; i++){
        for (int j = 0; j <= n + 1; j++){
            Type[i][j] = (i == 0 || j == 0 || i == n + 1 || j == n + 1) ? -1 : 0;
        }
    }
    for (int i = 0; i <= n + 1; i++){
        for (int j = 0; j <= n + 1; j++){
            fath[i][j] = (Node){i, j};
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    init();
    // debug();
    for (int i = 1; i <= m; i++){
        int op, x, y;
        scanf("%d",&op);
        if(op == 1){
            // printf("op = 1\n");fflush(stdout);
            scanf("%d%d",&x,&y); x++; y++; num[1]++;
            add(x, y, Type[x][y] = 1);
        }else if(op == 2){
            // printf("op = 2\n");fflush(stdout);
            scanf("%d%d",&x,&y); x++; y++; num[2]++;
            add(x, y, Type[x][y] = 2);
        }else if(op == 3){
            // printf("op = 3\n");fflush(stdout);
            printf("%d\n", num[1]);
            // ans[++pans] = num[1];
        }else if(op == 4){
            // printf("op = 4\n");fflush(stdout);
            printf("%d\n", num[2]);
            // ans[++pans] = num[2];
        }else if(op == 5){
            // printf("op = 5 : ");fflush(stdout);
            scanf("%d%d",&x,&y); x++; y++;
            Node Point = find(x, y);
            printf("%d\n", fathAir[Point.x][Point.y]);
            // ans[++pans] = fathAir[Point.x][Point.y];
        }
        // debug();
    }
    // for (int i = 1; i <= pans; i++){
    //     printf("result:%d\n", ans[i]);
    // }
    return 0;
}

// for (int i = 0; i < 4; i++){
//     int ttx, tty;
//     ttx = x + dir[i][0]; tty = y + dir[i][1];
//     if(check(ttx, tty) && (Type[ttx][tty] == 1 or Type[ttx][tty] == 2)) cal(ttx, tty);
// }cal(x, y);

// void cal(int x, int y){
//     Node Point = find(x, y);
//     Air[Point.x][Point.y] += Air[x][y]; Air[x][y] = 0;
//     printf("(%d,%d)被(%d,%d)从%d气改为了%d气\n", Point.x, Point.y, x, y, Air[Point.x][Point.y], Air[Point.x][Point.y] + Air[x][y]);
//     // fath[Point.x][Point.y].air += go[x][y].air;
// }