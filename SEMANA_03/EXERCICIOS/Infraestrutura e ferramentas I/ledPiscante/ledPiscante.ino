const int pinLed = 3;

void setup() {
  Serial.begin(115200);
  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, HIGH);
  Serial.println("Hello World!!!");
}

void loop() {
  digitalWrite(pinLed, LOW);
  delay(1000);
  digitalWrite(pinLed, HIGH);
  delay(1000);
}

