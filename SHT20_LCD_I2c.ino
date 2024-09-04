#include "DFRobot_SHT20.h"
#include<LiquidCrystal_I2C.h>

DFRobot_SHT20 sht20(&Wire, SHT20_I2C_ADDR);
LiquidCrystal_I2C lcd(0x27,16,4);
/*
Yellow - SDA - 21
Green - SCL - 22
*/
void setup()
{
  Serial.begin(115200);
  lcd.init();
  // Init SHT20 Sensor
  sht20.initSHT20();
  delay(100);
  Serial.println("Sensor init finish!");
  lcd.backlight();
  lcd.setBacklight(HIGH);
  sht20.checkSHT20();
}

void loop()
{

  float humd = sht20.readHumidity();
  float temp = sht20.readTemperature();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp, 1);
  lcd.print("C\n");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humd, 1);
  lcd.print("%\n");
  delay(2000);
}
