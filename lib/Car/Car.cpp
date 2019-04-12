#include "Car.h"

Car::Car(
    int rightPositive,int rightNegative,
    int leftNegative,int leftPositive,
    const int tracepin0, int tracepin1,
    int tracepin2, int tracepin3, int tracepin4,
    int x, int y,int direction)
    :rightPositive(rightPositive),rightNegative(rightNegative),leftNegative(leftNegative),leftPositive(leftPositive),
    x(x),y(y),direction(direction)
{
    trace[0] = tracepin0;
    trace[1] = tracepin1;
    trace[2] = tracepin2;
    trace[3] = tracepin3;
    trace[4] = tracepin4;

    pinMode(rightNegative,OUTPUT);
    pinMode(rightPositive,OUTPUT);
    pinMode(leftNegative,OUTPUT);
    pinMode(leftPositive,OUTPUT);
    pinMode(trace[0],INPUT);
    pinMode(trace[1],INPUT);
    pinMode(trace[2],INPUT);
    pinMode(trace[3],INPUT);
    pinMode(trace[4],INPUT);
    Serial.println("initializing car");
};

Car::~Car(){
    
}

void Car::goStop(){
    // digitalWrite(rightNegative,0);
    // digitalWrite(rightPositive,0);
    // digitalWrite(leftNegative,0);
    // digitalWrite(leftPositive,0);
    Serial.println("go stop");
};

void Car::goLeft(int setTime, float speed){
    int time = 0;
    // while (time<=setTime){

    //     digitalWrite(rightNegative,0);
    //     digitalWrite(rightPositive,1);
    //     digitalWrite(leftNegative,1);
    //     digitalWrite(leftPositive,0);
    //     delay(speed);
    //     time = time + speed;

    //     digitalWrite(rightNegative,0);
    //     digitalWrite(rightPositive,0);
    //     digitalWrite(leftNegative,0);
    //     digitalWrite(leftPositive,0);
    //     delay(1-speed);
    //     time = time + 1 - speed;
    // }
    // goStop();
    Serial.print("go left, time: ");
    Serial.print(setTime);
    Serial.print("speed: ");
    Serial.println(speed);
}

void Car::goRight(int setTime, float speed){
    // int time = 0;
    // while (time<=setTime){

    //     digitalWrite(rightNegative,1);
    //     digitalWrite(rightPositive,0);
    //     digitalWrite(leftNegative,0);
    //     digitalWrite(leftPositive,1);
    //     delay(speed);
    //     time = time + speed;

    //     digitalWrite(rightNegative,0);
    //     digitalWrite(rightPositive,0);
    //     digitalWrite(leftNegative,0);
    //     digitalWrite(leftPositive,0);
    //     delay(1-speed);
    //     time = time + 1 - speed;
    // }
    // goStop();
    Serial.print("go right, time: ");
    Serial.print(setTime);
    Serial.print("speed: ");
    Serial.println(speed);
}

void Car::goForward(int setTime, float speed){
    // int time = 0;
    // while (time<=setTime){

    //     digitalWrite(rightNegative,0);
    //     digitalWrite(rightPositive,1);
    //     digitalWrite(leftNegative,0);
    //     digitalWrite(leftPositive,1);
    //     delay(speed);
    //     time = time + speed;

    //     digitalWrite(rightNegative,0);
    //     digitalWrite(rightPositive,0);
    //     digitalWrite(leftNegative,0);
    //     digitalWrite(leftPositive,0);
    //     delay(1-speed);
    //     time = time + 1 - speed;
    // }
    // goStop();
    Serial.print("go forward, time: ");
    Serial.print(setTime);
    Serial.print("speed: ");
    Serial.println(speed);
}

void Car::goBackward(int setTime, float speed){
    // int time = 0;
    // while (time<=setTime){

    //     digitalWrite(rightNegative,1);
    //     digitalWrite(rightPositive,0);
    //     digitalWrite(leftNegative,1);
    //     digitalWrite(leftPositive,0);
    //     delay(speed);
    //     time = time + speed;

    //     digitalWrite(rightNegative,0);
    //     digitalWrite(rightPositive,0);
    //     digitalWrite(leftNegative,0);
    //     digitalWrite(leftPositive,0);
    //     delay(1-speed);
    //     time = time + 1 - speed;
    // }
    // goStop();
    Serial.print("go backward, time: ");
    Serial.print(setTime);
    Serial.print("speed: ");
    Serial.println(speed);
}

void Car::goXGrids(int x){
    int i = 1;
    for(;i<=x;i++){
        tracing();
        goForward(10,0.5);
        locationUpgrate(direction);
    }
    Serial.print("go ");
    Serial.print(x);
    Serial.println(" grids");
}

void Car::turnRight(int degree){
    // int i = 1;
    // int temp = degree/90;
    // for(;i<=temp;i++){
    //     goRight(100,0.6);
    //     while(1){
    //         goRight(10,0.3);
    //         if (digitalRead(trace[2])) {
    //             break;
    //         }
    //     } 
    // }
    Serial.print("turn right: ");
    Serial.println(degree);
}

void Car::turnLeft(int degree){
    // int i = 1;
    // for(;i<=degree;i++){
    //     goLeft(100,0.6);
    //     while(1){
    //         goLeft(10,0.3);
    //         if (digitalRead(trace[2])) {
    //             break;
    //         }
    //     } 
    // }
    Serial.print("turn left: ");
    Serial.println(degree);
}

void Car::tracing(){
    Serial.println("start tracing");
    // while(1){
        
    //     bool tracing[5];
    //     int i;
    //     for(i = 0;i<=4;i++){
    //         tracing[i] = digitalRead(trace[i]);
    //     }
        
    //     if(tracing[0]&&tracing[1]&&tracing[2]&&tracing[3]&&tracing[4]){
    //         goForward(20,0.6);
    //         break;
    //     }
    //     else if ((!tracing[1])&&(!tracing[2])&&(tracing[3])){
    //         goRight(5,0.3);
    //         goLeft(1,0.3);
    //     }
    //     else if ((!tracing[3])&&(!tracing[2])&&(tracing[1])){
    //         goLeft(5,0.3);
    //         goRight(1,0.3);
    //     }
    //     else if (tracing[2]) {
    //         goForward(50,0.6);
    //     }
    //     else {
    //         goForward(50,0.6);
    //     }
    // }
    Serial.println("end tracing");
}

void Car::locationUpgrate(int direction){
    switch(direction){
        case UP:
            y++;
        case DOWN:
            y--;
        case RIGHT:
            x++;
        case LEFT:
            x--;
    }
    Serial.println("upgrate location");
}

void Car::turn(int targetDirection){
    if(targetDirection == direction){
        return;
    }
    else
    {
    }
    
}
