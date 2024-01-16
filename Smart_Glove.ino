/* 
  Smart Glove

  Flex1         : Give Me Medicine   Finger1
  Flex2         : I am Hungry        Finger2
  Flex3         : I am thirsty       Finger3
  Flex4         : I Need Help        Finger4
  Flex5         : I feel pain        Finger5
  Flex1_2       : How are you        Finger1,2
  Flex3_4       : Nice to meet you   Finger3,4
  Flex1_2_3     : Thank You          Finger1,2,3
  Flex1_2_3_4   : Understand you     Finger1,2,3,4
  Flex1_2_3_4_5 : You are welcome    Finger1,2,3,4,5
*/

#include <Wire.h>                 // I2C communication
#include <LiquidCrystal_I2C.h>    // using I2C-based LCD
#include <SoftwareSerial.h>       // serial communication on digital pins
#include <DFRobotDFPlayerMini.h>  // control the DFPlayer Mini MP3 module

LiquidCrystal_I2C lcd(0X27, 16, 2);  // 0x27 Address of LCD on i2c | Tinkercad 0x20 -> PCF8574
unsigned int d = 20, d1 = 250, d2 = 380, d3 = 390, d4 = 400, d5 = 345; // d -> volume of sound
const int FlexSensorPin1 = A0;
const int FlexSensorPin2 = A1;
const int FlexSensorPin3 = A2;
const int FlexSensorPin4 = A3;
const int FlexSensorPin5 = A6; 

static const uint8_t PIN_MP3_TX = 2;  // Connects to module's RX
static const uint8_t PIN_MP3_RX = 3;  // Connects to module's TX

SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
DFRobotDFPlayerMini player;           // Create the Player object

void setup() {
  pinMode(FlexSensorPin1, INPUT);
  pinMode(FlexSensorPin2, INPUT);
  pinMode(FlexSensorPin3, INPUT);
  pinMode(FlexSensorPin4, INPUT);
  pinMode(FlexSensorPin5, INPUT);

  Serial.begin(9600);
  softwareSerial.begin(9600);   // Beigning serial port for DFPlayer Mini
  player.begin(softwareSerial); // Start communication with DFPlayer Mini
  lcd.init();                   // Command to start running
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Smart Glove");
}

void loop() {
  int FlexSensorValue1 = analogRead(FlexSensorPin1);
  int FlexSensorValue2 = analogRead(FlexSensorPin2);
  int FlexSensorValue3 = analogRead(FlexSensorPin3);
  int FlexSensorValue4 = analogRead(FlexSensorPin4);
  int FlexSensorValue5 = analogRead(FlexSensorPin5);

  if ((FlexSensorValue1 < d1) && (FlexSensorValue2 < d2) && (FlexSensorValue3 < d3) && (FlexSensorValue4 < d4) && (FlexSensorValue5 < d5)) {
    player.volume(d);
    player.play(10);
    lcd.setCursor(0, 1);
    lcd.print("You are welcome ");
    Serial.println("You are welcome");
    delay(1000);
  } 
  else if ((FlexSensorValue1 < d1) && (FlexSensorValue2 < d2) && (FlexSensorValue3 < d3) && (FlexSensorValue4 < d4)) {
    player.volume(d);
    player.play(9);
    lcd.setCursor(0, 1);
    lcd.print("Understand you  ");
    Serial.println("Understand you");
    delay(1000);
  } 
  else if ((FlexSensorValue1 < d1) && (FlexSensorValue2 < d2) && (FlexSensorValue3 < d3)) {
    player.volume(d);
    player.play(8);
    lcd.setCursor(0, 1);
    lcd.print("Thank You       ");
    Serial.println("Thank You");
    delay(1000);
  } 
  else if ((FlexSensorValue1 < d1) && (FlexSensorValue2 < d2)) {
    player.volume(d);
    player.play(6);
    lcd.setCursor(0, 1);
    lcd.print("How are you     ");
    Serial.println("How are you");
    delay(1000);
  } 
  else if ((FlexSensorValue3 < d3) && (FlexSensorValue4 < d4)) {
    player.volume(d);
    player.play(7);
    lcd.setCursor(0, 1);
    lcd.print("Nice to meet you");
    Serial.println("Nice to meet you");
    delay(1000);
  } 
  else if (FlexSensorValue1 < d1) {
    player.volume(d);
    player.play(1);
    lcd.setCursor(0, 1);
    lcd.print("Give Me Medicine");
    Serial.println("Give Me Medicine");
    delay(1000);
  } 
  else if (FlexSensorValue2 < d2) {
    player.volume(d);
    player.play(2);
    lcd.setCursor(0, 1);
    lcd.print("I am Hungry     ");
    Serial.println("I am Hungry");
    delay(1000);
  } 
  else if (FlexSensorValue3 < d3) {
    player.volume(d);
    player.play(3);
    lcd.setCursor(0, 1);
    lcd.print("I am thirsty    ");
    Serial.println("I am thirsty");
    delay(1000);
  } 
  else if (FlexSensorValue4 < d4) {
    player.volume(d);
    player.play(4);
    lcd.setCursor(0, 1);
    lcd.print("I Need Help     ");
    Serial.println("I Need Help");
    delay(1000);
  } 
  else if (FlexSensorValue5 < d5) {
    player.volume(d);
    player.play(5);
    lcd.setCursor(0, 1);
    lcd.print("I feel pain     ");
    Serial.println("I feel pain");
    delay(1000);
  } 
  else {
    lcd.setCursor(0, 1);
    lcd.print("NO Signal       ");
    Serial.println("NO Signal");
  }

  delay(250);
}
