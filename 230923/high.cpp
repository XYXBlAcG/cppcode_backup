#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <string>
#define de(x) std::cout << #x << " = " << x << std::endl
const int N = 2005;
int cc;
struct Num {
    int num[N], len, fu, st, bl;  // fu 0 Õý 1 ¸º
} aa, bb;
struct Div {
    Num res, remain;
} zero;
void sw(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}
void swa(Num &a, Num &b) {
    int tmp[N];
    memcpy(tmp, a.num, N);
    memcpy(a.num, b.num, N);
    memcpy(b.num, tmp, N);
    sw(a.len, b.len);
    sw(a.fu, b.fu);
}
bool operator==(Num a, Num b) {
    if (a.len ^ b.len)
        return 0;
    else
        for (int i = 1; i <= a.len; i++)
            if (a.num[i] ^ b.num[i])
                return 0;
    return 1;
}
void reverse(Num &a) {
    int tmp[N];
    memcpy(tmp, a.num, sizeof(a.num));
    // memset(a.num, 0, sizeof(a.num));
    for (int i = 1; i <= a.len; i++) a.num[i] = tmp[a.len - i + 1];
}
int max(int a, int b) { return (a > b) ? a : b; }
int leng(int a) {
    if (a == 0)
        return 1;
    int cnt = 0;
    while (a) a /= 10, cnt++;
    return cnt;
}
inline void input(Num &who) {
    scanf("%d", &who.len);
    for (int i = who.len; i; i--) scanf("%d", who.num + i);
    who.fu = 0;
}
inline void output(Num who) {
    if (who.fu)
        printf("-");
    if (who.st == 1) {
        for (int i = who.len - 1; i >= 0; i--) {
            printf("%d", who.num[i]);
        }
    } else if (who.st == 2) {
        int fl = 0;
        for (int i = who.bl - 1; i >= 0; i--) {
            if (!who.num[i] && !fl)
                continue;
            if (who.num[i] && !fl)
                fl = 1;
            printf("%d", who.num[i]);
        }
    } else {
        for (int i = who.len; i; i--) {
            printf("%d", who.num[i]);
        }
    }

    putchar('\n');
}
inline Num Bmax(Num a, Num b) {
    if (a.len > b.len)
        return a;
    if (a.len < b.len)
        return b;
    for (int i = a.len; i; i--) {
        if (a.num[i] > b.num[i])
            return a;
        if (a.num[i] < b.num[i])
            return b;
    }
    return a;
}
inline void move(Num &a, int wei) {  // left
    int tmp[N];
    memcpy(tmp, a.num, sizeof(tmp));
    // memset(a.num, 0, sizeof(a.num));
    for (int i = N - 5; i; i--) a.num[i - wei] = tmp[i];
}
inline Num normal(int inp) {
    Num numb;
    memset(numb.num, 0, sizeof(numb.num));
    int cnt = 0;
    for (; inp; cnt++) {
        numb.num[cnt + 1] = inp % 10;
        inp /= 10;
    }
    numb.len = cnt, numb.fu = 0;
    return numb;
}
inline Num Bstr(std::string inp) {
    Num numb;
    memset(numb.num, 0, sizeof(numb.num));
    numb.len = inp.size(), numb.fu = 0;
    for (int i = 0; i < (int)inp.size(); i++) {
        numb.num[i + 1] = inp[i] - '0';
    }
    return numb;
}
inline void Blen(Num &a) {
    int i = N - 5;
    while (!a.num[i] && i) i--;
    if (!i)
        i = 1;
    a.len = i;
}
inline Num substra(Num a, int from, int to) {
    Num tmp;
    memset(tmp.num, 0, sizeof(tmp.num)), tmp.fu = 0, tmp.len = to - from + 1;
    for (int i = from, j = 1; i <= to; i++, j++) tmp.num[j] = a.num[i];
    return tmp;
}
inline Num plus(Num a, Num b) {
    Num ans;
    memset(ans.num, 0, sizeof(ans.num)), ans.fu = 0;
    if (a.fu && b.fu)
        ans.fu = 1;
    else if (Bmax(a, b) == a && a.fu && !(a == b))
        ans.fu = 1;
    else if (Bmax(a, b) == b && b.fu && !(a == b))
        ans.fu = 1;
    for (int i = 1; i <= max(a.len, b.len); i++) {
        int tmp = a.num[i] + b.num[i];
        if (tmp >= 10)
            tmp %= 10, ans.num[i + 1]++;
        ans.num[i] += tmp;
        if (ans.num[i] >= 10)
            ans.num[i] %= 10, ans.num[i + 1]++;
    }
    Blen(ans);
    return ans;
}
inline Num minus(Num a, Num b) {
    Num ans;
    memset(ans.num, 0, sizeof(ans.num)), ans.len = 1, ans.fu = 0;
    if (a == b)
        return ans;
    if (Bmax(a, b) == b)
        swa(a, b), ans.fu = 1;
    for (int i = 1; i <= max(a.len, b.len); i++) {
        int tmp = a.num[i] - b.num[i];
        if (tmp < 0)
            tmp += 10, ans.num[i + 1]--;
        ans.num[i] += tmp;
        if (ans.num[i] < 0)
            ans.num[i] += 10, ans.num[i + 1]--;
    }
    Blen(ans);
    return ans;
}
Num times(Num a, Num b) {
    Num ans;
    memset(ans.num, 0, sizeof(ans.num)), ans.len = 1, ans.fu = a.fu ^ b.fu;
    for (int i = 1; i <= a.len; i++) {
        for (int j = 1; j <= b.len; j++) {
            int pos = i + j - 1, tmp = a.num[i] * b.num[j], cnt = 0;
            while (tmp) {
                ans.num[pos + cnt] += (tmp % 10);
                tmp /= 10;
                cnt++;
            }
        }
    }
    for (int i = 1; i <= N - 5; i++) {
        int cnt = 0, tmp = ans.num[i];
        ans.num[i] = 0;
        while (tmp) {
            ans.num[i + cnt] += (tmp % 10);
            tmp /= 10;
            cnt++;
        }
    }
    Blen(ans);
    return ans;
}
Div div(Num a, Num b) {
    Num ans, tmp;
    memset(ans.num, 0, sizeof(ans.num)), ans.len = 1, ans.fu = a.fu ^ b.fu;
    if (b.len == 1 && b.num[1] == 0) {
        ans.fu = 0;
        return zero;
    }
    if (Bmax(a, b) == b) {
        ans.fu = 0;
        reverse(a);
        return (Div){ ans, a };
    } else if (a == b) {
        ans.num[1] = 1, tmp = ans, tmp.fu = 0;
        return (Div){ ans, tmp };
    }
    a.fu = b.fu = 0;
    int tm[N];
    memset(tm, 0, sizeof(tm));
    reverse(a), reverse(b);
    move(a, 1), move(b, 1);
    for (int i = a.len - b.len - 1; i >= 0; i--) {
        for (int j = 0; j <= b.len; j++) tm[i + j] = b.num[j];
        while (1) {
            int cmp = 0;
            for (int j = b.len + i; j >= 0; j--) {
                cmp = a.num[j] - tm[j];
                if (cmp != 0)
                    break;
            }
            if (cmp < 0)
                break;
            for (int j = 0; j <= b.len + i; j++) {
                a.num[j] -= tm[j];
                if (a.num[j] < 0) {
                    a.num[j] += 10;
                    a.num[j + 1] -= 1;
                }
            }
            ans.num[i]++;
        }
        for (int j = 0; j <= b.len; j++) tm[i + j] = 0;
    }
    ans.st = 1;
    a.st = 2, a.bl = b.len;
    ans.len = (a.len - b.len > 0) ? (a.len - b.len) : 1;
    Blen(a);
    // reverse(ans);
    // move(a, -1), move(b, -1);
    // printf("%d\n", ans.len);
    return (Div){ ans, a };
}
int main() {
    zero.res.num[1] = -1;
    int tesa = 0, tesb = 0;
    scanf("%d%d", &tesa, &tesb);
    Num AAA = normal(tesa), BBB = normal(tesb);
    output(plus(AAA, BBB));
    // input(aa), input(bb);
//    std::string AA, BB;
//    std::cin >> AA >> BB;
//    Num aa = Bstr(AA), bb = Bstr(BB);
    // output(aa), output(bb);
    // // scanf("%d", &cc);
    // // Num CC = normal(cc);
    // output(plus(aa, bb));
    // // output(plus(aa, CC));
    // output(minus(aa, bb));
    // // output(minus(bb, CC));
    // output(times(aa, bb));
    // // output(times(aa, CC));
//    Div diver = div(aa, bb);
//    output(diver.res);
//    output(diver.remain);
    return 0;
}
