/*
  Tweaked from
  Harvard University 
  tinyMLx - OV7675 Camera Test for TinyML applications
  By - Anshu Bhatt

*/

#include <TinyMLShield.h>

// Image buffer;
byte image[160 * 120 * 2]; // QQVGA: 160x120 X 2 bytes per pixel (YCbCr422)
int bytesPerFrame;
int bytesPerPixel;

template <typename T>
inline T clamp_0_255(T x) {
  return std::max(std::min(x, static_cast<T>(255)), static_cast<T>(0));
}

inline void convert_yuv422_rgb888_f(uint8_t* out, uint8_t* in) {
  // Note: U and V are swapped
	const int32_t Y0 = in[0];
	const int32_t V  = in[1];
	const int32_t Y1 = in[2];
	const int32_t U  = in[3];

  out[0] = clamp_0_255(Y0 + 1.402f * (V - 128.0f));
  out[1] = clamp_0_255(Y0 - 0.344f * (U - 128.0f) - (0.714f * (V - 128.0f)));
  out[2] = clamp_0_255(Y0 + 1.772f * (U - 128.0f));
  out[3] = clamp_0_255(Y1 + 1.402f * (V - 128.0f));
  out[4] = clamp_0_255(Y1 - 0.344f * (U - 128.0f) - (0.714f * (V - 128.0f)));
  out[5] = clamp_0_255(Y1 + 1.774f * (U - 128.0f));
}

inline void ycbcr422_rgb888(int32_t Y, int32_t Cb, int32_t Cr, uint8_t* out) {
  Cr = Cr - 128;
  Cb = Cb - 128;

  out[0] = clamp_0_255((int32_t)(Y + Cr + (Cr >> 2) + (Cr >> 3) + (Cr >> 5)));
  out[1] = clamp_0_255((int32_t)(Y - ((Cb >> 2) + (Cb >> 4) + (Cb >> 5)) - ((Cr >> 1) + (Cr >> 3) + (Cr >> 4)) + (Cr >> 5)));
  out[2] = clamp_0_255((int32_t)(Y + Cb + (Cb >> 1) + (Cb >> 2) + (Cb >> 6)));
}

void setup() {
  Serial.begin(115200);
  while (!Serial);

  initializeShield();


  // Initialize the OV7675 camera
   // QCIF, RGB565, 1, 
  if (!Camera.begin(QQVGA, YUV422, 1, OV7675)) {
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
    const int32_t step_bytes = bytesPerPixel * 2;
    for(int32_t i = 0; i < bytesPerFrame; i+=bytesPerPixel * 2) {
      // Note: U and V are swapped
    	const int32_t Y0 = image[i + 0];
    	const int32_t Cr = image[i + 1];
    	const int32_t Y1 = image[i + 2];
    	const int32_t Cb = image[i + 3];
      ycbcr422_rgb888(Y0, Cb, Cr, &rgb888[0]);
      Serial.println(rgb888[0]);
      Serial.println(rgb888[1]);
      Serial.println(rgb888[2]);
      ycbcr422_rgb888(Y1, Cb, Cr, &rgb888[0]);
      Serial.println(rgb888[0]);
      Serial.println(rgb888[1]);
      Serial.println(rgb888[2]);
    }
    Serial.println("</image>");    
  }   
}
