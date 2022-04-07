#include <dht11.h>
#define DHT11PIN 4

dht11 DHT11;

int pos = 0;
bool valveOpened = false;

// 250  100%
// 1050 0%  

void setup()
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  int chk = DHT11.read(DHT11PIN);
  int moist = analogRead(A5);
  float moistPercent = basedMap(moist, 1100, 250, 0, 100);

  Serial.print("H");
  Serial.println(DHT11.humidity);

  Serial.print("T");
  Serial.println(DHT11.temperature);

  Serial.print("S");
  Serial.println((int)moistPercent);


//  if (moistPercent > 0.05) {
//    analogWrite(8, 255);
//    Serial.println("WATER");
//  } else {
//    analogWrite(8, 0);    
//    Serial.println("NONE");
//  }

  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  
  delay(1000);
  
}

float basedMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
