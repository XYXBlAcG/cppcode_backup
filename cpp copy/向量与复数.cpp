
#include <cstdio>
#include <math.h>
using namespace std;
const double EPS = 1e-8, PI = atan(1) * 4; struct Comp{
double x, y;
double sqr()const;//点乘的平方，也等于自己乘共轭
double abs()const{return sqrt(sqr());}//模长
Comp conj()const{return {x, -y};}//共轭
Comp norm()const{return *this / abs();}//归一化，即把模长变成1 //求辐角主值，修正x<0，y=-0时atan2会得到-π的锅，需要让取值范围严格半开半闭(-π,π] double arg()const{double t = atan2(y, x); return t < -PI + EPS ? t + PI * 2 : t;} Comp operator-()const{return {-x, -y};}
Comp operator*(double b)const{return {x * b, y * b};}//实数乘
};
Comp operator+(const Comp& a, const Comp& b){return {a.x + b.x, a.y + b.y};} Comp operator-(const Comp& a, const Comp& b){return {a.x - b.x, a.y - b.y};} Comp operator*(double a, const Comp& b){return {a * b.x, a * b.y};}//实数乘 Comp operator*(const Comp& a, const Comp& b){//复数乘
return {a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};}
double dot(const Comp& a, const Comp& b){return a.x * b.x + a.y * b.y;}//点乘 double cross(const Comp& a, const Comp& b){return a.x * b.y - a.y * b.x;}//叉乘 Comp operator/(const Comp& a, double b){return {a.x / b, a.y / b};}//实数除 Comp operator/(const Comp& a, const Comp& b){//复数除
return (Comp){dot(a, b), cross(a, b)} / b.sqr();} double Comp::sqr()const{return dot(*this, *this);}
 