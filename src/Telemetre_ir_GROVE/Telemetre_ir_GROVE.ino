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
