#include "SoftwareSerial.h"

SoftwareSerial bluetooth(3,2);

int pinSenMovimento = 4; 
int pinSisLigado = 5;
int pinPorta = 6;
boolean ligar = false;

int movimento;
int ON = LOW; 
int OFF = HIGH;
 
void setup(){
  
  pinMode(pinPorta, OUTPUT); 
  pinMode(pinSenMovimento, INPUT); 
  pinMode(pinSisLigado, OUTPUT);
  
  Serial.begin(9600);
  bluetooth.begin(9600);
  
}
 
void loop(){
 
  if(bluetooth.available()){
    parametroBluetooth(bluetooth.read());
  }

  controlePorta(ligar);
}

void parametroBluetooth(char args){
  switch(args){
    case 'l':
    case 'L':{
        Serial.println("Bluetooth, ligado!!");
        digitalWrite(pinSisLigado, ON);
        ligar = true;
        break;
      }
    case 'D':
    case 'd':{
      Serial.println("Bluetooth, dedsligado!!");
      digitalWrite(pinSisLigado, OFF);
      ligar = false;
      break;
    }
  }
}

void verificaPorta(boolean args){
  if (args){
    
     movimento = digitalRead(pinSenMovimento);

     if(movimento == ON){
      Serial.println("Sensor Ligado, Porta Aberta!!");
      digitalWrite(pinPorta, ON);
     }else{
      Serial.println("Sensor Ligado, Porta Desligado!!");
      digitalWrite(pinPorta, OFF);
     }
  }else{
    Serial.println("Sensor Movimento desligado!!");
  }
}

