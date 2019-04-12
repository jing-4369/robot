

#include "Arm.h"

Arm::Arm(
    int clawPin, int rotatePin,
    int bottomPin, int mediumPin,
    bool isCaught)
    :clawPin(clawPin),rotatePin(rotatePin),
    bottomPin(bottomPin),mediumPin(mediumPin),
    isCaught(isCaught)
{
        
    clawServo.attach(clawPin);
    rotateServo.attach(rotatePin);
    bottomJoint.attach(bottomPin);
    mediumJoint.attach(mediumPin);
    Serial.println("initializing arm");
};

Arm::~Arm(){
    
}

void Arm::setup(){
  bottomJoint.write(157);//157
  mediumJoint.write(120);
  rotateServo.write(143);
  clawServo.write(0);
  Serial.println("setup arm");
};

void Arm::liftUpFromGround(){
    int pos = 0;
    for (pos = 15;pos<=120;pos++){
    bottomJoint.write(pos+10);
    mediumJoint.write(pos);
    delay(25);
    }

    for (pos = 130;pos<=137;pos++){
        bottomJoint.write(pos);
        delay(25);
    }
    Serial.println("lift up from ground");
};

void Arm::liftUpFromColumn(){
    Serial.println("lift up from column");
}

void Arm::liftDownToGround(){
    int pos = 0;
    for (pos = 137;pos<=130;pos++){
        bottomJoint.write(pos);
        delay(25);
    }

    for (pos = 120;pos>=15;pos--){
        bottomJoint.write(pos+10);
        mediumJoint.write(pos);
        delay(25);
    }
    release();
    Serial.println("lift down to ground");
};

void Arm::liftDownToColumn(){
    Serial.println("lift down to column");
}

void Arm::grab(){
    int pos = 0;
    for (pos = 45;pos>=0;pos--){
        clawServo.write(pos);
        delay(25);
    }
    isCaught = true;
    Serial.print("isCaught:");
    Serial.println(isCaught);
};

void Arm::release(){
    int pos = 0;
    for (pos = 0;pos<=45;pos++){
        clawServo.write(pos);
        delay(25);
    }
    isCaught = false;
    Serial.print("isCaught:");
    Serial.println(isCaught);
}

bool Arm::getState(){
    return isCaught;
};

void Arm::changeState(){
    isCaught = ! isCaught;
};

