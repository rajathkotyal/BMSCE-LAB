void setup()
{ Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  int a=analogRead(A0);
  int b=map(a,0,1023,0,255);
  analogWrite(13,b);
  Serial.print("ANALOG");
   Serial.print(a);
   Serial.print("\n BRIGHTNESS");
   Serial.print(b);
}