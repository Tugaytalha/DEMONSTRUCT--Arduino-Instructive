static int SKi, SKj, SKk, SKwhile;
char SKa, SKb, SKc[256];
int SKledPin = 13;
int SKinput1;
char SKinput2;

int SKbuttonPin = 2;
int SKbuttonPressPin = 8;
int SKbuttonState;
int SKcount = 0;


int SKred = 10;
int SKyellow = 9;
int SKgreen = 8;

int SKinputPin = 11;

char SKmainMenu, SKsubMenu;
int SKmain,SKsub;


void SKchangeLights();
void SKbuttonPressCounter();
void SKcodesCategory();
void SKprojectsCategory();
void SKconnectionCategory();
void SKhardwareCategory();




void setup() {
  Serial.begin(9600);
  Serial.flush();
  Serial.setTimeout(30000);
}


void loop() {
  delay(1);
  SKwhile = 1;          //VOID LOOP has been kept as simple as possible. Complexity is maintained through functions.
    delay(1);
    SKmainMenu = (char)Serial.read();
    if (SKmainMenu == '1') {
      while (SKwhile == 1) {
        delay(1);
        SKsubMenu = (char)Serial.read();
        Serial.println("q");
        if (SKsubMenu == 2) {
          //ARDUINO CODES OF MERT WILL BE PUT HERE
        } else if (SKsubMenu == 0) {
          SKwhile = 0;
        }
      } SKwhile = 1;
    } if (SKmainMenu == '2') {
      SKconnectionCategory();
    } if (SKmainMenu == '3') {
      SKhardwareCategory();
    } if (SKmainMenu == '4') {
      SKprojectsCategory();
      Serial.println("a");
      
    } if (SKmainMenu == '0') {
    }
  

}















void SKchangeLights() {
  // green off, yellow on for 3 seconds    digitalWrite(green, LOW);
  digitalWrite(SKyellow, HIGH);
  delay(3000);
  // turn off yellow, then turn red on for 5 seconds
  digitalWrite(SKyellow, LOW);
  digitalWrite(SKred, HIGH);
  delay(5000);
  // red and yellow on for 2 seconds (red is already on though)
  digitalWrite(SKyellow, HIGH);
  delay(2000);
  // turn off red and yellow, then turn on green
  digitalWrite(SKyellow, LOW);
  digitalWrite(SKred, LOW);
  digitalWrite(SKgreen, HIGH);
  delay(3000);
  digitalWrite(SKgreen, LOW);
}


void SKbuttonPressCounter() {
  SKi = 1;
  SKwhile=1;
  SKcount = 0;
  while (SKi == 1) {
    SKbuttonState = digitalRead(SKbuttonPressPin);
    if (SKbuttonState == 1) {
      SKcount++;

      digitalWrite(SKledPin, HIGH);
      delay(200);
      digitalWrite(SKledPin, LOW);

      Serial.println(SKcount);
      SKa = (char)Serial.read();
      if (SKa == '0') {
        SKi = 0;
      }
    }

  }
  SKi = 1;
}

void SKcodesCategory() {
  SKwhile=1;
  /*
    while (SKwhile == 1) {

      else if (SKsubMenu == 0) { //CODE OF MERT
        SKwhile = 0;
      }
    } SKwhile = 1;*/
}

