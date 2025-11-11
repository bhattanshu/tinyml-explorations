/*
  Tweaked from
  Harvard University 
  tinyMLx - OV7675 Camera Test for TinyML applications
  By - Anshu Bhatt

*/

#include <TinyMLShield.h>

// Image buffer;
byte image[176 * 144 * 2]; // QCIF: 176x144 x 2 bytes per pixel (RGB565)
int bytesPerFrame;
int bytesPerPixel;

inline void rgb565_rgb888(uint8_t* in, uint8_t* out) {
  uint16_t p = (in[0] << 8) | in[1];

  out[0] = ((p >> 11) & 0x1f) << 3;
  out[1] = ((p >> 5) & 0x3f) << 2;
  out[2] = (p & 0x1f) << 3;
}

void setup() {
  Serial.begin(115200);
  while (!Serial);

  initializeShield();

  // Initialize the OV7675 camera
  if (!Camera.begin(QCIF, RGB565, 1, OV7675)) {
    Serial.println("Failed to initialize camera");
    while (1);
  }
  bytesPerPixel = Camera.bytesPerPixel();
  bytesPerFrame = Camera.width() * Camera.height() * Camera.bytesPerPixel();
  // Camera.testPattern();

  Serial.println("Welcome to the OV7675 Raw Bytes to Serial Test\n");
}

void loop() {

  bool clicked = readShieldButton();
  if (clicked) {
    Camera.readFrame(image);
    uint8_t rgb888[3];
    Serial.println("<image>");
    Serial.println(Camera.width());
    Serial.println(Camera.height());
    for(int32_t i = 0; i < bytesPerFrame; i+=bytesPerPixel) {
      rgb565_rgb888(&image[i], &rgb888[0]);
      Serial.println(rgb888[0]);
      Serial.println(rgb888[1]);
      Serial.println(rgb888[2]);
    }
    Serial.println("</image>");    
  }   
}
