/*
IMU : Uses about 6 gyros to be accurate 
SPI & I^2C -Communication using the arduino pins 
NANO Arduino - Uses USB Nano for connection 
Red LED ON - Recieving A Signal 
Green LED ON - Transmititing 
 */
int microphone_IN = A0; 
int microphone_Value = 0;
int LED_pin = 3; 
int Button_pin = 6;  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(microphone_IN,INPUT); 
  pinMode(LED_pin, OUTPUT);
  pinMode(Button_pin, INPUT);    
}

void loop() {
  // For Reading the Microphone:
  microphone_Value = analogRead(microphone_IN); 
  Serial.println(microphone_Value); //Serial.println print advances to the next line after being printed
  //Use Serial Plotter to Plot the Values
  if(digitalRead(Button_pin) == LOW){
    if(digitalRead(Button_pin) == HIGH){
      digitalWrite(LED_pin, HIGH);
      Serial.println("ON"); 
    }
  }else if(digitalRead(Button_pin) == HIGH){
    if(digitalRead(Button_pin) == LOW){
      digitalWrite(LED_pin, HIGH);
      Serial.println("ON");
    }
  }
  else{
      digitalWrite(LED_pin, HIGH);
      delay(2500);
      digitalWrite(LED_pin, LOW);
      delay(2500);
    }
  /*
   From the microphone, you are reading to the arduino the voltage arcoss a variable resistor on the
   microphone PCB. Once this analong signal is read by the arduino using the analog input, it is 
   converted to a digital signal using ADC (Analog to Digital Conversion) so it can be read by the 
   computer (Computers work in digital signals). 
   */

   //Electrons actually do not travel at the speed of light, the information abou the path travels at
   //the speed of light 

   /*
    Diode: Only lets current flow in one direction 
    */
}
