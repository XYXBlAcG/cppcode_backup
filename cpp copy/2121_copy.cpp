#include <cstdio>
int res = 0;
int n, m, sx, sy;
int w;
int map[7][7];
struct point {
    int x, y;
};
int white;
point dir[4] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
point move = { 0, 0 };
point jia(point a, point b) { 
    return { a.x + b.x, a.y + b.y }; 
}
point jian(point a, point b) { 
    return { a.x - b.x, a.y - b.y }; 
}
void hua(int a) {
    if (a == white) {
        res++;
        return;
    }
    for (int i = 0; i <= 3; i++) {
        map[move.x][move.y] = 0;
        move = jia(move, dir[i]);
        if (map[move.x][move.y] == 1)
            hua(a + 1);
        move = jian(move, dir[i]);
        map[move.x][move.y] = 1;
    }
}
int main() {
    for (int i = 0; i <= 6; i++) {
        for (int j = 0; j <= 6; j++) {
            map[i][j] = 0;
        }
    }
    scanf("%d%d%d%d", &n, &m, &sx, &sy);
    move.x = sx;
    move.y = sy;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &w);
            if (w == 0) {
                map[i][j] = 1;
                white++;
            } else {
                map[i][j] = 0;
            }
        }
    }
    hua(1);
    printf("%d\n", res);
    return 0;
}