void SKconnectionCategory() {
  SKwhile = 1;
  char gelenveri = '0';
  pinMode(6, OUTPUT);
  pinMode(3, OUTPUT);

  while (SKwhile == 1) {
    delay(1);
    digitalWrite(6, HIGH);

    gelenveri = Serial.read();

    delay(350);
    if (gelenveri == '0') {
      Serial.println("");
      Serial.println("WELCOME TO CONNECTIONS SECTION");
      Serial.println("Which lecture would you like to join?");
      Serial.println("1-Reset button");
      Serial.println("2-Pins characteristics");
      Serial.println("3-Breadboard");
      Serial.println("4-Analog pins");
      Serial.println("5-Power pins");
      Serial.println("6-PWM pins");
      Serial.println("PRESS 0 TO GO BACK TO MAIN MENU");
      Serial.println("IF YOU ENTER 9 YOU WILL GO BACK TO THE MAIN PAGE");

    }



    if ( gelenveri == '1') {
      delay(150);
      Serial.println("Press 0 to go back to lecture selection page");

    }
    if ( gelenveri == '2') {
      delay(150);
      Serial.println("Press 0 to go back to lecture selection page");

    }
    if ( gelenveri == '3') {
      delay(150);
      Serial.println("Press 0 to go back to lecture selection page");

    }
    if ( gelenveri == '4') {
      delay(150);
      Serial.println("Press 0 to go back to lecture selection page");

    }
    if ( gelenveri == '5') {
      delay(150);
      Serial.println("Press 0 to go back to lecture selection page");

    }
    if ( gelenveri == '6') {
      delay(150);
      Serial.println("Press 0 to go back to lecture selection page");

    }
    if ( gelenveri == 'c') {
      delay(150);
      if (analogRead(3) < 180 ) {
        Serial.println("YOUR SETUP IS WORKING");
      }
      else {
        Serial.println("YOUR SETUP IS NOT WORKING");
      }
    }
    if ((gelenveri == '9')) {
      SKwhile = 0;
    }
  }
}

void SKhardwareCategory() {
  int a;
  SKwhile=1;
  while (SKwhile == 1) {
    delay(1);
    char success1[35] = "Connection was succesful.\n\n";
    char success2[35] = "Press 1 to get a code example. ";
    char fail1[35] = "Connection wasn't succesful.\n\n";
    char fail2[65] = "Press 0 to go back to the Connection Screen and try again. ";


    if (Serial.available() > 0) {

      char datafromc = Serial.read();

      if (datafromc == '1') {
        delay(100);
        int ledPin = 7;
        int currentcontrol = A5;
        pinMode(ledPin, OUTPUT);
        pinMode(currentcontrol, INPUT);

        digitalWrite(ledPin, HIGH);
        a = digitalRead(currentcontrol);
        if (a == 1) {
          Serial.println(success1);
          Serial.print(success2);
        }
        if (a == 0) {
          Serial.println(fail1);
          Serial.print(fail2);
        }
        delay(2000); //LED stays on for 2 secs
        digitalWrite(ledPin, LOW);

      }

      if (datafromc == '2') {
        delay(100);
        int buttonPin = 7;
        int currentcontrol = A4;
        pinMode(buttonPin, OUTPUT);
        pinMode(currentcontrol, INPUT);

        digitalWrite(buttonPin, HIGH);
        a = digitalRead(currentcontrol);
        if (a == 1) {
          Serial.println(success1);
          Serial.print(success2);
        }
        if (a == 0) {
          Serial.println(fail1);
          Serial.print(fail2);
        }
      }

      if (datafromc == '3') {
        delay(100);
        int buzzerPin = 7;
        int currentcontrol = A3;
        pinMode(buzzerPin, OUTPUT);
        pinMode(currentcontrol, INPUT);

        digitalWrite(buzzerPin, HIGH);
        a = digitalRead(currentcontrol);
        if (a == 1) {
          Serial.println(success1);
          Serial.print(success2);
        }
        if (a == 0) {
          Serial.println(fail1);
          Serial.print(fail2);
        }
      }

      if (datafromc == '4') {
        delay(100);
        int potentPin = A0;
        int currentcontrol = A1;
        pinMode(potentPin, OUTPUT);
        pinMode(currentcontrol, INPUT);

        digitalWrite(potentPin, HIGH);
        a = digitalRead(currentcontrol);
        if (a == 1) {
          Serial.println(success1);
          Serial.print(success2);
        }
        if (a == 0) {
          Serial.println(fail1);
          Serial.print(fail2);
        }
      }

      if (datafromc == '5') {
        delay(100);
        int heatPin = A0;
        int currentcontrol = A2;
        pinMode(heatPin, OUTPUT);
        pinMode(currentcontrol, INPUT);

        digitalWrite(heatPin, HIGH);
        a = digitalRead(currentcontrol);
        if (a == 1) {
          Serial.println(success1);
          Serial.print(success2);
        }
        if (a == 0) {
          Serial.println(fail1);
          Serial.print(fail2);
        }
      }

      if (datafromc == '6') {
        delay(100);
        int echoPin = 3;
        int trigPin = 4;
        int currentcontrol = A3;
        pinMode(echoPin, OUTPUT);
        pinMode(trigPin, OUTPUT);
        pinMode(currentcontrol, INPUT);

        digitalWrite(echoPin, HIGH);
        digitalWrite(trigPin, HIGH);
        a = digitalRead(currentcontrol);
        if (a == 1) {
          Serial.println(success1);
          Serial.print(success2);
        }
        if (a == 0) {
          Serial.println(fail1);
          Serial.print(fail2);
        }
      }
      if (datafromc == '0') {
        SKwhile=0;
        }

    }
  } SKwhile = 1;
}

