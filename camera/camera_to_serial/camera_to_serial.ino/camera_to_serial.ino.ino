/*
  Tweaked from
  Harvard University 
  tinyMLx - OV7675 Camera Test for TinyML applications
  By - Anshu Bhatt

*/

#include <TinyMLShield.h>

bool commandRecv = false; // flag used for indicating receipt of commands from serial port
bool liveFlag = false; // flag as true to live stream raw camera bytes, set as false to take single images on command
bool captureFlag = false;

// Image buffer;
byte image[176 * 144 * 2]; // QCIF: 176x144 x 2 bytes per pixel (RGB565)
int bytesPerFrame;

void setup() {
  Serial.begin(115200);
  while (!Serial);

  initializeShield();

  // Initialize the OV7675 camera
  if (!Camera.begin(QCIF, RGB565, 1, OV7675)) {
    Serial.println("Failed to initialize camera");
    while (1);
  }
  bytesPerFrame = Camera.width() * Camera.height() * Camera.bytesPerPixel();

  Serial.println("Welcome to the OV7675 Raw Bytes to Serial Test\n");
}

void loop() {
  int i = 0;
  String command;

  bool clicked = readShieldButton();
  if (clicked) {
      if (!captureFlag) {
        captureFlag = true;
        Serial.println("\nRaw image data will begin streaming in 5 seconds...");
        delay(5000);
      }
  }
    
  if (captureFlag) {
    captureFlag = false;
    Camera.readFrame(image);
    Serial.write(image, bytesPerFrame);
    Serial.println();
  }
  
}
