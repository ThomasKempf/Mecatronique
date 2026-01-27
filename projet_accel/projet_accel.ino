//Libraries
#include <Wire.h>//https://www.arduino.cc/en/reference/wire
#include <Adafruit_MPU6050.h>//https://github.com/adafruit/Adafruit_MPU6050
#include <Adafruit_Sensor.h>//https://github.com/adafruit/Adafruit_Sensor
#include <math.h>
#include "Plotter.h"

Plotter p;
float ax,ay,az,gx,gy,gz,temperature,r,tang,t = 0;
int time_delay = 10;

//Objects
Adafruit_MPU6050 mpu;

void setup() {
  //Init Serial USB
  Serial.begin(115200);
  
  p.Begin();
  p.AddXYGraph("roulis", 16001, "T", t,"roulis",r);  // graphe pour x
  p.AddXYGraph("tangage", 16001, "T", t,"tangage",tang);  // graphe pour y

 if (!mpu.begin(0x68)) { // Change address if needed
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  readMPU();
  calcRoulisA();
  calcTangageA();
}

void loop() {
  delay(time_delay);
  t = t + 0.1;
  readMPU();
  calcRoulisAG();
  calcTangageAG();
  p.Plot();
}

void readMPU( ) { /* function readMPU */
  ////Read acceleromter data
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  ax = a.acceleration.x;
  ay = a.acceleration.y;
  az = a.acceleration.z;
  gx = g.gyro.x;
  gy = g.gyro.y;
  gz = g.gyro.z;
  temperature = temp.temperature;
}


void printParam(){
  /* Print out the values */
  Serial.print("Acceleration X: ");
  Serial.print(ax);
  Serial.print(", Y: ");
  Serial.print(ay);
  Serial.print(", Z: ");
  Serial.print(az);
  Serial.println(" m/s^2");

  Serial.print("Rotation X: ");
  Serial.print(gx);
  Serial.print(", Y: ");
  Serial.print(gy);
  Serial.print(", Z: ");
  Serial.print(gz);
  Serial.println(" rad/s");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");


}


int sign(float param){
  if (param >= 0){
    return 1;
  }
  else{
    return -1;
  }
}


void calcRoulisAG(){
  float alpha = 0.05;
  calcRoulisG();
  float rG = r;
  calcRoulisA();
  float rA = r;
  r = ((1-alpha)*rG)+(alpha*rA);
}


void calcTangageAG(){
  float alpha = 0.05;
  calcTangageG();
  float tG = tang;
  calcTangageA();
  float tA = tang;
  tang = ((1-alpha)*tG)+(alpha*tA);
}


void calcRoulisG(){
  r = r + gx*time_delay/1000;
}


void calcTangageG(){
  tang = tang + gy*time_delay/1000;
}


void calcRoulisA(){
  r = atan2f(ay,sign(az)*sqrt(0.01*(ax*ax)+(az*az)));
}


void calcTangageA(){
  tang = atan2f(-ax,sqrt((ay*ay)+(az*az)));
}