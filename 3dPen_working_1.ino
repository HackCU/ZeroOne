int sensorPin0 = A0;
int sensorPin1 = A1;
int ledPin = 13;      // select the pin for the LED
int sensorValue0 = 0;  // variable to store the value coming from the sensor
int sensorValue1 = 0;
int thresholdHigh=900;
int thresholdLow=120;
int state0=0;
int state1=0;
int previous0=0;
int previous1=0;
int side = 0;//0 is right, 1 is left;
int progState = 0;
int prevState = 0;
int n_magnets = 4;
float d_theta_sensor = 10.0;
float d_theta_magnet = 360.0/(float)n_magnets;
float anglePos = 0.0;
void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);  
}

void loop() {
  // read the value from the sensor:
  prevState = progState;
  previous0 = state0;
  previous1 = state1;
  sensorValue0 = analogRead(sensorPin0);
  sensorValue1 = analogRead(sensorPin1);
  if(sensorValue0 >= thresholdHigh){
    state0 = 1;
    if(sensorValue1 >= thresholdHigh){
      state1 = 1;
      progState = 3;
      if(prevState == 1)
      {
        if(side == 1){
          anglePos = anglePos - d_theta_sensor;
          side = 0;
        }
        else{
          anglePos = anglePos - d_theta_magnet;
          side = 0;
        }
      }
      else if(prevState == 2)
      {
        if(side == 1){
          anglePos = anglePos + d_theta_magnet;
          side = 1;
        }
        else{
          anglePos = anglePos + d_theta_sensor;
          side = 1;
        }
      }
    }
    else if(sensorValue1 <= thresholdLow){
      state1 = 0;
      progState = 2;
      if(prevState == 3)
      {
        if(side == 1){
          anglePos = anglePos - d_theta_magnet;
          side = 1;
        }
        else{
          anglePos = anglePos - d_theta_magnet + d_theta_sensor;
          side = 1;
        }
      }
      else if(prevState == 0)
      {
        if(side == 1){
          anglePos = anglePos + d_theta_magnet - d_theta_sensor;
          side = 2;
        }
        else{
          anglePos = anglePos + d_theta_magnet;
          side = 2;
        }
      }
    }
  }
  else if(sensorValue0 <= thresholdLow){
    state0 = 0;
    if(sensorValue1 >= thresholdHigh){
      state1 = 1;
      progState = 1;
      if(prevState == 3)
      {
        if(side == 1){
          anglePos = anglePos + d_theta_magnet - d_theta_sensor;
          side = 0;
        }
        else{
          anglePos = anglePos + d_theta_magnet;
          side = 0;
        }
      }
      else if(prevState == 0)
      {
        if(side == 1){
          anglePos = anglePos - d_theta_magnet;
          side = 1;
        }
        else{
          anglePos = anglePos - d_theta_magnet + d_theta_sensor;
          side = 1;
        }
      }
    }
    else if(sensorValue1 <= thresholdLow){
      state1 = 0;
      progState = 0;
      if(prevState == 1)
      {
        if(side == 1){
          anglePos = anglePos + d_theta_magnet;
          side = 1;
        }
        else{
          anglePos = anglePos + d_theta_sensor;
          side = 1;
        }
      }
      else if(prevState == 2)
      {
        if(side == 1){
          anglePos = anglePos - d_theta_sensor;
          side = 0;
        }
        else{
          anglePos = anglePos - d_theta_magnet;
          side = 0;
        }
      }
    }
  }
  
  Serial.print("Values: ");
  Serial.print(sensorValue0);
  Serial.print("  ");
  Serial.print(sensorValue1);
  Serial.print("    State: ");
  Serial.print(state0);
  Serial.print(" ");
  Serial.print(state1);
  Serial.print("    Progress State: ");
  Serial.print(progState);
  Serial.print("    Previous State: ");
  Serial.print(prevState);
  Serial.print("    Angle Position: ");
  Serial.print(anglePos);
  Serial.print("    Trigger side: ");
  Serial.print(side);
  Serial.println();
  
  delay(10);          
  
}
