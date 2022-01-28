const int stepPin = 9;
const int button = 11;
const int steps = 200;
const bool Open = 0;
int stepDelay;

#include <TMC2208Stepper.h>
TMC2208Stepper driver = TMC2208Stepper(5,6);

void setup() {
   Serial.begin(9600);
   while(!Serial);

   pinMode(stepPin, OUTPUT);
   
   driver.pdn_disable(1);   // Use PDN/UART pin for communication
   driver.I_scale_analog(0);
   driver.rms_current(500); // Fix current at 500mA
   driver.toff(0x2); // Turn driver on
}

void loop() {
   //Activates a direction of rotation and sets the delay between steps
   driver.shaft(true);
   stepDelay = 250;
   if (button == HIGH & Open ==1){
      driver.shaft(true);
         for (int x = 0; x < steps; x++) {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(stepDelay);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(stepDelay);
         }
         delay(1000);
   }else if (button == HIGH & Open ==0){
      driver.shaft(false);
         for (int x = 0; x < steps; x++) {
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(stepDelay);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(stepDelay);
         }
         delay(1000);
   }

   driver.shaft(false);
   stepDelay = 150;
   
   for (int x = 0; x < steps * 2; x++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(stepDelay);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(stepDelay);
   }
   delay(1000);
}