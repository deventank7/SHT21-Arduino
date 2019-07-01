#include <Wire.h>
#include <Arduino.h>

#define SHT21_ADDRESS 0x40  //I2C address for the sensor

#define TRIGGER_TEMP_MEASURE_NOHOLD  0xF3
#define TRIGGER_HUMD_MEASURE_NOHOLD  0xF5

float temperature, humidity;
char temp[4], hum[4];

void setup()
{
  Wire.begin(18, 19);
  Serial.begin(115200);
}

void loop()
{

  temperature = getTemperature();
  humidity = getHumidity();
  sprintf(temp, "%f", temperature);
  Serial.print("Temperature is ");
  Serial.println(temp);
  sprintf(hum, "%f", humidity);
  Serial.print("Humidity is ");
  Serial.println(hum);
  delay(2000);
}

