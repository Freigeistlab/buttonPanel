/*
Freigeist
Code to send button presses on panel over serial
*/

const int button_pins[6] = {4,7,2,5,3,6};
const int led_pin = 8;
bool prev_state[6] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};

void setup() {
  for(int i = 0; i < sizeof(button_pins)/sizeof(button_pins[0]); ++i) {
    pinMode(button_pins[i], INPUT_PULLUP);
  }
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600);
  Serial.println("start");
}

void loop() {
  for(int i = 0; i < sizeof(button_pins)/sizeof(button_pins[0]); ++i) {
    
    if(digitalRead(button_pins[i]) == LOW && prev_state[i] == HIGH) {
      Serial.print(i);
      Serial.println("D");
      digitalWrite(led_pin, HIGH);
      prev_state[i] = LOW;
    }

    if(digitalRead(button_pins[i]) == HIGH && prev_state[i] == LOW) {
      Serial.print(i);
      Serial.println("U");
      digitalWrite(led_pin, LOW);
      prev_state[i] = HIGH;
    }
  }
  delay(20);
}
