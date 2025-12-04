# TP Brasrobotisé à2degrésdeliberté

## DFRobotFirebeetle2
En premier nous avons installer arduino et mis en place une com Serial qui envoie simplement un Print, pour s'assurer de la bonne prise en main du micro controleur
```c
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}


void loop() {
  Serial.println("Hello!");
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
```

