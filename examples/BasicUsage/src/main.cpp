#include <Arduino.h>
#include "SimpleDictionary.h"
#include <string>
#include <array>

//Adafruit nRF52840 Feather Express requires Adafruit_TinyUSB library for Serial
//See: https://learn.adafruit.com/introducing-the-adafruit-nrf52840-feather/arduino-board-setup#4-run-a-test-sketch-2860620
#if defined(USE_TINYUSB) 
#include <Adafruit_TinyUSB.h> // for Serial
#endif

constexpr size_t ElementSize = 10, KeySize = 20;


//Creating a few different sample dictionaries to show handling of different types
SimpleDictionary<int, 10, 20> IntDictionary;
SimpleDictionary<float, 10, 20> FloatDictionary;
SimpleDictionary<char*, 10, 20> CharDictionary;
SimpleDictionary<std::array<char, 20>, 10, 20> CharArrayDictionary;

char* floatDicName = "floats";
char* intDicName = "ints";
char* charPointerDicName = "charPointers";
char* charArrayDicName = "charArrays";

void setup() {
  Serial.begin(115200);
  IntDictionary[intDicName] = 100;

  FloatDictionary[floatDicName] = 1.2;

  CharDictionary[charPointerDicName] = "CDE";

  sprintf(CharArrayDictionary[charArrayDicName].data(),"TestCharArray%d", millis());
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(millis());
  IntDictionary[intDicName] = millis();
  Serial.print(intDicName);
  Serial.print(":");
  Serial.println(IntDictionary[intDicName]);

  Serial.print(floatDicName);
  Serial.print(":");
  FloatDictionary[floatDicName] = millis();
  Serial.println(FloatDictionary[floatDicName]);

  Serial.print(charPointerDicName);
  Serial.print(":"); 
  char buffer[20];
  sprintf(buffer, "t%d", millis());
  CharDictionary[charPointerDicName] = buffer;
  Serial.println(CharDictionary[charPointerDicName]);

  Serial.print(charArrayDicName); 
  Serial.print(":"); 
  sprintf(CharArrayDictionary[charArrayDicName].data(),"TestCharArray%d", millis());
  Serial.println(CharArrayDictionary[charArrayDicName].data());

  Serial.println("");
  delay(3000);

}