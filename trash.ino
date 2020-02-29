#include <Ultrasonic.h>
#define BLYNK_PRINT Serial
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "32f75fbea09b4ae3bec12b777b9c1185";

char ssid[] = "ICT_Innovation_Lab";
char pass[] = "beinnovative#";

BlynkTimer timer;
int distance = 0;

int thresh[3] = {15, 30, 45};
Ultrasonic ultrasonic(12, 13); //12>>D6(trig) 13>>D7(echo)

WidgetLED green(V3);
WidgetLED orange(V2);
WidgetLED red(V1);



void setup(){

  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass); 
}

void loop(){
  distance = ultrasonic.distanceRead();
  Serial.println(distance);
  Blynk.run();

  if(distance){
    Blynk.virtualWrite(V0,distance);
  }

  if(distance<thresh[0]){
    green.on();
    orange.off();
    red.off();
    }
  else if(distance<thresh[1]){
    green.off();
    red.off();
    orange.on();
  }
  else if(distance<thresh[2]){
    green.off();
    orange.off();
    red.on();
  }
  else{
    green.on();
    orange.off();
    red.off();
  delay(1000);
  }
}
