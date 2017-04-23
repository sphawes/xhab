int scraper1Step = 12;
int scraper1Dir  = 11;

int scraper2Step = 10;
int scraper2Dir = 9;

int filamentStep = 7;
int filamentDir = 6;

int scraperLimit = 52;

String incomingByte = "";

#include <Servo.h>

#include <AccelStepper.h>
#define HALFSTEP 8

#define motorPin1  3     // IN1 on the ULN2003 driver 1
#define motorPin2  4     // IN2 on the ULN2003 driver 1
#define motorPin3  5     // IN3 on the ULN2003 driver 1
#define motorPin4  6     // IN4 on the ULN2003 driver 1

AccelStepper stepper;

Servo myservo;

bool extrudeFilamentStatus = false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  myservo.attach(8);
  
  pinMode(scraper1Step, OUTPUT);
  pinMode(scraper1Dir, OUTPUT);

  pinMode(scraper2Step, OUTPUT);
  pinMode(scraper2Dir, OUTPUT);

  pinMode(filamentStep, OUTPUT);
  pinMode(filamentDir, OUTPUT);

  pinMode(scraperLimit, INPUT);

  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);

  stepper.setMaxSpeed(1000);
  stepper.setSpeed(100);
  

}

void loop() {

  if(extrudeFilamentStatus){
    //extrude filament
    stepper.runSpeed();
  }
  else{
    stepper.stop();
  }
  
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
        scraperCarriage(0);
        break;
      case '4':
        //raise scraper
        scraperCarriage(1);
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
    digitalWrite(scraper1Dir, LOW);
    digitalWrite(scraper2Dir, LOW);
    while(true){
      digitalWrite(scraper1Step, HIGH);
      digitalWrite(scraper2Step, HIGH);
      delay(2);
      digitalWrite(scraper1Step, LOW);
      digitalWrite(scraper2Step, LOW);
      delay(2);
      if(digitalRead(scraperLimit) == HIGH){
        break;
      }
    }
  }
  else{
    //lower carriage
    digitalWrite(scraper1Dir, HIGH);
    digitalWrite(scraper2Dir, HIGH);
    for(int i = 0;i<5000;i++){
      digitalWrite(scraper1Step, HIGH);
      digitalWrite(scraper2Step, HIGH);
      delay(2);
      digitalWrite(scraper1Step, LOW);
      digitalWrite(scraper2Step, LOW);
      delay(2);
    }
  }

}

void extrudeFilament(int action){
  if(action == 0){
    extrudeFilamentStatus = false;
  }
  else{
    extrudeFilamentStatus = true;
  }


}
