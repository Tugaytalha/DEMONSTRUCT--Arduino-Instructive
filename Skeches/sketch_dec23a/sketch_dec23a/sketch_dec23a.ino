int ledPin=13;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char input;
  input=Serial.read();
if(input=='1'){
  digitalWrite(ledPin,HIGH);
  Serial.println(input);
  
  }else if(input=='2'){
    digitalWrite(ledPin,LOW);
    Serial.println(input);
    }

}
