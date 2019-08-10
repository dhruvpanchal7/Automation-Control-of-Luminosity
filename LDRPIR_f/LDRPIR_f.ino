int pirSensor = 12;              // the pin that the sensor is atteched to
int val = 0;                 // variable to store the sensor status (value)
int data1=0;
int data2=0;
int data3=0;
int flag=0;
int timer=0;

const int led0 = 8;
const int led1 = 6;
const int led2 = 3;
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
}

void loop(){
  val = digitalRead(pirSensor);
  
  if (Serial.available()>0){
    data1= Serial.read();
    flag=1;
    Serial.write(data1);
  }

   
  if (val==HIGH)
  {
    digitalWrite(led0,HIGH);

        if (data1=='0' || data1=='2') { 
          digitalWrite(led1,LOW);
          digitalWrite(led2,LOW);
            }
        else if(data1=='1' || data1=='3' )
        {
              if(data1 == '1'){
              data2=Serial.read();
              //data2=(double)data3;
              Serial.write(data2);
              if (data2 <= 20){
                analogWrite(led1,50);
                Serial.println("one");
                }
               if(data2>=20 && data2<=40){
                analogWrite(led1,100);
                Serial.println("two");
                }
                if(data2>=40 && data2<=60){
                analogWrite(led1,150);
                Serial.println("three");
                }
                if(data2>=60 && data2<=80){
                analogWrite(led1,200);
                Serial.println("four");
                }
                if(data2>=80 && data2<=100){
                analogWrite(led1,255);
                Serial.println("five");
                }
          }

          if(data1 == '3')
          {
              data3=Serial.read();
              Serial.write(data3);
              if(data3>=10 && data3<=20){
                analogWrite(led2,50);
                }
              if(data3>=20 && data3<=40){
                analogWrite(led2,100);
                }
              if(data3>=40 && data3<=60){
                analogWrite(led2,150);
                }
              if(data3>=60 && data3<=80){
                analogWrite(led2,200);
                }
              if(data3>=80 && data3<=100){
                analogWrite(led2,255);
                }
          }
          
          flag=0;
        }
        else
        {
          int tempStatus = analogRead(tempPin); 
          int ldrStatus = analogRead(ldrPin);
            if (ldrStatus <= 200) 
            {

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

        } 
        else 
        {
            digitalWrite(led1, LOW);
            Serial.println(ldrStatus);  
        }
        double cel=(double)tempStatus*(5/10.24); 
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

      } 
      else 
      {
            digitalWrite(led2, LOW);
            Serial.println(cel);  
       }
    /*delay(100);                // delay 100 milliseconds 
    if (state == LOW) 
    {
      digitalWrite(led0,HIGH);
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  
   
  else 
  {
      digitalWrite(led0, LOW); // turn LED OFF
      delay(200);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }*/
  }
}
  else
  {
    digitalWrite(led0,LOW); 
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
  }
}
