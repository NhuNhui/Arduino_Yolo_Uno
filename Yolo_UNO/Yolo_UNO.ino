#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel rgb(4, D3, NEO_GRB + NEO_KHZ800);

void setup()
{
    Serial.begin(115200); // Khởi tạo Serial
    rgb.begin();
    // Cấu hình chân GPIO
    pinMode(D3, OUTPUT); // Chân GPIO điều khiển đèn LED
    pinMode(A0, INPUT); // Chân analog đọc cảm biến ánh sáng
}

void onLed() {
  rgb.setPixelColor(0, rgb.Color(255,102,0));
  rgb.setPixelColor(1, rgb.Color(255,102,0));
  rgb.setPixelColor(2, rgb.Color(255,102,0));
  rgb.setPixelColor(3, rgb.Color(255,102,0));
  rgb.show();
}

void offLed() {
  rgb.setPixelColor(0, rgb.Color(0,0,0));
  rgb.setPixelColor(1, rgb.Color(0,0,0));
  rgb.setPixelColor(2, rgb.Color(0,0,0));
  rgb.setPixelColor(3, rgb.Color(0,0,0));
  rgb.show();
}

void loop()
{
    // Đọc giá trị cảm biến
    int sensorValue = analogRead(A0);

    // Điều khiển đèn LED
    if (sensorValue < 1000) { // Bật đèn LED khi ánh sáng thấp
        onLed();
    } else {  // Tắt đèn LED khi ánh sáng cao
        offLed();
  }

    // In ra giá trị ánh sáng
    Serial.print("Light: ");
    Serial.println(sensorValue);

    delay(1000); // Chờ 1 giây
}