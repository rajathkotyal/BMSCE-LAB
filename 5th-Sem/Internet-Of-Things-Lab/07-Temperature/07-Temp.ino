int outputpin = 0;
void setup()
{
	Serial.begin(9600);
}


void loop()
{
  int rawvoltage = analogRead(outputpin);
  float millivolts = (rawvoltage/1024.0)*5000;
  float celsius = millivolts/10;
  Serial.print("\nCelsius:\n");
  Serial.print(celsius);
  Serial.println("\nFahrenheit: ");
  Serial.print((celsius*9)/5 +32);
  delay(1000);
}
