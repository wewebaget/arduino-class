const int echoPin910 = 9;
const int trigPin910 = 10;
const int trigPin56 = 6;
const int echoPin56 = 5;
const int LEDred910 = 11;
const int LEDyellow910 = 2;
const int LEDgreen910 = 3;
const int LEDred56 = 4;
const int LEDyellow56 = 7;
const int LEDgreen56 = 8;
float duration910, distance910, duration56, distance56;
// this must go in the void loop
void setup() {
  pinMode(trigPin910, OUTPUT);
  pinMode(echoPin910, INPUT);
  pinMode(trigPin56, OUTPUT);
  pinMode(echoPin56, INPUT);
  pinMode(LEDred910, OUTPUT);
  pinMode(LEDyellow910, OUTPUT);
  pinMode(LEDgreen910, OUTPUT);
  pinMode(LEDred56, OUTPUT); 
  pinMode(LEDyellow56, OUTPUT);
  pinMode(LEDgreen56, OUTPUT);
  Serial.begin(9600);
}

void get910(){
  digitalWrite(trigPin910, LOW); // set the trigger on the right to off
  delayMicroseconds(2);
  digitalWrite(trigPin910, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin910, LOW); 
  duration910 = pulseIn(echoPin910, HIGH); // the duration on the right reads the echo that is on
  distance910 = (duration910*.0343)/2;
}
void get56(){
  digitalWrite(trigPin56, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin56, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin56, LOW);
  duration56 = pulseIn(echoPin56, HIGH);
  distance56 = (duration56*.0343)/2;
}

void loop() {
  get910();
  get56();

  //duration is time. time * the speed of sound (in this case it's 0.0343)/2 because it takes the same time for the ultrasonic wave to come back
  while(distance910<10 && distance56< 10){
    get910();
    get56();
    digitalWrite(LEDgreen910, HIGH);
    delay(5900);
    digitalWrite(LEDgreen910, LOW);
    digitalWrite(LEDyellow910, HIGH);
    delay(1000);
    digitalWrite(LEDyellow910, LOW);
    digitalWrite(LEDred910, HIGH);
    digitalWrite(LEDred56, LOW);
    digitalWrite(LEDgreen56, HIGH);
    delay(5900);
    digitalWrite(LEDgreen56, LOW);
    digitalWrite(LEDyellow56, HIGH);
    delay(1000);
    digitalWrite(LEDyellow56, LOW);
    digitalWrite(LEDred56, HIGH);
    digitalWrite(LEDred910, LOW);
  }

  while(distance910<10 && distance56 > 10){
    get910();
    get56();
    digitalWrite(LEDred910, LOW);
    digitalWrite(LEDred56, HIGH);
    digitalWrite(LEDgreen910, HIGH);
    digitalWrite(LEDgreen56, LOW);
  }

  while(distance56<10 && distance910 > 10){
    get910();
    get56();
    digitalWrite(LEDred56, LOW);
    digitalWrite(LEDred910, HIGH);
    digitalWrite(LEDgreen56, HIGH);
  }

  Serial.println(distance910);
}
