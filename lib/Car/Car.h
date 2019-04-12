#ifndef CAR_H
#define CAR_H 

#include <Arduino.h>

#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4

class Car
{
    public:

    const int rightPositive;
    const int rightNegative; 
    const int leftNegative;
    const int leftPositive;
    int trace[5];

    int x;
    int y;

    int direction;

    Car(
        int rightPositive = 4, int rightNegative = 5,
        int leftNegative = 6, int leftPositive = 7,
        int tracepin0 = 1, int tracepin1 = 2,
        int tracepin2 = 3, int tracepin3 = 8, int tracepin4 = 9,
        int x = 0, int y = 0, int direction = UP);//初始化4个电机pin，和五个循迹pin，以及小车初始坐标和方向
    ~Car();

    void goStop();
    void goLeft(int setTime, float speed);
    void goRight(int setTime, float speed);
    void goForward(int setTime, float speed);
    void goBackward(int setTime, float speed);//setTime为行驶时间，speed是占空比
    void goXGrids(int x);//行驶X格
    void turnRight(int degree);
    void turnLeft(int degree);//degree：1代表90度，2代表180度
    
    void tracing();

    void locationUpgrate(int direction);

    void turn(int targetDirection);//判断小车如何从当前方向转至目标方向
};


#endif