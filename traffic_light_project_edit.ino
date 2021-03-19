int motionSensor = 8;
int PIR_STATE = LOW;
int VALUE = 0;

int red = 3; 
int green = 2;
int buzzer = 7;
int counter = 0;

int carRed = A2;
int carYellow = A1;
int carGreen = A0;

void setup()  { 
  
  pinMode(motionSensor, INPUT);
  
  pinMode(green, OUTPUT); // Lights from Pedestrian point of view
  pinMode(red, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  pinMode(carRed, OUTPUT); //  Lights from Cars/Road point of view
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
  
} 

void loop(){
   digitalWrite(red, HIGH); // Turns red LED on. This will stay on until motion is detected by the sensor when someone wishes to cross.
   digitalWrite(carGreen, HIGH); // Light is green for cars to move freely 
   
  VALUE = digitalRead(motionSensor); // Waits for motion to be detected
  
  if (VALUE == HIGH)
    {

      digitalWrite(buzzer, HIGH); // Makes sound to let Pedestrian know motion has been detected.
      delay(70);
      digitalWrite(buzzer, LOW);
      delay(150);
      digitalWrite(buzzer, HIGH); 
      delay(70);
      digitalWrite(buzzer, LOW);

      delay(5000); 
      digitalWrite(carGreen, LOW); // Motion has been detected so the light are in the process of stopping the cars. Green LED off.
      delay(1000);
      digitalWrite(carYellow, HIGH); // Cars will get yellow LED
  
      delay(4000); // 
      digitalWrite(carYellow, LOW);
      digitalWrite(red, LOW); //  Turns red LED off for Pedestrian
      delay(0);

      // Light in process of changing to allow people to cross

      digitalWrite(green, HIGH); // Turns green LED on for Pedestrians
      digitalWrite(carRed, HIGH); // Light Turns red for cars
      
        while(counter <= 40) // Rapid buzzer so people have an audible cue along with a visual one. Time can be changed with counter
        {
          digitalWrite(buzzer, HIGH);  
          delay(70);
          digitalWrite(buzzer, LOW);
          delay(200);
          counter++;
        }
    
      counter = 0;
      
    digitalWrite(carRed, LOW);
    digitalWrite(green, LOW); //  Turns green LED off
    delay(200);
  }

}
