
#include <Wire.h>
#include <SparkFun_ADS1219.h>
#include <LiquidCrystal_I2C.h>

ADS1219 adc;  // handle
const float Rf = 22e6; // Your TIA feedback resistor (1 MΩ)

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22); // SCL = GPIO21, SDA = GPIO22 assumed
  if (!adc.begin()) {
    Serial.println("ADS1219 not found!");
    while (1);
  }

  adc.setMode(ADS1219_MODE_CONTINUOUS);
  adc.setDataRate(ADS1219_DR_20SPS);
  adc.setGain(ADS1219_GAIN1);
  adc.setMux(ADS1219_CH_DIFF0);
  
  Wire.beginTransmission(ADS1219_ADDR);
  Wire.write(REG_CONFIG);         // e.g. the config register address
  Wire.write(newConfigBits);      // bit-fields for mode/rate/gain/mux
  Wire.endTransmission();

  delay(100);
  adc.startConversion();
}

void loop() {
  // put your main code here, to run repeatedly:

}
m