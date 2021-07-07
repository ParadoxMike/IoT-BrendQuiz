//here is everything LCD related

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //create new lcd object

//do all neccesarry setup
void setupLCD(){
  lcd.init();                   
  lcd.backlight();
}