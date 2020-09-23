// variables
int GREEN = 2;
int YELLOW = 3;
int RED = 4;
int DELAY_GREEN = 900;
int DELAY_YELLOW = 700;
int DELAY_RED = 900;


// basic functions
void setup()
{
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}

void loop()
{
  red_light();
  delay(DELAY_RED);
  yellow_light();
  delay(DELAY_YELLOW);
  green_light();
  delay(DELAY_GREEN);
}

void green_light()
{
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
}

void yellow_light()
{
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(RED, LOW);
}

void red_light()
{
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, HIGH);
}