int pinoAbriPorta = 12; 
int pinoSensor = 11;
int pinoPorta = 13;
int pinoBlue = 10;
int acionamento; 
char buf;
boolean ligado = false;
 
void setup(){
  
  pinMode(pinoAbriPorta, OUTPUT); 
  pinMode(pinoSensor, INPUT); 
  pinMode(pinoPorta, OUTPUT);
  pinMode(pinoBlue,OUTPUT);
  
  Serial.begin(9600);
}
 
void loop(){
  
  buf = Serial.read();
  Serial.print(buf);
  Serial.print("\n");
 
  if (buf == '1' || ligado == true){
    ligado = true;
    verificaPorta(ligado);
  }else{
    verificaPorta(ligado);
  }
  
}

void verificaPorta(boolean args){
  if (args){
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
        delay(1000);
         acionamento = digitalRead(pinoSensor);
         if(acionamento == HIGH){
           abrirPorta();
           return;
         }
         else {
           return;
         }
      }
  }
}
 
 void abrirPorta (){
   Serial.print("Porta Aberta!!!");
   digitalWrite(pinoPorta,HIGH);
   delay(5000);
   digitalWrite(pinoPorta,LOW);
   digitalWrite(pinoAbriPorta, LOW);
   return;
 }
