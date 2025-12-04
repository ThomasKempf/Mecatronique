#include <math.h>
uint8_t L1 = 15; # cm
uint8_t L2 = 10; # cm
uint8_t O1 = 15; # °
uint8_t O2 = 10; # °
uint8_t x = 0; # cm
uint8_t y = 0; # cm

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}


int calcule_position()
{
  x = L1*cos(O1)+L2*cos(O1+O2);
  y = L1*sin(O1)+L2*sin(O1+O2);
}


void print_resultat() {
    const char* labels[] = {"x", "y", "O1", "O2"};
    uint8_t* values[] = {&x, &y, &O1, &O2};
    uint8_t nbr_values = 4
    for (uint8_t i = 0; i < nbr_values; i++) 
    {
        Serial.print(labels[i]);
        Serial.print(" = ");
        Serial.println(*values[i]);
    }
}


void loop() {
  Serial.println("Hello!");
  digitalWrite(LED_BUILTIN, HIGH); 
  delay(1000);                      
  digitalWrite(LED_BUILTIN, LOW);  
  delay(1000);   
  O1 = 0
  O2 = 0
  calcule_position()
  print_resultat()
  //

}
