
void calcSteeringPID(void) {
  
if (distanceFromLine <50 && distanceFromLine >-50)
{ //Proportional
  pValue = steerAngleSetPoint*steerSensorCounts+steeringPositionZero;
  pValue = pValue + distanceFromLine*Ko*0.1;
  }
else
{
   //Proportional
  pValue = steerAngleSetPoint*steerSensorCounts+steeringPositionZero;
  } 
 }

 void motorDrive(void) 
  {
    jrk.setTarget(pValue);
  }

void updatejrk(){
  jrk.setProportionalCoefficient(Kp, 1);
  jrk.setDerivativeCoefficient(Kd, 5);
  jrk.setIntegralCoefficient(Ki, 1);
    
  }
