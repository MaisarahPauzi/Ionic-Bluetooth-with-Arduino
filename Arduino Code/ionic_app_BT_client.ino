#include <SoftwareSerial.h>
SoftwareSerial HC06Serial(3,4); // (RX,TX)
String value;


void setup() {
  for (int i=8; i<14; i++)          // initialize LED
  {               
    pinMode(i, OUTPUT);             
  }  

  Serial.begin(9600);       // start serial communication at 9600bps
  HC06Serial.begin(9600);
}

void loop() {
  
  if (HC06Serial.available())
  {
    value = HC06Serial.readString();
    Serial.println(value);
    
    if(value == "OFF"){
      for (int j=8; j<14; j++)        // looping
      {               
        digitalWrite(j, LOW);        // turn on LED
      }  
    }
    else if(value =="ON"){
      for (int k=8; k<14; k++)        // looping
      {               
        digitalWrite(k, HIGH);         // turn off LED
      } 
    }
    
  }
}