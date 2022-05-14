
const int triggerPin = 9; // storing pin number 9 inside triggerPin variable so we can easily identify that we are storing //trigger pin of ultrasonic sensor inside our variable.
const int echoPin = 10; // storing pin number 10 inside echoPin variable so we can easily identify that we are storing //trigger pin of ultrasonic sensor inside our variable.


long duration; // creating a long variable to use in distance formula

int distance; // creating a variable named distance to find the distance getting from the sensor

void setup() {

  // put your setup code here, to run once:

// setting trigger pin to output to detect distance in front of him and give information to echo pin
 pinMode(triggerPin,OUTPUT);

// setting echo pin to INPUT get distance information from trigger pin
 pinMode(echoPin,INPUT);


// Establishing Serial communication to debug our code
 Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  // clearing if trigger pin is active already
  digitalWrite(triggerPin,LOW);

// giving very less amount delay to activate our sensor
  delayMicroseconds(2);

// activating our sensor to get distance
  digitalWrite(triggerPin,HIGH);

// giving delay in micro seconds
  delayMicroseconds(10);

// setting trigger pin to LOW
  digitalWrite(triggerPin,LOW);

// get duration by pulseIn in built function
  duration = pulseIn(echoPin,HIGH);

// Formula to calculate distance
  distance = duration * 0.034/2 ;

// printing distance on serial monitor
  Serial.print("Distance : ");

  Serial.println(distance);
  
}
