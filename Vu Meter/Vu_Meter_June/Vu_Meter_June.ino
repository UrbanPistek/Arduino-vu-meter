//Make this into an array 
 /*int LED_PIN1 = 2;
 int LED_PIN2 = 3;
 int LED_PIN3 = 4; 
 int LED_PIN4 = 5;
 int LED_PIN5 = 6;
 int LED_PIN6 = 7;
 int LED_PIN7 = 8;
 int LED_PIN8 = 9;
 int LED_PIN9 = 10;*/
 int LED_PINS[] = {2,3,4,5,6,7,8,9};
 int Micro_IN = A0; 
 int microphone_value = 0;
  
void setup() {
Serial.begin(9600);
  for(int idx = 0; idx < 8; idx++){
    pinMode(LED_PINS[idx], OUTPUT);  
  }
  pinMode(Micro_IN, INPUT);
  analogReference(INTERNAL);  
}

void loop() {
  microphone_value = analogRead(Micro_IN); 
  Serial.println(microphone_value);
    if(microphone_value > 275 || microphone_value < 270)
     digitalWrite(LED_PINS[0], HIGH);
    else 
     digitalWrite(LED_PINS[0], LOW);
  /*
  digitalWrite(LED_PIN1, HIGH); 
  digitalWrite(LED_PIN4, HIGH);
  digitalWrite(LED_PIN7, HIGH);
  delay(500); 
  digitalWrite(LED_PIN1, LOW); 
  digitalWrite(LED_PIN4, LOW);
  digitalWrite(LED_PIN7, LOW);
  delay(500);
 */
}
