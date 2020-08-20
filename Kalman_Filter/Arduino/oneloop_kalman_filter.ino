// Parameters of the Kalman Filter
float q;
float r;
float h;
float a;
float p = 0;


volatile unsigned int temp, counter = 0; //This variable will increase or decrease depending on the rotation of encoder
int value =0; // variable to hold rotary encoder output
int count = 0; // variable to hold laser snsor output
int check = 0; // variable for laser sensor debounce


// Parameters of the Kalman Filter (Changable)
void setup() {

  


  
   Serial.begin (9600);
  pinMode(4, INPUT_PULLUP); //plug laser sensor output into pin 4

  
  // plug rotary encoder ouputs into pin 2 and 3
  pinMode(2, INPUT_PULLUP); // white output pin goes to arudino pin 2
  
  pinMode(3, INPUT_PULLUP); // green output pin goes to arudino pin 3
//Setting up interrupt
  //A rising pulse from encodenren activated ai0(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
  attachInterrupt(0, ai0, RISING);
   
  //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
  attachInterrupt(1, ai1, RISING);
  q = 0.1;
  r = 0.1;
  h = 1.0;
  a = 1.0;
}

void loop() {
   int sensorVal = digitalRead(4); // plug laser sensor into pin 4



 
  value = counter/1200;  //originally counter holds the value of rotary encoder, which is a number that starts at 0 and increases by 1200 every rotation
                        // by dividing by 1200, we can count number of rotations. 





 // the following is basically a debouncer for the laser sensor
 // without it, the laser sensor would increase count by more than 1 whenever it sees a strip of tape
 
  if (sensorVal == LOW && check == 0) { // laser sensor typically reads high when not seeing any tape, if it sees tape it will go low. 
                                        //without "&&check==0", the if statement will be true multiple times, and count will increase more than once
    count = count+1; // this increments count
    check = 1; // resets the variable 'check' to 1, so that count can only increase one time per tape 
  }
  if (sensorVal == HIGH && check ==1){ // once the tape is no longer seen by sensor, variable 'check' is again set to 0
  check =0;
  }




  
  // put your main code here, to run repeatedly:
  // Input calc_val and measr_Val
  float calc_val = count;//laser
  float measr_val = value;//rotary
  float kal_value = get_value(calc_val, measr_val);
  // Ouput kal_value

  //prints outputs constantly 
  Serial.print ("laser sensor is ");
  Serial.print(count);
  Serial.print ("         Rotary encoder is ");
  Serial.print(value);
  Serial.print("           kalman filter value =  ");
  Serial.println(kal_value);
}

float get_value(float calc_value, float measr_value){
  float temp_p = a * a * p + q;
  float kalman_gain = h * p / (h * h * p + r);
  float kalman_value = calc_value + kalman_gain * (measr_value - h * calc_value);
  p = (1 - kalman_gain * h) * temp_p;
  return kalman_value;
}




// the following  two functions are for the rotary encoder, copied and pasted from a youtube tutorial

  void ai0() {
  // ai0 is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if(digitalRead(3)==LOW) {
  counter++;
  }else{
  counter--;
  }
  }
   
  void ai1() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(2)==LOW) {
  counter--;
  }else{
  counter++;
  }
  }
