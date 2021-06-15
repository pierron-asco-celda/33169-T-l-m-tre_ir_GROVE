# 33169-Telemetre ir GROVE

Telemetre ir GROVE [33169](https://www.pierron.fr/telemetre-ir-grove.html)

<div style="text-align: justify">Le capteur de proximité infrarouge de 80 cm est un capteur de mesure de distance de type à usage général. Ce capteur SHARP GP2Y0A21YK, bénéficie d’un petit boîtier et d’une très faible consommation de courant. Il fait une lecture continue de distance et renvoie une tension analogique correspondante avec une plage de 10 cm à 80 cm.</div>

Caractéristiques techniques :
- Alimentation : 2,5 à 7 V (typiquement : 5 V)
- Consommation : 50 mA
- Plage de mesure : 10 à 80 cm

![L-33169](/img/L-33169.jpg)

# Usage :
Pour l’utilisation de ce module, référez-vous aux indications présentes sur le circuit imprimé GROVE.

# Complément sur la programmation :

À partir du moniteur série, vous obtenez la tension. vous pouvez ainsi calculer et trouver la distance à l’objet réfléchissant selon la figure ci-dessous.

![C-33169](/img/C-33169.jpg)

# RESSOURCES À TÉLÉCHARGER :

Ressource utilisation : [GP2Y0A21YK](https://github.com/pierron-asco-celda/33169-Telemetre_ir_GROVE/blob/main/src/Datasheet_GP2Y0A21YK.pdf)

# Exemple :
### Arduino / C++
```cpp
/*
    ** Mesure Distance SHARP 2Y0A21F5Y module Grove **
       PIN A0 Module shield GROVE
       Baud rate 9600 -> Moniteur série
*/


#define IR_PROXIMITY_SENSOR A0
#define ADC_REF 5

float voltage = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  voltage = getVoltage();
  Serial.print("Tension Capteur = " );
  Serial.print(voltage);
  Serial.println();
  delay(500);
}


float getVoltage() {
  int sensor_value;
  int sum;
  for (int i = 0; i < 20; i ++) 
  {
    sensor_value = analogRead(IR_PROXIMITY_SENSOR);
    sum += sensor_value;
  }
  sensor_value = sum / 20;
  float voltage;
  voltage = (float)sensor_value * ADC_REF / 1024;
  return voltage;
}
```
## À propos :

PIERRON ASCO-CELDA (https://www.pierron.fr).
