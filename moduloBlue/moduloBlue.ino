int pinoIO = 13;
char buf;
 
void setup()
{

  pinMode(pinoIO, OUTPUT);
  Serial.begin(9600);
}
 
void loop()
{
  while(Serial.available() > 0)
  {
    buf = Serial.read();
    Serial.print(buf);
    Serial.print("\n");

    if (buf == 'L')
    {
      digitalWrite(pinoIO, HIGH);
    }
    //Caso seja recebido o caracter D, apaga o led
     if (buf == 'D')
    {
      digitalWrite(pinoIO, LOW);
    }
  }
}
