void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  char tersten[100];
  char terstenn[100];
  int i;
  delay(1);
  if(Serial.available()){
  for(i=0;i<100;i++){
    
  tersten[i]=Serial.read();
  if(tersten[i]!=-1){
  Serial.print(tersten[i]);  
  terstenn[99-i]=tersten[i];
  }
  delay(1);
  }
  Serial.println("-");
  for(i=0;i<100;i++){
  if((terstenn[i]>=97)&&(terstenn[i]<=122)){    
  terstenn[i]=terstenn[i]-32;
  }
    if(terstenn[i]!=-1){
    Serial.print(terstenn[i]);
    }
    }  
  }
  
}
