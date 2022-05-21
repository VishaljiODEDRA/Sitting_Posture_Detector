

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
#define motorPin 4
#define FORCE_SENSOR_PIN A0

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(motorPin, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  int analogReading = analogRead(FORCE_SENSOR_PIN);
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.println(distance);
  Serial.println(analogReading);
   if(distance == 0 && analogReading == 0) {
      Serial.println("Please, connect your pins properly.");
    }
    //
  else if( distance<3 || distance>10 || analogReading<100 || analogReading>350)  {
     digitalWrite(12, HIGH); 
     digitalWrite(13, LOW);
     Serial.println("Abnormal");
      digitalWrite(motorPin, HIGH); 
  }
  //  
  else if (3<=distance<=10 && 100 <= analogReading <=350){
       digitalWrite(13, HIGH);
       digitalWrite(12, LOW);
       Serial.println("Normal");
      digitalWrite(motorPin, LOW);
  } 
  
  delay(500);
}
