int pirSensor = 12;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)
const int led0 = 8;
const int led1 = 6;
const int led2 = 5;
const int tempPin = A0;
const int ldrPin = A2;

void setup() {

  pinMode(pirSensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(ldrPin, INPUT);
  pinMode(tempPin,INPUT);
//  bt.begin(9600);
}

void loop(){
  val = digitalRead(pirSensor); 
  if (val==HIGH)
  {
    digitalWrite(led0,HIGH);
     Serial.println("Motion detected!"); 
      state = HIGH;
  }
  else
  {
    digitalWrite(led0,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    Serial.println("Motion stopped!");
        state = LOW;
  }
  if (val == HIGH) { 
          int tempStatus = analogRead(tempPin); 
          int ldrStatus = analogRead(ldrPin);
          if (ldrStatus <= 200) {

                          if (ldrStatus <= 39) {
                          analogWrite(led1, 255);
                          Serial.println(ldrStatus);

                          }
                          else if(ldrStatus <=80||ldrStatus>=40) {
                              analogWrite(led1, 200);
                              Serial.println(ldrStatus);
                          }
                          else if(ldrStatus <=100||ldrStatus>=81) {
                                analogWrite(led1, 150);
                                Serial.println(ldrStatus);
                          }
                          else if(ldrStatus <=120||ldrStatus>=101) {
                                analogWrite(led1, 100);
                                Serial.println(ldrStatus);
                          }
                          else if(ldrStatus <=140||ldrStatus>=121) {
                                analogWrite(led1, 50);
                                Serial.println(ldrStatus);
                          }

                          else{
                                analogWrite(led1, 25);
                                Serial.println(ldrStatus);
                          }

      } else {
            digitalWrite(led1, LOW);
            Serial.println(ldrStatus,led1);  
       }
      double cel=(double)val*(5/10.24); 
      if (cel >= 20) {

                          if (cel <=22) {
                          analogWrite(led2, 100);
                          Serial.println(cel);

                          }
                          else if(cel <=28||cel>=23) {
                              analogWrite(led2, 175);
                              Serial.println(cel);
                          }
                          else if(cel <=35||cel>=29) {
                                analogWrite(led2, 225);
                                Serial.println(cel);
                          }
                          else{
                                analogWrite(led2, 255);
                                Serial.println(cel);
                          }

      } else {
            digitalWrite(led2, LOW);
            Serial.println(cel);  
       }
    delay(100);                // delay 100 milliseconds 
  Serial.println(val);
}}
