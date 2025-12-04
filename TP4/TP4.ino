#include <math.h>
#include "Plotter.h"
Plotter p;
float L1 = 15; // cm
float L2 = 10; // cm
float O1 = 15; // °
float O2 = 10; // °
float x, y;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  p.Begin();
  p.AddXYGraph("Position Robot", 16001, "X", x,"Y",y);  // graphe pour x
  delay(1000);
}


void calcule_position()
{
  x = L1*cos(O1*(PI / 180.0))+L2*cos((O1+O2)*(PI / 180.0));
  y = L1*sin(O1*(PI / 180.0))+L2*sin((O1+O2)*(PI / 180.0));
}

int calcul_omega()
{
  return asin(y/(sqrt((y*y)+(x*x))))*(180.0 / M_PI);
}


int calcul_beta()
{
  return acos((x*x+y*y+L1*L1-L2*L2)/(2*L1*(x*x+y*y)));
}


int calcul_gama()
{
  return acos((x*x+y*y-L1*L1+L2*L2)/(2*L2*(x*x+y*y)));
}


void calcul_angles()
{
  int beta = calcul_beta();
  int gama = calcul_gama();
  int omega = calcul_omega();
  O1 = omega - beta;
  O2 = omega + gama;
}


void print_resultat() {
  Serial.print("x:"); 
  Serial.print(x);
  Serial.print("\t");  // Tabulation pour séparer les variables
  Serial.print("y:");
  Serial.println(y);

}


void loop() {
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
  //

}
