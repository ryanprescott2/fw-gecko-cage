#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 32  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library.
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS \
  0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

#include <Adafruit_SSD1306.h>
#include <Wire.h>

class GeckoDisplay {
 public:
  GeckoDisplay(uint8_t screen_width, uint8_t screen_height)
      : display_{screen_width, screen_height, &Wire, OLED_RESET} {}

  void Init() {
    // Show initial display buffer contents on the screen --
    // the library initializes this with an Adafruit splash screen.
    display_.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);

    display_.display();
    delay(2000);  // Pause for 2 seconds

    // Clear the buffer
    display_.clearDisplay();

    // Draw a single pixel in white
    display_.drawPixel(10, 10, SSD1306_WHITE);
  }

  void WriteTemperature(uint8_t temp) {
    display_.clearDisplay();

    display_.setTextSize(1);  // Normal 1:1 pixel scale
    display_.setTextColor(SSD1306_BLACK, SSD1306_WHITE);  // Draw 'inverse' text
    display_.setCursor(0, 0);  // Start at top-left corner
    display_.println(F("Hello, world!"));
  }

  void WriteTime(uint8_t time) {}

 private:
  Adafruit_SSD1306 display_;
};