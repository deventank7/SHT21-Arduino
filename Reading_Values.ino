int readSHT21(uint8_t command)
{
  uint16_t result;

  Wire.beginTransmission(SHT21_ADDRESS);
  Wire.write(command);
  Wire.endTransmission();
  delay(100);

  Wire.requestFrom(SHT21_ADDRESS, 3);
  while (Wire.available() < 3) {
  delay(1);
  }

  // return result
  result = ((Wire.read()) << 8);
  result += Wire.read();
  result &= ~0x0003;   // clear two low bits (status bits)
  return result;
}

float getHumidity()

{
  return (-6.0 + 125.0 / 65536.0 * (float)(readSHT21(TRIGGER_HUMD_MEASURE_NOHOLD)));
}

float getTemperature()
{
  return (-46.85 + 175.72 / 65536.0 * (float)(readSHT21(TRIGGER_TEMP_MEASURE_NOHOLD)));
}

