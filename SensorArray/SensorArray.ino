#include <dht11.h>
#define DHT11PIN 4

dht11 DHT11;

// 250  100%
// 1050 0%  

void setup()
{
  Serial.begin(9600);
  
}

void loop()
{
  int chk = DHT11.read(DHT11PIN);
  int moist = analogRead(A5);
  float moistPercent = basedMap(moist, 1050, 250, 0, 1);

  Serial.print(yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy\ ty, 2);

  Serial.print("T");
  Serial.println((float)DHT11.temperature, 2);

  Serial.print("S");
  Serial.println(moistPercent);

  delay(2000);
  
}

float basedMap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
