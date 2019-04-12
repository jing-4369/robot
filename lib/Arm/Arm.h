#ifndef Arm_H
#define Arm_H

#include <Arduino.h>
#include <Servo.h>

class Arm
{
    public:

    const int clawPin;
    const int rotatePin;
    const int bottomPin;
    const int mediumPin;
    
    Servo clawServo;//爪子：0~45
    Servo rotateServo;//旋转舵机：143
    Servo bottomJoint;//底部关节：0~137
    Servo mediumJoint;//中部关节：15~120

    Arm (
        int clawPin = 10, int rotatePin = 11,
        int bottomPin = 12, int mediumPin = 13,
        bool isCaught = false);
    ~Arm ();

    bool isCaught;
    void setup();

    void liftUpFromGround();
    void liftUpFromColumn();
    void liftDownToGround();
    void liftDownToColumn();
    void grab();
    void release();


    bool getState();
    void changeState();
    //1.从初始状态放到地面上
    //2.从地面上升起
    //3.grab,release
    //4.从抓取状态放到柱子上
    
    private:

};

#endif
