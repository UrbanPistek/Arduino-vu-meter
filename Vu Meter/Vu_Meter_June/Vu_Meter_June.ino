const int SIZE = 10; 
const int MAX = 30;
const int MIN = 0; 
const int RANGE = MAX - MIN; 
int LED_PINS[] = {2,3,4,5,6,7,8,9,10};
int Micro_IN = A0; 
int microphone_value = 0;
int vol = 0;

//Experiment with using pointers instead later 
class RunningAverage{
  int data[SIZE] = {0}; 
  int index = 0; 
public: 
  void add_element(int element){
    data[index] = element; 
    index++; 
    index = index%SIZE; 
  }

  int average(){
    int sum = 0; 
    for(int idx = 0; idx < SIZE; idx++){
      sum = sum + data[idx]; 
    }
    return sum/SIZE;
  }
};

int read_background_noise(){
  int sum = 0; 
  for(int idx= 0; idx < 10; idx++){
    sum += analogRead(Micro_IN); 
  }
  return sum/10; 
}

void LED_range(int vol){
  int bucket_size = RANGE/10; 
  int magitude = abs(vol/bucket_size); 
  
  for(int idx = 0; idx < 9; idx++){
    digitalWrite(LED_PINS[idx], LOW); 
   } 
   
  //if(abs(vol) > MIN){
  for(int idx = 0; idx < magitude; idx++){
    digitalWrite(LED_PINS[8-idx], HIGH); 
   }
  //}
}
  
RunningAverage Av;
  
void setup(){
Serial.begin(9600);
  for(int idx = 0; idx < 8; idx++){
    pinMode(LED_PINS[idx], OUTPUT);  
  }
  pinMode(Micro_IN, INPUT);
  analogReference(INTERNAL);
   
}

void loop(){ 
       Av.add_element(analogRead(Micro_IN)); 
       vol = Av.average() - read_background_noise();
       LED_range(vol);  
       Serial.println(vol); 
       
}

/*
 Why you can't take a foureir transform and determine the frquancies of the noise:
 Becasue doing the foureir transform and them converting it back to the time domain can take too much time
 It can be done in real time (using a butterfly algorithm), however you need to record all the
 data up to that point (ie. define a window) 
 */

 /*
  * 
  */
