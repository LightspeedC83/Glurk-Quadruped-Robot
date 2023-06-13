int TrigPin = 4;
int EchoPin = 21;

//define sound speed in cm/uS
#define sound_speed 0.034

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop() {
  // clears Trigpin
  digitalWrite(TrigPin,LOW);
  delayMicroseconds(2);

  //sets trigpin on high state for 10 uS
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  //reads the echopin and calculates distance in cm
  float duration = pulseIn(EchoPin, HIGH);
  float distance = duration * sound_speed/2;

  //printing the distance to the serial monitor
  Serial.print("Distance (in cm):");
  Serial.println(distance);
  }
