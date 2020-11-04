int tilt=4;
int led=11;
void setup()
{
  pinMode(tilt,INPUT);
  pinMode(led,OUTPUT);
}

void loop()
{
  int reading;
  reading=digitalRead(tilt);
  if(reading)
  digitalWrite(led, LOW);
  else
  digitalWrite(led, HIGH);

}
