/*
Project by:Kevin Joe Ronin(URK17S221)
Hardware: Ultrasonic_Sensor and NodeMCU
Data is displayed at Blynk app
*/

#include <Ultrasonic.h>
#define BLYNK_PRINT Serial
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "32f75fbea09b4ae3bec12b777b9c1185";

char ssid[] = "akib";
char pass[] = "0987654321";

BlynkTimer timer;
int distance = 0;
int distance1 = 0;
int distance2 = 0;
int distance3 = 0;
int distance4 = 0;

int a, b, c, d;

int thresh = 15;

Ultrasonic ultrasonic1(15, 13); //15>>D8(trig) 13>>D7(echo)
Ultrasonic ultrasonic2(12, 14); //12>>D6(trig) 14>>D5(echo)
Ultrasonic ultrasonic3(2, 0);   //2>>D4(trig) 0>>D3(echo)
Ultrasonic ultrasonic4(4, 5);   //4>>D2(trig) 5>>D1(echo)

WidgetLED LED0(V0);
WidgetLED LED1(V1);
WidgetLED LED2(V2);
WidgetLED LED3(V3);

void setup(){
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

}

void loop(){
  
  distance1 = ultrasonic1.distanceRead();
  distance2 = ultrasonic2.distanceRead();
  distance3 = ultrasonic3.distanceRead();
  distance4 = ultrasonic4.distanceRead();
  
  Serial.println(distance1);
  Serial.println(distance2);
  Serial.println(distance3);
  Serial.println(distance4);
  Blynk.run();
  
//for first LED
  long first_LED_CON = distance1<thresh && distance1>0;
  if(first_LED_CON){
    Blynk.virtualWrite(V0,distance1);
    LED0.on();
  }
  else{
    LED0.off();
    a = 1000;
  }


//for second LED
  long second_LED_CON = distance2<thresh && distance2>0;
  if(second_LED_CON){
    Blynk.virtualWrite(V1,distance2);
    LED1.on();
  }
  else{
    LED1.off();
    b = 2000;
  }


//for third LED
  long third_LED_CON = distance3<thresh && distance3>0;
  if(third_LED_CON){
    Blynk.virtualWrite(V2,distance3);
    LED2.on();
  }
  else{
    LED2.off();
    c = 3000;
  }


//for fourth LED
  long fourth_LED_CON = distance4<thresh && distance4>0;
  if(fourth_LED_CON){
    Blynk.virtualWrite(V3,distance4);
    LED3.on();
  }
  else{
    LED3.off();
    d = 4000;
  }

  if((a+b+c+d) == 10000){
    Blynk.notify("Alert !!!!!!!");  
  }
 
}
