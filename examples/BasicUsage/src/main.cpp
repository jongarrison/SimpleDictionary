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
SimpleDictionary<int, 10, 20> IntDictionary;
SimpleDictionary<float, 10, 20> FloatDictionary;
// SimpleDictionary<string> CharDictionary;
SimpleDictionary<char*, 10, 20> CharDictionary;
SimpleDictionary<std::array<char, 20>, 10, 20> CharArrayDictionary;

void setup() {
  Serial.begin(115200);
  IntDictionary["Red"] = 100;

  FloatDictionary["Cube"] = 1.2;

  CharDictionary["CharA"] = "CDE";

  sprintf(CharArrayDictionary["CharArray"].data(),"TestCharArray%d", millis());
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(millis());
  IntDictionary["Red"] = millis();
  Serial.print("Red:");
  Serial.println(IntDictionary["Red"]);

  Serial.print("Cube:");
  FloatDictionary["Cube"] = millis();
  Serial.println(FloatDictionary["Cube"]);

  Serial.print("CharA:"); 
  char buffer[20];
  sprintf(buffer, "t%d", millis());
  CharDictionary["CharA"] = buffer;
  Serial.println(CharDictionary["CharA"]);

  Serial.print("CharArray:"); 
  sprintf(CharArrayDictionary["CharArray"].data(),"TestCharArray%d", millis());
  Serial.println(CharArrayDictionary["CharArray"].data());

  Serial.println("");
  delay(3000);

}