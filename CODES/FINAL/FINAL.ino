#define BLYNK_PRINT Serial


#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "0ee0607502c8417d8b6cfefa38ab7f3a";
char ssid[] = "MOTOROLA-9F672";    // Your WiFi credentials.
char pass[] = "2958b1231bb27d6c7d63";

BlynkTimer timer;

const int trigPin = D0;
const int echoPin = D2;
long duration;
int distance;
WidgetLCD lcd(V1);

void sendSensor() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);
if(distance<10)
{
 Blynk.email("XXXXXXXXXXXXXXX@gmail.com", "ESP8266 Alert", "BIN FULL!");
 Blynk.notify("BIN FULL..!");
}
lcd.print(7, 1, distance);
Blynk.virtualWrite(V0, distance);
}

void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT); 
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
lcd.clear(); 
timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
