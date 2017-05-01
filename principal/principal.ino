#include "SoftwareSerial.h"

SoftwareSerial bluetooth(3,2);

//porta digitral 
int pinSenMovimento = 4; 
int pinSisLigado = 5;
int pinPorta = 6;
int pinAr = 7;
int pinLampada = 8;
int pinComputador = 9;

//Variavel de controle
boolean ligarSistema = false;
boolean computador = false;
boolean ar = false;
int movimento;
int ON = HIGH; 
int OFF = LOW;
 
void setup(){
  
  pinMode(pinPorta, OUTPUT); 
  pinMode(pinSenMovimento, INPUT); 
  pinMode(pinSisLigado, OUTPUT);
  pinMode(pinAr, OUTPUT);
  pinMode(pinLampada, OUTPUT);
  pinMode(pinComputador, OUTPUT);
  
  Serial.begin(9600);
  bluetooth.begin(9600);
  
}
 
void loop(){
 
  if(bluetooth.available()){
    parametroBluetooth(bluetooth.read());
    
  }else if (ligarSistema){
    verificaPorta(ligarSistema);
    sistemaLampada(ligarSistema);
    sistemaComputador(computador);
    sistemaAr(ar);
  }
  
}

void parametroBluetooth(char args){
  switch(args){
    case 'l':
    case 'L':{
        Serial.println("Sistema ligado!!");
        digitalWrite(pinSisLigado, ON);
        ligarSistema = true;
        break;
      }
    case 'D':
    case 'd':{
      Serial.println("Sistema desligado!!");
      digitalWrite(pinSisLigado, OFF);
      ligarSistema = false;
      break;
    }

    case 'C':
    case 'c':{
      Serial.println("Computador ligado!!");
      computador = true;
      break;
    }

    case 'Z':
    case 'z':{
      Serial.println("Computador ligado!!");
      computador = false;
      break;
    }

    case 'a':
    case 'A':{
      Serial.println("Ar condicionado , liagado!!");
      ar = true;
      break;
    }

    case 's':
    case 'S':{
      Serial.println("Ar condicionado , Desligado!!");
      ar = false;
      break;
    }
  }
}

void sistemaComputador(boolean args){
  if(args && ligarSistema){
    digitalWrite(pinComputador,ON);
  }else{
    digitalWrite(pinComputador,OFF);
  }
}

void sistemaLampada(boolean args){
  if(args && ligarSistema){
    digitalWrite(pinLampada,ON);
  }else{
    digitalWrite(pinLampada,OFF);
  }
}

void sistemaAr(boolean args){
  if(args && ligarSistema){
    digitalWrite(pinAr,ON);
  }else{
    digitalWrite(pinAr,OFF);
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

