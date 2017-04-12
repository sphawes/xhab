int scraperStep = 6;
int scraperDir  = 5;

int filamentStep = 7;
int filamentDir = 8;

String incomingByte = "";

#include <Servo.h>

Servo myservo;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  myservo.attach(11);
  
  pinMode(scraperStep, OUTPUT);
  pinMode(scraperDir, OUTPUT);

  pinMode(filamentStep, OUTPUT);
  pinMode(filamentDir, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    int incomingInt = incomingByte.toInt();
    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingInt);

    switch(incomingInt){
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

void linearActuator(int action){
  if(action == 0){
    //disengage linear actuator
    myservo.write(150);
  }
  else{
    //engage linear actuator
    myservo.write(82);
  }
  
}

void scraperCarriage(int action){
  if(action == 0){
    //raise carriage
    digitalWrite(scraperDir, HIGH);
    for(int i = 0;i<50;i++){
      digitalWrite(scraperStep, HIGH);
      delay(2);
      digitalWrite(scraperStep, LOW);
      delay(2);
    }
  }
  else{
    //lower carriage
    digitalWrite(scraperDir, LOW);
    for(int i = 0;i<50;i++){
      digitalWrite(scraperStep, HIGH);
      delay(2);
      digitalWrite(scraperStep, LOW);
      delay(2);
    }
  }

}

void extrudeFilament(int action){
  if(action == 0){
    //raise carriage
    digitalWrite(filamentDir, HIGH);
    for(int i = 0;i<50;i++){
      digitalWrite(filamentStep, HIGH);
      delay(2);
      digitalWrite(filamentStep, LOW);
      delay(2);
    }
  }
  else{
    //lower carriage
    digitalWrite(filamentDir, LOW);
    for(int i = 0;i<50;i++){
      digitalWrite(filamentStep, HIGH);
      delay(2);
      digitalWrite(filamentStep, LOW);
      delay(2);
    }
  }


}
