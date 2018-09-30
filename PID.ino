
void calcSteeringPID(void) {
  
  pValue = steerAngleSetPoint*steerSensorCounts+steeringPositionZero;
   }

 void motorDrive(void) 
  {
    jrk.setTarget(pValue);
  }

//void updatejrk(){
//  jrk.setProportionalCoefficient(Kp, 1);
//  jrk.setDerivativeCoefficient(Kd, 5);
//  jrk.setIntegralCoefficient(Ki, 1);
//    
//  }
