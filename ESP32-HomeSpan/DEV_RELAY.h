struct DEV_RELAY : Service::Switch {  // deriving from the HomeSpan Switch service

  int relayPin;
  SpanCharacteristic *power;

  DEV_RELAY(int relayPin) : Service::Switch() {

    power = new Characteristic::On();
    this->relayPin = relayPin;
    pinMode(relayPin, OUTPUT);
  }

  boolean update() {            

    digitalWrite(relayPin, power->getNewVal());
   
    return(true);
  }
};
