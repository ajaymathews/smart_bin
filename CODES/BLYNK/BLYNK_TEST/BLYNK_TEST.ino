/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "c9d7104c6e444de6a99d6221c385a2b6";

char ssid[] = "SSID";
char pass[] = "123456789";
BlynkTimer timer;
int i,distance;

void distance_read()
{
 for(i=0;i<=50;i=i+5)
 {
  distance=i;
  Blynk.virtualWrite(V5, distance);// Please don't send more that 10 values per second.
}}

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,HIGH);

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, distance_read);
 // distance_read(),function declared that calls every second
}

void loop()
{
  Blynk.run();
  timer.run();
}
