char data = 0;

int pinoSaidaBlue = 13;  

void setup()
{
    Serial.begin(9600);
    pinMode(pinoSaidaBlue,OUTPUT);
}

void loop()
{
    data = Serial.read();
    Serial.print(data);
    Serial.print("\n");
    if(data == '1'){
        digitalWrite(pinoSaidaBlue,HIGH);
    }else if(data == '0'){
        digitalWrite(pinoSaidaBlue,LOW);
    }
}