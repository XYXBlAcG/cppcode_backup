#include <iostream>

using namespace std;

bool mp[10][10];

int st[10][10];

void init(int x, int y)
{

    int cnt = 0;

    while (cnt < 10)
    {

        int i = rand() % 9 + 1, j = rand() % 9 + 1;

        if (mp[i][j] || (i == x && j == y))
        {

            continue;
        }

        cnt++;

        mp[i][j] = true;
    }

    memset(st, -1, sizeof(st));
}

bool checkwin()
{

    for (int i = 1; i <= 9; i++)
    {

        for (int j = 1; j <= 9; j++)
        {

            if (st[i][j] < 0 && !mp[i][j])
            {

                return false;
            }
        }
    }

    return true;
}

void printmap()
{

    printf("x y ");

    for (int i = 1; i <= 9; i++)
    {

        printf("%d ", i);
    }
    printf("\n");

    for (int i = 1; i <= 9; i++)
    {

        printf("%d : ", i);

        for (int j = 1; j <= 9; j++)
        {

            if (st[i][j] == -1)
            {

                putchar('*');
            }

            else if (st[i][j] == -2)
            {

                putchar('@');
            }

            else
            {

                putchar('0' + st[i][j]);
            }

            putchar(' ');
        }

        putchar('\n');
    }
}

bool valid(int x, int y)
{

    return x >= 1 && x <= 9 && y >= 1 && y <= 9;
}

int getnum(int x, int y)
{

    int cnt = 0;

    for (int i = -1; i <= 1; i++)
    {

        for (int j = -1; j <= 1; j++)
        {

            int nx = x + i, ny = y + j;

            if (valid(nx, ny))
            {

                cnt += mp[nx][ny];
            }
        }
    }

    return cnt;
}

bool open(int x, int y)
{

    if (st[x][y] == -2)
    {

        return false;
    }

    if (mp[x][y])
    {

        return true;
    }

    st[x][y] = getnum(x, y);

    if (!st[x][y])
    {

        for (int i = -1; i <= 1; i++)
        {

            for (int j = -1; j <= 1; j++)
            {

                if (!i && !j)
                    continue;

                int nx = x + i, ny = y + j;

                if (valid(nx, ny) && st[nx][ny] < 0)
                {

                    open(nx, ny);
                }
            }
        }
    }

    return false;
}

bool quickopen(int x, int y)
{

    int cnt = 0;

    bool res = false;

    if (st[x][y] > 0)
    {

        for (int i = -1; i <= 1; i++)
        {

            for (int j = -1; j <= 1; j++)
            {

                int nx = x + i, ny = y + j;

                if (valid(nx, ny) && st[nx][ny] == -2)
                {

                    cnt++;
                }
            }
        }

        if (cnt == st[x][y])
        {

            for (int i = -1; i <= 1; i++)
            {

                for (int j = -1; j <= 1; j++)
                {

                    int nx = x + i, ny = y + j;

                    if (!i && !j)
                        continue;

                    if (valid(nx, ny))
                    {

                        res |= open(nx, ny);
                    }
                }
            }
        }
    }

    return res;
}

int main()
{

    system("cls");

    printf("1 x y: open\n2 x y: mark\n3 x y: quick open\n(the first action should begin with 1)\n");

    for (int i = 1; i <= 9; i++)
    {

        for (int j = 1; j <= 9; j++)
        {

            printf("* ");
        }

        printf("\n");
    }

    srand((time(NULL) - 114514 + 1919810) % 998244353ll + 1e9 + 7 - 1e9 - 9);

    int x, y, op;

    while (true)
    {

        scanf("%d%d%d", &op, &x, &y);

        if (valid(x, y) && op == 1)

            break;
    }

    init(x, y);

    open(x, y);

    while (true)
    {

        system("cls");

        printf("1 x y: open\n2 x y: mark\n3 x y: quick open\n(the first action should begin with 1)\n");

        printmap();

        if (checkwin())
        {

            printf("You Win!\n");

            break;
        }

        int x, y, op;

        while (true)
        {

            scanf("%d%d%d", &op, &x, &y);

            if (valid(x, y) && op <= 3 && op >= 1)
                break;
        }

        if (op == 1)
        {

            if (open(x, y))
            {

                printf("You Died!\n");

                break;
            }
        }

        else if (op == 2)
        {

            if (st[x][y] == -1)
            {

                st[x][y] = -2;
            }

            else if (st[x][y] == -2)
            {

                st[x][y] = -1;
            }
        }

        else if (op == 3)
        {

            if (quickopen(x, y))
            {

                printf("You Died!\n");

                break;
            }
        }
    }

    for (int i = 1; i <= 9; i++)
    {

        for (int j = 1; j <= 9; j++)
        {

            if (mp[i][j])
                printf("* ");

            else
                printf("%d ", getnum(i, j));
        }

        printf("\n");
    }

    return 0;
}
