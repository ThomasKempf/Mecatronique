# TP Communication avec une centrale inertielle

## 2 Mise en place de la communication avec les capteurs

### Question 1 :
c'est une communication I2C c'est asynchrone sans clock et on retrouve les deux fils SDA et SCL

### Question 2 :
nous avons compilé le programme exemple dans le microcontroleur relié au capteur. Nous avons relier SDA du capteur à celui du microcontroleur et de même pour le SCL

### Question 3 :
<img src="./Capture_1.png" alt="rond" width="300">



## 3 Calcul de l’attitude :

### Question 1 :
```c
void calcRoulis(){
  r = atan2f(ay,sign(az)*sqrt(0.01*(ax*ax)+(az*az)));
}

void calcTangage(){
  tang = atan2f(-ax,sqrt((ay*ay)+(az*az)));
}

int sign(float param){
  if (param >= 0){
    return 1;
  }
  else{
    return -1;
  }
}
```

### Question 2 :
<img src="./roulis_tang.png" alt="rond" width="300">

### Question 3 :
```c
void calcRoulisG(){
  r = r + gx*time_delay;
}

void calcTangageG(){
  tang = tang + gy*time_delay;
}
```
<img src="./calc_giro.png" alt="rond" width="300">