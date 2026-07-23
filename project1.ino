#define BLYNK_TEMPLATE_ID "TMPL3mpMFSQfU"
#define BLYNK_TEMPLATE_NAME "ESP32 Relay"
#define BLYNK_AUTH_TOKEN "Ri84g2vpkSJ7UUOzXZVj91pgJgQ7zlw6"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "M-MALEK";
char pass[] = "#Malekmalek786";

#define RELAY_PIN 18

BLYNK_WRITE(V0)
{
  int state = param.asInt();

  if (state == 1)
    digitalWrite(RELAY_PIN, LOW);   // Relay ON (active LOW)
  else
    digitalWrite(RELAY_PIN, HIGH);  // Relay OFF
}

void setup()
{
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);    // Relay OFF at startup

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
}
