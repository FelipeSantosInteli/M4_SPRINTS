const int pinOut = 18;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32-S3!");
  pinMode(pinOut, OUTPUT);
}

void loop() {

  // Frequência das notas:
  const int Do = 262;
  const int Re = 294;
  const int Mi = 330;
  const int Fa = 349;
  const int Sol = 392;
  const int La = 440;
  const int Si = 494;
  const int DoZin = 528;
  
  delay(1000);
  int tempo = 400;
  tone(pinOut,La,tempo); //LA
  delay(tempo);
  tone(pinOut,Re,tempo); //RE
  delay(tempo);
  tone(pinOut,Fa,tempo/2); //FA - O tempo/2 faz com que demore metade do valor estipulado anteriormente, pois essa parte é mais rápida
  delay(tempo/2);
  tone(pinOut,Sol,tempo/2); //SOL
  delay(tempo/2);
  tone(pinOut,La,tempo); //LA
  delay(tempo);
  tone(pinOut,Re,tempo); //RE
  delay(tempo);
  tone(pinOut,Fa,tempo/2); //FA
  delay(tempo/2);
  tone(pinOut,Sol,tempo/2); //SOL
  delay(tempo/2);
  tone(pinOut,Mi,tempo); //MI
  delay(tempo);
}
