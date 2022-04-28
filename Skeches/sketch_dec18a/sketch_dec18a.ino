const int ledPin=13;
const int buttonPin=2;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.setTimeout(10000);
pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char input=(char)Serial.read();
  char sqr;
  int buttonState = 0;
int count =0;

delay(1);
while(Serial.available()){
  delay(1);
input=Serial.read();
if(input=='1'){
  digitalWrite(ledPin,HIGH);
  
  }else if(input=='2'){
    digitalWrite(ledPin,LOW);
    
    }else if(input=='3'){
      delay(800);
      digitalWrite(ledPin,HIGH);
      delay(800);
      digitalWrite(ledPin,LOW);
      delay(800);
      digitalWrite(ledPin,HIGH);
      delay(800);
      digitalWrite(ledPin,LOW);
      delay(800);
      digitalWrite(ledPin,HIGH);
      delay(800);
      digitalWrite(ledPin,LOW);
      delay(800);
      
      }else if(input=='4'){
        int sqr;
        sqr=Serial.parseInt();
        delay(1000);
        Serial.print(sqr*sqr);
        
        }else if(input=='5'){
          char a=0;
          while(1){
             buttonState = digitalRead(buttonPin);
    if (buttonState == 1) {
      count++;
    
      digitalWrite(ledPin, HIGH);
      delay(200);
      digitalWrite(ledPin, LOW);
      
      Serial.println(count);
      
  } 
  a=(char)Serial.read();
  
  if(a=='1'){
    break;
  }
          }
          }else if(input=='0'){
            exit(0);
            
            }
}            


}
