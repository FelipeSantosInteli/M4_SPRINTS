const int btn_1 = 4;
const int btn_2 = 5;
const int Led[4] = {40,39,38,37};
const int Buzz = 12;
const int PhtR = 7;
int limt = 3;
int e = -1;
int vect[64];


void setup() {
  Serial.begin(9600);
  pinMode(Led[0], OUTPUT);
  pinMode(Led[1], OUTPUT);
  pinMode(Led[2], OUTPUT);
  pinMode(Led[3], OUTPUT);
  pinMode(btn_1, INPUT_PULLUP);
  pinMode(btn_2, INPUT_PULLUP);
  pinMode(Buzz, OUTPUT);  
  pinMode(PhtR, INPUT);


}

void loop() {

  int btnStts_1 = digitalRead(btn_1);
  int btnStts_2 = digitalRead(btn_2);

  if (btnStts_1 == HIGH){
    Serial.println("Botão 1 APERTADO");
    
    e += 1;
    // Converte de 4096 à 16 e armazena numa array em binário //
    int bi[4] = {0, 0, 0, 0};
    int PhtR_Stts = analogRead(PhtR);
    int resul = floor(PhtR_Stts/256);
    int inv = 15 - resul;
    tone(Buzz, 1000 + (resul*300), 500);
    Serial.println(inv);
    while (inv > 0) {
      bi[limt] = inv % 2;
      inv = inv / 2;
      limt--;
    }
    limt = 3;
    
    for (int i = 0; i<4; i++) {
      digitalWrite(Led[i], bi[i]);
      Serial.println(bi[i]);
    }
  
    vect[e] = 15 - resul;


    int size = sizeof(vect)/sizeof(int);
    // Serial.println(vect[size - 1]);



  delay(100);
  }

  else if (btnStts_2 == HIGH) {
    Serial.println("Botão 2 APERTADO");
    int size = sizeof(vect)/sizeof(int);
    for (int i = 0 ; i <  size; i++) {
      if (vect[i] != 0) {
        int bi[4] = {0, 0, 0, 0};
        int inv = vect[i];
        int resul = 15 -inv;
        tone(Buzz, 1000 + (resul*300), 300);
        Serial.println(inv);
        while (inv > 0) {
          bi[limt] = inv % 2;
          inv = inv / 2;
          limt--;
        }
        limt = 3;
      }
    }
    delay(300);
  }
  
  // Serial.print(bi[0]);
  // Serial.print(bi[1]);
  // Serial.print(bi[2]);
  // Serial.println(bi[3]);
  delay(100);
}
