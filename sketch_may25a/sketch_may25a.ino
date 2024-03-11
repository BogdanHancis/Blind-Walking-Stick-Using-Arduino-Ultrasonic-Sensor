int trigPin = 10;
int echoPin = 11;
int buzzer = 9;

long duration;
int distance;

void setup() {
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600);
}

void loop() {
// send the signal
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);

duration = pulseIn(echoPin,HIGH); // read the reflected waves
distance = duration * 0.034 / 2; // compute the distance

Serial.print("Distance: ");
Serial.println(distance);

// make sound effect
if(distance < 20) {
int del = 2 * distance; // delay in milliseconds

digitalWrite(buzzer,HIGH);
delay(del);
digitalWrite(buzzer,LOW);
delay(del);
}
}