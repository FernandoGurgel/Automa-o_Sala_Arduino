int pinoAbriPorta = 12; 
int pinoSensor = 13;
int pinoPorta = 11;
int acionamento; 
 
void setup()
{
  pinMode(pinoAbriPorta, OUTPUT); 
  pinMode(pinoSensor, INPUT); 
  pinMode(pinoPorta, OUTPUT);
  Serial.begin(9600);
}
 
void loop()
 { 
   verificaPorta();
 
  }

 void verificaPorta(){
   do{
     acionamento = digitalRead(pinoSensor);
       if (acionamento == LOW)
      {
        digitalWrite(pinoAbriPorta, LOW);
        Serial.println("Parado");
      }
      else 
      {
        digitalWrite(pinoAbriPorta, HIGH);
        Serial.println("Movimento !!!");
      }
     delay(3000);
     acionamento = digitalRead(pinoSensor);
     if(acionamento == HIGH){
       abrirPorta();
       return;
     }
     else {
       return;
     }
   }while(acionamento == LOW);
 }
 
 void abrirPorta (){
   Serial.print("Porta Aberta!!!");
   digitalWrite(pinoPorta,HIGH);
   delay(5000);
   digitalWrite(pinoPorta,LOW);
   return;
 }
