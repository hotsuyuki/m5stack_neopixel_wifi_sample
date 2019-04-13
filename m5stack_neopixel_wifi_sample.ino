#include <M5Stack.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Adafruit_NeoPixel.h>

#define LED_COUNT 15
#define LED_PIN 21

char blynk_token[] = "YOUR_OWN_BLYNK_AUTH_TOKEN";
char wifi_ssid[] = "YOUR_OWN_WiFi_SSID";
char wifi_pass[] = "YOUR_OWN_WiFi_PASSWORD";

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN);

BLYNK_WRITE(V1) {
  int R = param[0].asInt();
  int G = param[1].asInt();
  int B = param[2].asInt();

  M5.Lcd.print("R = ");
  M5.Lcd.print(R);
  M5.Lcd.print(" / G = ");
  M5.Lcd.print(G);
  M5.Lcd.print(" / B = ");
  M5.Lcd.print(B);
  M5.Lcd.print("\n");

  for (int i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, R, G, B);
  }
  strip.show();
  delay(10);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  M5.begin();
  
  Blynk.begin(blynk_token, wifi_ssid, wifi_pass);
  
  strip.begin();
  strip.setBrightness(50);
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
}
