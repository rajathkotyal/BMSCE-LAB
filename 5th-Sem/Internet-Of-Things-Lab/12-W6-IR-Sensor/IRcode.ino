#include <Servo.h>
#include <IRremote.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

Servo myservo;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
}
void loop(){
    if (irrecv.decode(&results))
  {
    switch (results.value)
    {
      case 0xFD00FF:
  		myservo.attach(9);
        Serial.println("Start");
        break;
      case 0xFD609F:
		myservo.write(360);
		Serial.println("Clockwise");
        break;
      case 0xFD20DF:
		myservo.write(-360);
		Serial.println("Counter Clockwise");
        break;
      default:
        Serial.print("Unrecognized code received: 0x");
        Serial.println(results.value, HEX);
        break;
    }
    irrecv.resume();
  }
}
