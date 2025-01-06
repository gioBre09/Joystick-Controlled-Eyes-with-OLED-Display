#include <Adafruit_GFX.h>
    #include <Adafruit_SSD1306.h>
    
    #define SCREEN_WIDTH 128
    #define SCREEN_HEIGHT 64
    #define OLED_RESET    -1
    Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
    
    // Joystick pins
    #define JOYSTICK_X A0
    #define JOYSTICK_Y A1
    #define JOYSTICK_BUTTON 2
    
    void setup() {
      pinMode(JOYSTICK_BUTTON, INPUT_PULLUP);
      
      if (!display.begin(SSD1306_I2C_ADDRESS, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);
      }
    
      display.clearDisplay();
      display.display();
    }
    
    void drawEye(int x, int y) {
      // Draw eyes outline
      display.drawCircle(32, 32, 15, SSD1306_WHITE); // Left eye
      display.drawCircle(96, 32, 15, SSD1306_WHITE); // Right eye
    
      // Draw pupils
      display.fillCircle(32 + x, 32 + y, 5, SSD1306_WHITE); // Left pupil
      display.fillCircle(96 + x, 32 + y, 5, SSD1306_WHITE); // Right pupil
    }
    
    void drawEyelids() {
      // Draw eyelids (closed eyes)
      display.drawLine(17, 32, 47, 32, SSD1306_WHITE);  // Left eye
      display.drawLine(81, 32, 111, 32, SSD1306_WHITE); // Right eye
    }
    
    void loop() {
      int joystickX = analogRead(JOYSTICK_X);
      int joystickY = analogRead(JOYSTICK_Y);
      bool buttonPressed = !digitalRead(JOYSTICK_BUTTON);
    
      // Map joystick values to pupil range (-7 to +7)
      int pupilX = map(joystickX, 0, 1023, -7, 7);
      int pupilY = map(joystickY, 0, 1023, -7, 7);
    
      display.clearDisplay();
    
      if (buttonPressed) {
        drawEyelids(); // Close eyes when button is pressed
      } else {
        drawEye(pupilX, pupilY); // Move pupils based on joystick
      }
    
      display.display();
      delay(50); // Smooth animation
    }