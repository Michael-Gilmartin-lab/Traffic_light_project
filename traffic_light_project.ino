int motionSensor = 8;
int PIR_STATE = LOW;
int VALUE = 0;

int red = 4; 
int green = 2;
int yellow = 3;
int buzzer = 7;
int counter = 0;

void setup()  { 
  
  pinMode(motionSensor, INPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
} 

void loop(){
   digitalWrite(red, HIGH); // Turns red LED on. This will stay on until motion is detected by the sensor.
   
  VALUE = digitalRead(motionSensor); // Waits for motion to be detected
  
  if (VALUE == HIGH)
    {

      digitalWrite(buzzer, HIGH); // Makes sound to let someone know motion has been detected.
      delay(70);
      digitalWrite(buzzer, LOW);
      delay(150);
      digitalWrite(buzzer, HIGH); 
      delay(70);
      digitalWrite(buzzer, LOW);
  
      delay(3000); // Small delay once motion detected
      digitalWrite(red, LOW); //  Turns red LED off
      delay(0);

      // Light in process of changing to allow people to cross

      digitalWrite(yellow, HIGH); // Turns yellow LED on
      delay(6000); // small delay of 6 seconds for yellow LED
      digitalWrite(yellow, LOW); //  Turns yellow  LED off
      delay(100);


      digitalWrite(green, HIGH); // Turns green LED on

        while(counter <= 40) // Rapid buzzer so people have an audible cue along with a visual one. Time can be changed with counter
        {
          digitalWrite(buzzer, HIGH);  
          delay(70);
          digitalWrite(buzzer, LOW);
          delay(200);
          counter++;
        }
    
      counter = 0;

    digitalWrite(green, LOW); //  Turns green LED off
    delay(200);
  }

}
