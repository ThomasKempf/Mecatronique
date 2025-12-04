# TP Brasrobotisé à2degrésdeliberté

## Partie 2

### DFRobotFirebeetle2
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

### Etape a-b
En utilisant le trigonometrie, on trouve les cooronnée du point P en fonction des angles
```c
x = L1*cos(O1*(M_PI / 180.0))+L2*cos((O1+O2)*(M_PI / 180.0));
y = L1*sin(O1*(M_PI / 180.0))+L2*sin((O1+O2)*(M_PI / 180.0));
```

### Etape c
En mettant 0 et 90 pour la valerus des angles, nous avons optenue x = 15 et y = 10, ce qui correspond à la réalité

### Etape d
On fait varier les deux angles avec une double boucle for pour ensuite représenter toutes les positions possible de la pince via le listner
```c
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
```
<img src="./Etape_d.png" alt="Etape_d" width="300">

## Partie 2

### Etape a - b
En appliquant le theoreme d'Al-kashi on trouve les angles Gama et Beta. On calcule O1 et O2 avec ces angles

<img src="./alkashi.png" alt="Alkashi" width="300">

```c
void calcul_angles()
{
  int beta = calcul_beta();
  int gama = calcul_gama();
  int omega = calcul_omega();
  O1 = omega - beta;
  O2 = omega + gama;
}
```

### Etape c
en testant notre programme avec x = 25 et y = 0 nous obtenons:

    beta:0.00
    gama:0.00
    omega:0.00
    x:25.00
    y:0.00

ce qui correspond à la réalité


### Etape d
Nous avons ensuite écris un programme permetant de décrire un cercle de rayon 7cm
```c
void representation_cercle()
{
  float rayon = 7;
  float pas = 3.6;
  for (int i=0;i <= 360; i++)
  {
    calcul_yx_cercle(rayon,i);
    p.Plot();
    delay(pas); // 0.1s par valeur
  }
}
```
<img src="./rond.png" alt="rond" width="300">