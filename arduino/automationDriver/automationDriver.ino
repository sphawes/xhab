void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  incomingByte = "";

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);

    switch(incomingByte){
      case '1':
        //if we received a 1, then the raspi is trying to get us to engage the linear actuator
        linearActuator(1);
        break;
      case '2':
        //raspi wants to disengage linear actuator
        linearActuator(0);
        break;
      case '3':
        //lower scraper
        scraperCarriage(1);
        break;
      case '4':
        //raise scraper
        scraperCarriage(0);
        break;
      case '5':
        //extrude filament
        extrudeFilament(1);
        break;
      case '6':
        //stop filament extrusion
        extrudeFilament(0);
        break;
    }

  }
}

void linearActuator(action){
  if(action == 0){
    //disengage linear actuator

  }
  else{
    //engage linear actuator

  }

}

void scraperCarriage(action){
  if(action == 0){
    //raise carriage

  }
  else{
    //lower carriage

  }

}

void extrudeFilament(action){
  if(action == 0){
    //stop extruding

  }
  else{
    //start extruding

  }


}
