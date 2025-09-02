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
#include <DHT.h>
#include <DHT_U.h>
#include <SPI.h>
#include <Wire.h>

#include "gecko_display.h"

#define DHTPIN 2       // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11  // DHT 11

/*!
 *  @brief  Converts Celcius to Fahrenheit
 *  @param  c
 *					value in Celcius
 *	@return float value in Fahrenheit
 */
static float ConvertTempCtoF(float c) { return c * 1.8 + 32; }

class GeckoCage {
 public:
  static constexpr uint8_t kScreenHeight = 64;
  static constexpr uint8_t kScreenWidth = 128;
  static constexpr uint8_t kDhtSensorPin = 2;
  static constexpr uint8_t kDhtType = DHT11;

  enum class CageState {
    kDaytime = 0,
    kNighttime = 1,
  };

  void Init() {
    gecko_display_.Init();
    dht_.begin();
    dht_.temperature().getSensor(&dht_sensor_);
    dht_.humidity().getSensor(&dht_sensor_);
    delay_ms_ = dht_sensor_.min_delay / 1000;
  }

  void HandleDisplayUpdate(int temp, int humidity, uint8_t time,
                           CageState state) {
    gecko_display_.WriteEnvironment(temp, humidity);
    gecko_display_.WriteTime(time);
  }

  void ExecuteCageCycle() {
    // read temperature and humidity
    float temp = 0.0;
    float humidity = 0.0;
    if (!MeasureEnvironment(&temp, &humidity)) {
      gecko_display_.DisplayError("DHT11 err");
    }
    int temp_i = temp * 100;
    int humidity_i = humidity * 100;

    // read time

    // set relay state based on time

    // update display
    HandleDisplayUpdate(temp_i, humidity_i, 0, CageState::kDaytime);
  }

  bool MeasureEnvironment(float* temperature, float* humidity) {
    sensors_event_t event;
    dht_.temperature().getEvent(&event);
    if (isnan(event.temperature)) {
      return false;
    } else {
      *temperature = ConvertTempCtoF(event.temperature);
    }
    // Get humidity event and print its value.
    dht_.humidity().getEvent(&event);
    if (isnan(event.relative_humidity)) {
      return false;
    } else {
      *humidity = event.relative_humidity;
    }
    return true;
  }

  uint32_t delay_ms_ = 0;

 private:
  GeckoDisplay gecko_display_{kScreenWidth, kScreenHeight};
  CageState state_ = CageState::kDaytime;
  DHT_Unified dht_{kDhtSensorPin, kDhtType};
  sensor_t dht_sensor_;
};

GeckoCage gecko_cage;
void setup() {
  gecko_cage.Init();
  Serial.begin(9600);
}

void loop() {
  gecko_cage.ExecuteCageCycle();
  // gecko_cage.HandleDisplayUpdate(100, 4, GeckoCage::CageState::kDaytime);
  // read temperature
  // read time
  // set relay
  // update display
  delay(5000);
}