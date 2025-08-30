/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x32 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

#include "gecko_display.h"

class GeckoCage {
 public:
  enum class CageState {
    kDaytime = 0,
    kNighttime = 1,
  };

  static constexpr uint8_t kScreenHeight = 64;
  static constexpr uint8_t kScreenWidth = 128;

  void Init() { gecko_display_.Init(); }

  void HandleDisplayUpdate(uint8_t temperature, uint8_t time, CageState state) {
    gecko_display_.WriteTemperature(temperature);
    gecko_display_.WriteTime(time);
  }

 private:
  GeckoDisplay gecko_display_{kScreenWidth, kScreenHeight};
  CageState state_ = CageState::kDaytime;
};

GeckoCage gecko_cage;
void setup() { gecko_cage.Init(); }

void loop() {
  delay(1000);

  gecko_cage.HandleDisplayUpdate(100, 4, GeckoCage::CageState::kDaytime);
  // read temperature
  // read time
  // set relay
  // update display
}