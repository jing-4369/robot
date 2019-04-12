#include <Arduino.h>
#include "Arm.h"
#include "Car.h"
//asdasdasdasdasdasdasd
// class coordinate
// {
//     public:
//         int x;
//         int y;

//         coordinate(int x, int y):x(x),y(y){};
// };

Arm myArm(10,11,12,13);
Car myCar(4,5,6,7,1,2,3,8,9,0,0,UP);

// coordinate Up(0,1);
// coordinate Down(0,-1);
// coordinate Left(-1,0);
// coordinate Right(1,0);//四个方向初始化

// coordinate ring[6] = {
//                     coordinate(0,2),coordinate(1,1),
//                     coordinate(-1,1),coordinate(-2,2),
//                     coordinate(2,2),coordinate(0,4)};//六个圆环初始化

// coordinate target[3] = {
//     coordinate(3,4),coordinate(3,2),coordinate(3,6)};//三个目标位置初始化

void grabAndLiftUp();

void setup (){
    Serial.begin(9600);
    myCar.goForward(10,0.5);
    Serial.println("go to init location");
    myArm.setup();

    myCar.goXGrids(1);
    grabAndLiftUp();
    myCar.goXGrids(2);
    myCar.turnRight(90);
    myCar.goXGrids(3);
    myCar.turnLeft(90);
    myArm.liftDownToColumn();
    myArm.liftUpFromColumn();//抓第一个，放在三分区
    Serial.println("successfully place first ring");

    myCar.turnLeft(90);
    myCar.goXGrids(3);
    myCar.turnRight(90);
    grabAndLiftUp();
    myCar.turnRight(180);
    myCar.goXGrids(1);
    myCar.turnLeft(90);
    myCar.goXGrids(3);
    myCar.turnLeft(90);
    myArm.liftDownToColumn();
    myArm.liftUpFromColumn();//抓第二个，放在三分区
    Serial.println("successfully place second ring");

    myCar.turnLeft(90);
    myCar.goXGrids(1);
    myCar.turnLeft(90);
    grabAndLiftUp();
    myCar.goXGrids(1);
    myCar.turnLeft(90);
    myArm.liftDownToColumn();
    myArm.liftUpFromColumn();//抓第三个，放在二分区
    Serial.println("successfully place third ring");

    myCar.turnRight(90);
    myCar.goXGrids(1);
    myCar.turnRight(90);
    grabAndLiftUp();
    myCar.turnRight(180);
    myCar.goXGrids(2);
    myCar.turnLeft(90);
    myArm.liftDownToColumn();
    myArm.liftUpFromColumn();//抓第四个，放在二分区
    Serial.println("successfully place fourth ring");

    myCar.turnLeft(90);
    myCar.goXGrids(3);
    grabAndLiftUp();
    myCar.turnRight(180);
    myCar.goXGrids(3);
    myCar.turnLeft(90);
    myCar.goXGrids(2);
    myArm.liftDownToGround();
    myArm.liftUpFromGround();//抓第五个，放在一分区
    Serial.println("successfully place fifth ring");

    myCar.turnRight(90);
    myCar.goXGrids(1);
    myCar.turnRight(90);
    myCar.goXGrids(3);
    grabAndLiftUp();
    myCar.turnLeft(180);
    myCar.goXGrids(4);
    myCar.turnLeft(90);
    myCar.goXGrids(1);
    myCar.turnRight(90);
    myArm.liftDownToGround();
    myArm.liftUpFromGround();//抓第六个，放在一分区
    Serial.println("successfully place sixth ring");
    Serial.println("successfully finish all tasks!!!");
    
    float time = millis()/1000;
    Serial.print("time cost is ");
    Serial.print(time);
    Serial.println(" s");
}

void loop (){
}

void grabAndLiftUp(){
    myArm.liftDownToGround();
    myCar.goForward(5,0.5);
    myArm.grab();
    myArm.liftUpFromGround();
    Serial.println("grab and lift up");
}