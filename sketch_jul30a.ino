#include <sensores.h>

const int ledVermelho = 4; //porta do led vermelho
const int ledVerde =    5; //porta do led verde
const int T1 =         333; // periodo led vermelho
const int T2 =         200; // periodo led verde
unsigned long  ultima_troca1;
unsigned long ultima_troca2;
bool ultimo_estado1;
bool ultimo_estado2;
void setup() {
 pinMode(ledVermelho,OUTPUT);
 pinMode(ledVerde,OUTPUT);
 pinMode(7,INPUT);
 digitalWrite(ledVermelho,LOW);
 digitalWrite(ledVerde,LOW);
 ultima_troca1 = 0;
 ultima_troca2 = 0;
 ultimo_estado1 = false;
 ultimo_estado2 = false; 
}

void loop() {
  unsigned long tempo;
  tempo = millis();
  if (tempo - ultima_troca1 >= T1 ) {
    if (ultimo_estado1) {
      digitalWrite(ledVermelho,HIGH);
    }
    else {
      digitalWrite(ledVermelho,LOW);
    }
      ultima_troca1 += T1;
      ultimo_estado1 = !(ultimo_estado1);
  }
  
  tempo = millis();
  if (check_SD()) {
      if (tempo - ultima_troca2 >= T2) {
    if (ultimo_estado2) {
      digitalWrite(ledVerde,HIGH);
    }
    else {
      digitalWrite(ledVerde,LOW);
    }
    ultimo_estado2 = !(ultimo_estado2);
    ultima_troca2 += T2;
      }
  }
 else {
    digitalWrite(ledVerde,LOW);
//    ultimo_estado2 = false;
//    ultima_troca2 += tempo;
 }  

}
