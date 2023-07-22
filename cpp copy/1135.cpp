#include <cstdio>
int main() {
    int y, m, d;
    scanf("%d%d%d", &y, &m, &d);
    if (m < 3)
        m += 12, y--;
    int c = y / 100;
    y = y - c * 100;
    int w = (y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1) % 7;
    if (w < 0)
        w += 7;
    if (w == 0)
        printf("Sunday\n");
    if (w == 1)
        printf("Monday\n");
    if (w == 2)
        printf("Tuesday\n");
    if (w == 3)
        printf("Wednesday\n");
    if (w == 4)
        printf("Thursday\n");
    if (w == 5)
        printf("Friday\n");
    if (w == 6)
        printf("Saturday\n");
    return 0;
}