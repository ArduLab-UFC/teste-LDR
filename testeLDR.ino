#define ldr A5
#define ledLdr 8
#define som 10

void funcao1(int luz);
void funcao2(int luz, int buzzer);

int luminosidade;

void setup() {

  Serial.begin(9600);

  pinMode(ldr, INPUT);
  pinMode(ledLdr, OUTPUT);
  pinMode(som, OUTPUT);

  digitalWrite(som, 0);
  digitalWrite(ledLdr, 0);
}

void loop() {

  luminosidade = analogRead(ldr);

  Serial.println(luminosidade);
  Serial.println("-----------------");
  delay(1000);

  //funcao1(luminosidade); //sinal luminoso
  funcao2(luminosidade, som); //sinal luminoso e sonoro

}

void funcao1(int luz){
  if(luz<300){
    digitalWrite(ledLdr, 1);
  }else{
    digitalWrite(ledLdr, 0);
  }
}

void funcao2(int luz, int buzzer){
  if(luz<300){
    digitalWrite(ledLdr, 1);
    digitalWrite(buzzer, 0);
  }else{
    digitalWrite(ledLdr, 0);
    digitalWrite(buzzer, 1);
    delay(200);
    digitalWrite(buzzer, 0);
  }
}
