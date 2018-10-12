
void calcSteeringPID(void) {
  
  pValue = steerAngleSetPoint*steerSensorCounts+steeringPositionZero;
   }

 void motorDrive(void) 
  {
    jrk.setTarget(pValue);
  }
  
  
  
// distance steer
  //void calcSteeringPID(void) {
  //if (distanceFromLine > 1800) distanceFromLine = 1800;
//if (distanceFromLine < -1800) distanceFromLine = -1800;
 //  pValue = steeringPositionZero-distanceFromLine;
 //  }
  
   
  
  
//void updatejrk(){
//  jrk.setProportionalCoefficient(Kp, 1);
//  jrk.setDerivativeCoefficient(Kd, 5);
//  jrk.setIntegralCoefficient(Ki, 1);
//    
//  }
