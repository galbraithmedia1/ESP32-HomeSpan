
#include "HomeSpan.h" 
#include "LED.h"
#include "DEV_RELAY.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  homeSpan.setPairingCode("11122333");
  homeSpan.setQRID("111-22-333");

  homeSpan.begin(Category::Bridges, "HomeSpan Bridge");
       

  new SpanAccessory();
    new Service::AccessoryInformation();
      new Characteristic::Identify();
    new LED(15); 

   
  // Accessory 2: Relay Switch
  new SpanAccessory();
    new Service::AccessoryInformation();    
      new Characteristic::Identify();                       
    new DEV_RELAY(17);  // instantiates a new relay
}


void loop() {
  // put your main code here, to run repeatedly:
  homeSpan.poll();
}
