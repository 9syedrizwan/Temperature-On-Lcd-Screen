#define temp A0
#include <LiquidCrystal.h>
LiquidCrystal led(2,3,4,5,6,7);
void setup()
{
  pinMode(temp,INPUT);
  Serial.begin(9400);
  led.begin(16,2);
}

void loop()
{
  int RawValue=analogRead(temp);
  float Voltage=(RawValue/1023.0)*5000;
  float tempC=(Voltage-500)*0.1;
  Serial.print("Temperature in C = ");
  Serial.println(tempC,1);
  int humidity = analogRead(temp);
  Serial.print("Humidity:");
  Serial.print(map(humidity,0,1023,10,70));
  Serial.print("%");
  Serial.println("--------------------");
  
  led.setCursor(0,0);
  led.print("temp ");
  led.print(tempC);
  led.print("C");
  
  
  led.setCursor(0,1);
  led.print("humidity ");
  led.print(humidity);
  led.print("%");
  
  
  
  
  
  
}