void SKprojectsCategory() {
  
  SKwhile=1;
  while (SKwhile == 1) {
    delay(1);
    SKsubMenu = (char)Serial.read();
    if (SKsubMenu == '1') {
      while (SKwhile == 1) {
        delay(1);
        SKinput2 = (char)Serial.read();
        if (SKinput2 == '1') {
          pinMode(SKred, OUTPUT);
          pinMode(SKyellow, OUTPUT);
          pinMode(SKgreen, OUTPUT);
          pinMode(SKinputPin, OUTPUT);
          digitalWrite(SKred, HIGH);
          digitalWrite(SKyellow, HIGH);
          digitalWrite(SKgreen, HIGH);

          delay(5000);

          if (analogRead(SKinputPin) < 265) {
            Serial.println("You have succesfully built your project!");
            SKk = 0;
          }
          else {
            Serial.println("The circuit hasn't been built properly.");
          }
        } else if (SKinput2 == '2') {
          digitalWrite(SKred, LOW);
          digitalWrite(SKyellow, LOW);
          digitalWrite(SKgreen, LOW);
          for (SKj = 0; SKj < 3; SKj++) {
            SKchangeLights();
          }
        } else if (SKinput2 == '0') {
          SKwhile = 0;
        }
      } SKwhile = 1;
    }
    else if (SKsubMenu == '2') {

      while (SKwhile == 1) {
        delay(1);
        SKinput2 = (char)Serial.read();
        if (SKinput2 == '1') {
          
          SKbuttonPressPin = 2;
          SKledPin = 9;

          pinMode(SKbuttonPressPin, INPUT);

          delay(2000);

          if (digitalRead(SKbuttonPressPin) > 0) {   //Custom analogRead() vallue will be put here for the value 265
            Serial.println("You have succesfully built your project!");
            SKk = 0;
          }
          else {
            Serial.println("The circuit hasn't been built properly.");
          }
        } else if (SKinput2 == '2') {
          char SKa = '0';
          int SKprestate;
          SKcount = 0;
          while (SKwhile == 1) {
            delay(1);
            SKbuttonState = digitalRead(SKbuttonPressPin);

            // check if the pushbutton is pressed. If it is, then the buttonState is HIGH:
            if (SKbuttonState == HIGH && SKprestate == 0) {
              SKcount++;
              Serial.println(SKcount);
              // turn LED on
              digitalWrite(SKledPin, HIGH);
              delay(200);
              // turn LED off
              digitalWrite(SKledPin, LOW);

              SKprestate = 1;
            } else if (SKbuttonState == LOW) {
              SKprestate = 0;
            }
            SKa = (char)Serial.read();        //CHECKS IF USER WANTS TO QUIT OR NOT.
            if (SKa == '1') {
              SKwhile = 0;
            }
          } SKwhile = 1;
        } else if (SKinput2 == '0') {
          SKwhile = 0;
        }
      } SKwhile = 1;
    } 
    else if (SKsubMenu == '3') {
      //THIRD PROJECT WILL BE PUT HERE
    }
    else if (SKsubMenu == '0') {
      SKwhile = 0;
    }
  } SKwhile = 1;
}
