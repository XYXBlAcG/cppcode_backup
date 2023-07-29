// #include <iostream>
// #include <cmath>

// using namespace std;

// const double G = 6.67e-11; //万有引力常数

// //表示行星的结构体
// struct planet {
//     double mass; //质量
//     double x, y; //坐标
//     double vx, vy; //速度
//     double ax, ay; //加速度
// };

// //时间步长，自己模拟的时候可以根据需要进行调整
// const double dt = 3600 * 24;

// //计算两个行星间的距离
// double distance(const planet& p1, const planet& p2) {
//     return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
// }

// //计算一个行星受到的引力
// void calculateForce(planet& p1, const planet& p2) {
//     double d = distance(p1, p2);
//     if (d == 0) return;
//     double f = G*p1.mass*p2.mass/(d*d);
//     double dx = p2.x - p1.x;
//     double dy = p2.y - p1.y;
//     double fx = f*dx/d;
//     double fy = f*dy/d;
//     p1.ax += fx/p1.mass;
//     p1.ay += fy/p1.mass;
// }

// int main() {
//     //定义八大行星
//     planet sun{1.9885e30, 0, 0, 0, 0, 0, 0}; //太阳
//     planet mercury{3.302e23, 57.91e9, 0, 0, 47.87e3, 0, 0}; //水星
//     planet venus{4.869e24, 108.21e9, 0, 0, 35.02e3, 0, 0}; //金星
//     planet earth{5.9742e24, 149.6e9, 0, 0, 29.78e3, 0, 0}; //地球
//     planet mars{6.4219e23, 227.92e9, 0, 0, 24.077e3, 0, 0}; //火星
//     planet jupiter{1.899e27, 778.57e9, 0, 0, 13.07e3, 0, 0}; //木星
//     planet saturn{5.688e26, 1.43e12, 0, 0, 9.69e3, 0, 0}; //土星
//     planet uranus{8.686e25, 2.87e12, 0, 0, 6.81e3, 0, 0}; //天王星
//     planet neptune{1.024e26, 4.5e12, 0, 0, 5.43e3, 0, 0}; //海王星

//     //自己设定仿真天数
//     int totalDays = 365*10;

//     //循环模拟运动
//     for (int i = 0; i < totalDays*24*3600/dt; i++) {
//         //计算各个行星受到的总引力
//         calculateForce(mercury, sun);
//         calculateForce(venus, sun);
//         calculateForce(earth, sun);
//         calculateForce(mars, sun);
//         calculateForce(jupiter, sun);
//         calculateForce(saturn, sun);
//         calculateForce(uranus, sun);
//         calculateForce(neptune, sun);

//         //计算行星的运动
//         mercury.vx += mercury.ax*dt;
//         mercury.vy += mercury.ay*dt;
//         mercury.x += mercury.vx*dt;
//         mercury.y += mercury.vy*dt;

//         venus.vx += venus.ax*dt;
//         venus.vy += venus.ay*dt;
//         venus.x += venus.vx*dt;
//         venus.y += venus.vy*dt;

//         earth.vx += earth.ax*dt;
//         earth.vy += earth.ay*dt;
//         earth.x += earth.vx*dt;
//         earth.y += earth.vy*dt;

//         mars.vx += mars.ax*dt;
//         mars.vy += mars.ay*dt;
//         mars.x += mars.vx*dt;
//         mars.y += mars.vy*dt;

//         jupiter.vx += jupiter.ax*dt;
//         jupiter.vy += jupiter.ay*dt;
//         jupiter.x += jupiter.vx*dt;
//         jupiter.y += jupiter.vy*dt;

//         saturn.vx += saturn.ax*dt;
//         saturn.vy += saturn.ay*dt;
//         saturn.x += saturn.vx*dt;
//         saturn.y += saturn.vy*dt;

//         uranus.vx += uranus.ax*dt;
//         uranus.vy += uranus.ay*dt;
//         uranus.x += uranus.vx*dt;
//         uranus.y += uranus.vy*dt;

//         neptune.vx += neptune.ax*dt;
//         neptune.vy += neptune.ay*dt;
//         neptune.x += neptune.vx*dt;
//         neptune.y += neptune.vy*dt;

//         //给各个行星的加速度清零
//         mercury.ax = mercury.ay = 0;
//         venus.ax = venus.ay = 0;
//         earth.ax = earth.ay = 0;
//         mars.ax = mars.ay = 0;
//         jupiter.ax = jupiter.ay = 0;
//         saturn.ax = saturn.ay = 0;
//         uranus.ax = uranus.ay = 0;
//         neptune.ax = neptune.ay = 0;

//         //输出各个行星的坐标
//         cout << "Day " << i*dt/(24*3600) << ":" << endl;
//         cout << "Mercury: (" << mercury.x << ", " << mercury.y << ")" << endl;
//         cout << "Venus: (" << venus.x << ", " << venus.y << ")" << endl;
//         cout << "Earth: (" << earth.x << ", " << earth.y << ")" << endl;
//         cout << "Mars: (" << mars.x << ", " << mars.y << ")" << endl;
//         cout << "Jupiter: (" << jupiter.x << ", " << jupiter.y << ")" << endl;
//     }
//     }