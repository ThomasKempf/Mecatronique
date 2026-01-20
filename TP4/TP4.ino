#include <math.h>
#include "Plotter.h"
Plotter p;
float L1 = 15; // cm
float L2 = 10; // cm
float O1 = 15; // °
float O2 = 10; // °
float x, y , t;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  p.Begin();
  p.AddXYGraph("Position Robot", 16001, "T", t,"O2",O2);  // graphe pour x
  delay(1000);
}


void calcule_position()
{
  x = L1*cos(O1*(PI / 180.0))+L2*cos((O1+O2)*(PI / 180.0));
  y = L1*sin(O1*(PI / 180.0))+L2*sin((O1+O2)*(PI / 180.0));
}


int calcul_omega()
{
  return asin(y/(sqrt((y*y)+(x*x))))*(180.0 / PI);
}


int calcul_beta()
{
  return acos((x*x+y*y+L1*L1-L2*L2)/(2*L1*sqrt(x*x+y*y)))*(180.0 / PI);
}


int calcul_gama()
{
  return acos((x*x+y*y-L1*L1+L2*L2)/(2*L2*sqrt(x*x+y*y)))*(180.0 / PI);
}


void calcul_angles()
{
  float beta = calcul_beta();
  float gama = calcul_gama();
  float omega = calcul_omega();
  O1 = omega - beta;
  float z;
  z = 180-gama-beta;
  O2 = 180 - z;
}


void print_resultat() {
  Serial.print("x:"); 
  Serial.println(x);
  Serial.print("y:");
  Serial.println(y);
  Serial.print("O1:"); 
  Serial.println(O1);
  Serial.print("O2:");
  Serial.println(O2);

}


void representation_position_pince()
{
  for (int i=0;i <= 90; i++)
  {
    for (int j=0;j <= 180; j++)
    {
      O1 = float(i);
      O2 = float(j);
      calcule_position();
      p.Plot();
      delay(10);
    }
  }
}


void calcul_yx_cercle(float rayon,float angle)
 {
  y = 4;
  x = 12;
  float xr = rayon*cos(angle*(PI / 180.0));
  float yr = rayon*sin(angle*(PI / 180.0));
  x = x + xr;
  y = y + yr;
 }


void representation_cercle()
{
  float rayon = 7;
  float pas = 3.6;
  t = 0;
  for (int i=0;i <= 360; i++)
  {
    calcul_yx_cercle(rayon,i);
    calcul_angles();
    calcule_position();
    p.Plot();
    delay(pas); // 0.1s par valeur
    t = t + 0.01;
  }
}


void loop() 
{
  representation_cercle();
}
