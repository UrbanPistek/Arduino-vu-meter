const int SIZE = 10; 
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
/*
  int data[SIZE]; 
  int index = 0; 
  
  void add_element(int element){
    data[index] = element; 
    index++; 
    index = index%SIZE; 
  }

  int average(int data[]){
    int sum = 0; 
    for(int idx = 0; idx < SIZE; idx++){
      sum = sum + data[idx]; 
    }
    return sum/SIZE; 
  }*/
  
RunningAverage Av;
int LED_PINS[] = {2,3,4,5,6,7,8,9};
int Micro_IN = A0; 
int microphone_value = 0;
  
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
       Serial.println(Av.average());
       /*
       add_element(analogRead(Micro_IN)); 
       Serial.println(average(data)); 
       */
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
