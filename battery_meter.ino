#define relayPin  2
#define sec 3600
void setup() {
Serial.begin(9600);
pinMode(relayPin,1);
Serial.println("it will start when you connect the battery");
}
unsigned long t;
unsigned long d = 1000;
double power;

void loop() {
   float bR =  batteryRead(A1);

  if(millis() - t >= d && !!thereIsBattery(A1) == true){
    Serial.println(String("V = ")+String( bR));
    power += bR/12;
     Serial.println(analogRead(A1));
    t = millis();
  }
  
}
float batteryRead(byte analogPin){
 if( analogRead(analogPin) > 0){
 
   return  float(0.0048828125 *float(analogRead(analogPin))) ;

 }else{
   return false;

 }
}
boolean thereIsBattery(byte analogPin){
  if(float(batteryRead(analogPin)) > float(2.5)){
    digitalWrite(relayPin,1);
    return true;
  }else{
    digitalWrite(relayPin,0);
    double capacity =  power/3600;
      if(millis() - t >= d ){
   Serial.println("capacity of the battary is  = "+String(capacity)+"AH");
  }
   
  return false;
  }
}

