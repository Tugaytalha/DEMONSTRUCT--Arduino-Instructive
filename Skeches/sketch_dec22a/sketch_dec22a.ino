int ledpin=11;

void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
Serial.begin(9600);
}
int fullmu(int parlaklikDegeri);

void loop() {
  // put your main code here, to run repeatedly:
  static int parlaklik=0;
  static int degisim=15;
  delay(100);
  parlaklik+=degisim;
  analogWrite(ledpin,parlaklik);
  degisim=fullmu(parlaklik)*15;
}
int fullmu(int parlaklikDegeri){
  static int yon=1;
  if ((parlaklikDegeri==255)||(parlaklikDegeri==0)){
    return yon=-1*yon;
    }else{return yon;}
  }
