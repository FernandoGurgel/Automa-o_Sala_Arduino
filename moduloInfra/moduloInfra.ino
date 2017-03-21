#include <IRremote.h>  
  
int RECV_PIN = 11;  
float armazenavalor;  
int pinoledvermelho = 5;  
  
IRrecv irrecv(RECV_PIN);  
decode_results results;  
  
void setup()  {  
  Serial.begin(9600);  
  irrecv.enableIRIn(); // Inicializa o receptor IR  
}  
   
void loop()  { 
  if (irrecv.decode(&results)){
    Serial.print("Valor lido: ");
    Serial.println(results.value, HEX);
    //armazenavalor = (results.value);
    digitalWrite(pinoledvermelho,HIGH);
    delay(20000);
    digitalWrite(pinoledvermelho,LOW);
    delay(10000);
    digitalWrite(pinoledvermelho,HIGH);
    delay(20000);
    digitalWrite(pinoledvermelho,LOW);
  }
}
