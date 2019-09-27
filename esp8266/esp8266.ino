#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <Wire.h>
const char *ssid     = "Mrsalam";
const char *password = "yamahdi038,";

const long utcOffsetInSeconds = 12600;

char daysOfTheWeek[7][12] = {"1 shanbe", "2 shanbe", "3 shanbe", "4 shanbe", "5SHANBE", "Friday", "shanbe"};

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

void setup(){
  Serial.begin(9600);
  Wire.begin();
  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
}

void loop() {
  timeClient.update();
  Wire.beginTransmission(8);
  //Wire.write(daysOfTheWeek[timeClient.getDay()]);
  //Wire.write(", ");
  Wire.write(timeClient.getHours());
  Wire.write(":");
  Wire.write(timeClient.getMinutes());
  Wire.write(":");
  Wire.write(timeClient.getSeconds());
  //Serial.println(timeClient.getFormattedTime());
  Wire.endTransmission();
  delay(1000);
}
