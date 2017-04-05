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
  
  
  if (buf == 'L' || ligado == true){
    Serial.print(buf);
    Serial.print("\n");
    
    digitalWrite(pinoBlue,HIGH);
    ligado = true;
    verificaPorta(ligado);
  }else if ((buf == 'D' || ligado == false){
    Serial.print(buf);
    Serial.print("\n");
    
    digitalWrite(pinoBlue,LOW);
    verificaPorta(ligado);
  }
  
}

void verificaPorta(boolean args){
  if (args){
     acionamento = digitalRead(pinoSensor);
     
     if (acionamento == LOW){
        digitalWrite(pinoAbriPorta, LOW);
        Serial.println("Parado");
      }
      else {
        
        digitalWrite(pinoAbriPorta, HIGH);
        Serial.println("Movimento !!!");
        
      }
  }
}

