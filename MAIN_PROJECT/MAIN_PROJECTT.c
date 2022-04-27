#include <string.h>
#include <unistd.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <errno.h>

//FROM HERE

struct Tuser
{ //User informantions
  char user_name[30];
  char password[30];
  char name[30];
  int experience;
};

void cursor_coordinator(int x, int y);   //From here -----
void umsleep(__int64 usec);
void cursoreaster(int k);
void Ttakeuserinfo(char st[30]);
void Tclearpass(char pass[30], int show);
int Ttpass(char pass[30], char ch, int *i, int show);
void Ttakepassword(char pass[30]);      //-----To here is made by Tugay Talha İçen
int *SKloginsystem_main(int *Tsab);     //Made by Salih Karagöllü
int Exp_save(int Texp, int Tusrcnt);  //Made by Tugay Talha içen and Deniz Altınışık
void serial_Write(char choice[]);   //Made by Salih Karagöllü
void serial_Read();           //Made by Salih Karagöllü
void SKarduinoConnection(); //Made by Salih Karagöllü
int SKarduinoCodes();       //Made by Mert Emre
int SKconnectionPart();   //Made by Yasir Güneş
int SKhardwarePart();    //Made by Muhammed Emir Sivri
int SKprojectsPart();   //Made by Salih Karagöllü
//Also, you can see various kinds of implementations and integrations throughout all codes made by Salih Karagöllü.


int main() //Made by Salih Karagöllü
{ 
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
  SKarduinoConnection(); //It checks if arduino is connected or not. Inf not, program won't start.
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
  printf("\n\n\n           Warning!\n\n          After this message an introduction message will appear.\n\n         Please read it CAREFULLY because it will show only ONCE.");
  getch();
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
  printf("------------------------------------------------------\n");
  printf("\t\t  HELLO!\n   WELCOME to DEMONSTRATE!\n");
  printf("------------------------------------------------------\n");
  printf("This application will teach you these topics from scratch:\n");
  printf("1) How Arduino works\n");
  printf("2) Which internal and external hardwares and devices Arduino has\n");
  printf("3) How to use some basic hardwares\n");
  printf("4) How to setup circuits for Arduino\n");
  printf("5) How to program Arduino\n");
  printf("6) How is the interaction between Program and Hardware in Arduino system\n");
  printf("Above all, This application will guide you for learning Arduino step by step\n");
  printf("And it will help you to practise your information with some basic projects.\n");
  printf("------------------------------------------------------\n");
  printf("Use this link to download the Arduino IDE which we will use it program Arduino:\n");
  printf("FOR WINDOWS: https://downloads.arduino.cc/arduino-1.8.19-windows.exe\n");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
  getch();

  system("cls");
  int *Tsab = malloc(3 * sizeof(int));
  Tsab = SKloginsystem_main(Tsab);
  int DAexp = Tsab[0];
  int Tusercount = Tsab[1];
  Exp_save(DAexp, Tusercount);

  while (1)
  {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    int SKwhile = 1; //used for putting certain codes in loops
    sleep(1);
    int SKfirstExpBoundary = 260, SKsecondExpBoundary = 490; //exp system boundaries. First boundary lets you learn hardware category and second boundary lets you get into the projects.
    system("cls");
    printf("\n\n\n\nYour exp:%d\n\n[1]CODES\n[2]CONNECTIONS", DAexp);
    if (DAexp >= SKfirstExpBoundary)
    {
      printf("\n[3]HARDWARES");
    }
    if (DAexp >= SKsecondExpBoundary)
    {
      printf("\n[4]PROJECTS"); //EXP system will be added so the other categories will open after certain progression
    }
    printf("\n[0]EXIT");
    int SKi = 0;
    char SKinput1, SKinput2; //I made two versions of inputs because parent/child categories has to have different inputs so that it doesn't confuse program.
    while (SKi == 0)
    {
      printf("\nPlease select a category:"); //Selects main category
      scanf("%s", &SKinput1);
      if ((DAexp < SKfirstExpBoundary) && (SKinput1 >= '3'))
      {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
        printf("\n\nInvalid input.");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
      }
      else
      {
        SKi = 1;
      }
    }
    sleep(1);
    if (SKinput1 == '1')
    { //CODES category
      serial_Write("1");
      system("cls");
      printf("\n[1]C Codes\n[2]Arduino Codes\n[0]EXIT");
      printf("\n\nPlease select a category:");
      scanf("%s", &SKinput2);
      if (SKinput2 == '1')
      { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
        printf("Work in progress");
        //DENİZHANIN C KODU BÖLÜMÜ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
      }
      else if (SKinput2 == '2')
      {
        serial_Write("2");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        DAexp += SKarduinoCodes();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        Exp_save(DAexp, Tusercount);
      }else if(SKinput2=='0'){
        serial_Write("0");
      }
    }
    if (SKinput1 == '2')
    {
      serial_Write("2");
      system("cls");
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
      DAexp += SKconnectionPart();
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
      Exp_save(DAexp, Tusercount);
    }
    if ((SKfirstExpBoundary <= DAexp) && (SKinput1 == '3'))
    {
      serial_Write("3");
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
      DAexp+=SKhardwarePart();
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
      Exp_save(DAexp, Tusercount);
    }
    if ((SKsecondExpBoundary <= DAexp) && (SKinput1 == '4'))
    { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
      DAexp+=SKprojectsPart();
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
      Exp_save(DAexp, Tusercount);
    }
    if (SKinput1 == '0')
    {

      Exp_save(DAexp, Tusercount);
      exit(0);
    }
  }
  return 0;
}



//------------------------------------------------------------------------------------------------------------------------------------------------------------




void serial_Write(char choice[])
{

  HANDLE SKcommHandle;
  char SKportName[] = "\\\\.\\COM5"; // it depends on device
  BOOL SKstatus;

  SKcommHandle = CreateFile(SKportName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL); // opens the serial port
  DCB dcbserialParams = {0};                                                                            //For configuring parameters of communication, DCB structure is needed.
  dcbserialParams.DCBlength = sizeof(dcbserialParams);

  SKstatus = GetCommState(SKcommHandle, &dcbserialParams);

  dcbserialParams.BaudRate = CBR_9600;
  dcbserialParams.ByteSize = 8;
  dcbserialParams.StopBits = ONESTOPBIT;
  dcbserialParams.Parity = NOPARITY;

  SKstatus = SetCommState(SKcommHandle, &dcbserialParams);

  COMMTIMEOUTS SKtimeouts = {0}; //COMMTIMEOUTS structure contains the time-out parameters for a communication device.

  SKtimeouts.ReadIntervalTimeout = 50;
  SKtimeouts.ReadTotalTimeoutConstant = 50;
  SKtimeouts.ReadTotalTimeoutMultiplier = 10;
  SKtimeouts.WriteTotalTimeoutConstant = 50;
  SKtimeouts.WriteTotalTimeoutMultiplier = 10;

  char lpBuffer[10];

  strcpy(lpBuffer, choice);

  DWORD SKbytesToWrite;
  DWORD SKbytesWritten = 0;

  SKbytesToWrite = sizeof(lpBuffer);

  SKstatus = WriteFile(SKcommHandle, lpBuffer, SKbytesToWrite, &SKbytesWritten, NULL);

  CloseHandle(SKcommHandle);
}

void serial_Read()
{

  HANDLE SKcommHandle;
  char SKportName[] = "\\\\.\\COM5"; // it depends on device
  BOOL SKstatus;
  DWORD dwEventMask;
  char SKtempCh;
  char SerialBuffer[256];
  DWORD NoBytesRead;

  SKcommHandle = CreateFile(SKportName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

  DCB dcbserialParams = {0};
  dcbserialParams.DCBlength = sizeof(dcbserialParams);

  SKstatus = GetCommState(SKcommHandle, &dcbserialParams);

  dcbserialParams.BaudRate = CBR_9600;
  dcbserialParams.ByteSize = 8;
  dcbserialParams.StopBits = ONESTOPBIT;
  dcbserialParams.Parity = NOPARITY;

  SKstatus = SetCommState(SKcommHandle, &dcbserialParams);

  COMMTIMEOUTS SKtimeouts = {0};

  SKtimeouts.ReadIntervalTimeout = 50;
  SKtimeouts.ReadTotalTimeoutConstant = 50;
  SKtimeouts.ReadTotalTimeoutMultiplier = 10;
  SKtimeouts.WriteTotalTimeoutConstant = 50;
  SKtimeouts.WriteTotalTimeoutMultiplier = 10;

  if (SetCommTimeouts(SKcommHandle, &SKtimeouts) == FALSE)
    return;

  SKstatus = SetCommMask(SKcommHandle, EV_RXCHAR);
  SKstatus = WaitCommEvent(SKcommHandle, &dwEventMask, NULL);

  int i = 0;
  do
  {
    SKstatus = ReadFile(SKcommHandle, &SKtempCh, sizeof(SKtempCh), &NoBytesRead, NULL);
    SerialBuffer[i] = SKtempCh;
    i++;
  } while (NoBytesRead > 0);

  int j = 0;
  for (j = 0; j < i - 1; j++)
    printf("%c", SerialBuffer[j]);

  CloseHandle(SKcommHandle);
}


int SKconnectionPart()
{
  int SKexpChange = 0, SKwhile = 1;
  serial_Write("0");
  serial_Read();
  while (SKwhile == 1)
  {

    int baglantisecim;
    while (baglantisecim != 9)
    {
    baglantisecim:
      printf("\nPLEASE SELECT:"); // Baglanti yerine girdik artik konulari seciyoruz
      scanf("%d", &baglantisecim);
      if (baglantisecim == 1)
      { // reset konusunu sectik
        system("cls");
        printf("---------------------------------------------------------\n");
        printf("RESET BUTTON\n\n");
        printf("The reset button does pretty much the same as unplugging the board and plugging it back in.\nIt restarts your program from the beginning.\n");
        printf("\nThe same thing happens when you program the board - the USB interface presses the reset button for you.\nThat then enters the bootloader for a second or two so it can try and program it.\n");
        printf("\nWhen you reset the board the LED on pin 13 should flash a couple of times\nwhile it's in the bootloader before it runs whatever program you have programmed in.\n");
        printf("If that LED doesn't flash when you press the reset button\nthen there is a serious fault with your board which will take further diagnostic.\n");
        printf("If you have anything else plugged into the Arduino then unplug it.\n");
        printf("Try powering the Arduino from different power supplies.\n");
        printf("---------------------------------------------------------\n");
        SKexpChange += 10;
        serial_Write("5");
        serial_Read();    // Arduino reset konusunu bize anlatti
        int resetbtsecim; // resetten cikmak icin burada secim yapıyoruz
        scanf("%d", &resetbtsecim);
        if (resetbtsecim == 0)
        {                    // cikmayi secerse konu ekranı seçme yerine gitmemiz lazım
          serial_Write("0"); // Konu secme ekranını seçiyoruz
          system("cls");
          serial_Read(); // Konu seçme ekranı karşımıza geliyor.
        }
        goto baglantisecim;
      }
      if (baglantisecim == 2)
      { // Pin charasteristics konusunu sectik
        system("cls");
        printf("---------------------------------------------------------\n");
        printf("PINS FEATURES\n");
        printf("\nInput/Output (I/O):\nThere are 14 digital and 6 analog input/output pins.\nThe logic level of all of these pins is 5V.\nEach pin works with a maximum input and output current of 40mA.\nIn addition, some pins have different properties.\n\nSpecial pins are as follows:\n");
        printf("\nSerial Communication - 0 (RX) and 1 (TX): TTL Used to receive (RX) and transmit (TX) serial data.\nThese pins are also used when uploading a program from the computer to the card or while making mutual communication between the computer and UNO.\nFor this reason, these pins should not be used when the program is loaded on the card or when communication is established between the card and the computer.\n");
        printf("\nExternal Interrupt - 2 and 3:\nThese pins can be used as rising edge, falling edge or change interrupt pins.\n");
        printf("\nPWM- 3,5,6,9,10 and 11:\n8-bit resolution PWM output pins.\n");
        printf("\nSPI-10 (SS), 11 (MOSI), 12 (MISO), 13 (SCK):\nThese pins are used for SPI communication.\n");
        printf("\nLED- 13:\nThere is a built-in LED on the board (indicated by the letter L). This LED is connected to pin 13.\nWhen set to HIGH, the LED will turn on, and when set to LOW, it will turn off.\n");
        printf("\nAnalog- A0,A1,A2,A3,A4,A5:\nThere are 6 analog input pins with 10-bit resolution.\nThese pins can also be used for digital input and output.\nThe measuring range of the pins is 0-5V. By using AREF pin and analogReference() function,\nthe lower limit can be increased and the upper limit can be decreased.\n");
        printf("\nI2C- A4 or SDA pin and A5 or SCL pin:\nThese pins are used for I2C communication.\n");
        printf("\nAREF:\nMeasurement reference pin for analog inputs.\n");
        printf("\nReset:\nThis pin is set to LOW for reset. Instead, the Reset button on the card can be pressed.\n");
        printf("\nArduino Uno PWM Pin\n");
        printf("As we mentioned above, PWM pins are pins 3,5,6,9,10 and 11.\nWith PWM outputs, analog controls such as motor speed control and light brightness can be made.\n");
        printf("\nPRESS 2 TO SEE ALL THE PINS\n");
        printf("\n---------------------------------------------------------\n");
        SKexpChange += 10;
        serial_Write("2");
        serial_Read();    // Arduino Pin charasteristics konusunu bize anlatti
        int pincharsecim; // Pin charasteristics konusundan cikmak icin burada secim yapıyoruz
        scanf("%d", &pincharsecim);
        if (pincharsecim == 0)
        {                    // cikmayi secerse konu ekranı seçme yerine gitmemiz lazım
          serial_Write("0"); // Konu secme ekranını seçiyoruz.
          system("cls");
          serial_Read(); // Konu seçme ekranı karşımıza geliyor.
          goto baglantisecim;
        }
        if (pincharsecim == 2)
        {
          system("PNG\\pins.jpg");
          serial_Write("2");
          serial_Read();
          scanf("%d", &pincharsecim);
          if (pincharsecim == 0)
          {                    // cikmayi secerse konu ekranı seçme yerine gitmemiz lazım
            serial_Write("0"); // Konu secme ekranını seçiyoruz.
            system("cls");
            serial_Read(); // Konu seçme ekranı karşımıza geliyor.
            goto baglantisecim;
          }
        }
      }
      if (baglantisecim == 3)
      { // Breadboard konusunu sectik
        system("cls");
        printf("---------------------------------------------------------\n");
        printf("BREADBOARD\n\n");
        printf("A Breadboard is simply a board for prototyping or building circuits on.\nIt allows you to place components and connections on the board to make circuits without soldering.\n");
        printf("\nThe holes in the breadboard take care of your connections by physically holding onto parts or wires\nwhere you put them and electrically connecting them inside the board.\n");
        printf("\nThe ease of use and speed are great for learning and quick prototyping of simple circuits.\nMore complex circuits and high frequency circuits are less suited to breadboarding.\n");
        printf("\nBreadboard circuits are also not ideal for long term use\nLike circuits built on perfboard (protoboard) or PCB (printed circuit board)\n");
        printf("But they also don't have the soldering like protoboards, or design and manufacturing costs like PCB's.\n");
        printf("\nIn this video you can learn how to use breadboard https://bit.ly/3tL4MXS\n");
        printf("\nTO SEE AN EXAMPLE PROJECT OF BREADBOARD PRESS 1:\n");
        printf("---------------------------------------------------------\n");
        SKexpChange += 10;
        serial_Write("3");
        serial_Read();       // Breadboard konusunu bize anlatti
        int breadboardsecim; // Breadboard konusunundan cikmak icin burada secim yapıyoruz
        scanf("%d", &breadboardsecim);
        if (breadboardsecim == 0)
        {                    // cikmayi secerse konu ekranı seçme yerine gitmemiz lazım
          serial_Write("0"); // Konu secme ekranını seçiyoruz.
          system("cls");
          serial_Read(); // Konu seçme ekranı karşımıza geliyor.
          goto baglantisecim;
        }
        if (breadboardsecim == 1)
        {
          system("cls");
          printf("---------------------------------------------------------\n");
          printf("\nWE ARE GOING TO LIGHT UP A LED ON THE BREADBOARD\n");
          printf("\nTO DO THAT WE ARE GOING TO USE THESE:\n");
          printf("2 CABLES\n");
          printf("1 LED\n");
          printf("1 RESISTANCE\n");
          printf("AND WE'RE GOING TO SETUP EVERYTHING JUST LIKE IN THE PICTURES\n");
          printf("\nPress any key to see the picture of setup:");
          getch();
          system("PNG\\circuitalone.png");
          printf("\nPress any key to see the picture of setup in practise:");
          getch();
          system("PNG\\circuitalonereal.jpeg");
          printf("\nPress any key to see the code:");
          getch();
          system("PNG\\code.png");
          printf("\n\nTO CHECK IF YOUR SETUP WORKS PRESS 2:\n");
          printf("---------------------------------------------------------\n");
          SKexpChange += 10;
        }
        serial_Write("3");
        serial_Read(); // Breadboard konusunu bize anlatti
        scanf("%d", &breadboardsecim);
        if (breadboardsecim == 0)
        {                    // cikmayi secerse konu ekranı seçme yerine gitmemiz lazım
          serial_Write("0"); // Konu secme ekranını seçiyoruz.
          system("cls");
          serial_Read(); // Konu seçme ekranı karşımıza geliyor.
          goto baglantisecim;
        }
        if (breadboardsecim == 2)
        {
          system("cls");
          printf("\nTO DO THIS PLUG A CABLE's ONE END TO PIN 3 AND PLUG THE ANOTHER END LIKE IN THE PICTURE");
          printf("\n\nYOU CAN KNOW IF YOUR BUILD IS WORKING BY NOTICING THAT THE LED's BRIGTNESS BECOME A LITTLE LOW");
          printf("\nPress any key to see the image of the setup:");
          getch();
          system("PNG\\circuitwtester.png");
          SKexpChange += 10;
          printf("\n\nIF YOU'RE DONE PRESS ANY KEY TO CONTINUE\n");
          getch();
        checkagain:
          serial_Write("c");
          system("cls");
          serial_Read();
          printf("IF YOU WANT TO CHECK AGAIN PRESS 2:\n");
          serial_Write("3");
          serial_Read(); // Ana menü için 0a bas.
          printf("\nPLEASE SELECT:");
          scanf("%d", &breadboardsecim);
          if (breadboardsecim == 0)
          {                    // cikmayi secerse konu ekranı seçme yerine gitmemiz lazım
            serial_Write("0"); // Konu secme ekranını seçiyoruz.
            system("cls");
            serial_Read(); // Konu seçme ekranı karşımıza geliyor.
            goto baglantisecim;
          }
          if (breadboardsecim == 2)
          {
            goto checkagain;
          }
        }
      }
      if (baglantisecim == 4)
      { // Analog pins konusunu sectik
        system("cls");
        printf("---------------------------------------------------------\n");
        printf("ANALOG PINS\n\n");
        printf("The Arduino Uno board has 6 analog pins.\nOur analog pins numbered in the range A0-A5 have a precision of 10 bits.\nThese analog pins can be used to read signals from analog sensors or to generate voltage to our sensors.\nWe can also perform digital input and output operations by controlling our analog pins like digital pins.\n");
        printf("\nAnalog pins can be set for input and output, just like digital pins are grooved.\nFor this reason, in order to get healthy feedback from our analog pins,\nwe must pay attention to the mode of our pin being compatible with our use request.\n");
        printf("analogReference()\n");
        printf("\nUsage: analogReference (parameter)\n");
        printf("It allows us to set the reference voltage used in input works of analog pins.\nThanks to this process, we can make more precise measurements.\n");
        printf("\nIt has 5 parameters:\n");
        printf("DEFAULT      : Allows Arduino boards to operate at default voltages of 5V.\n");
        printf("INTERNAL     : Sets the reference voltage of our analog pins to 1.1V (for Atmega328 and Atmega168).\n");
        printf("INTERNAL1V1  : Valid only for Arduino Mega boards and sets the reference voltage to 1.1V.\n");
        printf("INTERNAL2V56 : Valid only for Arduino Mega boards and sets the reference voltage to 2.56V.\n");
        printf("EXTERNAL     : Sets the voltages in the range of 0-5V applied from the Aref pin as the reference voltage.\n");
        printf("Note: When using the Aref pin, voltages less than 0V and greater than 5V should not be used,\nAnd the readings on the analog pins may not be correct for a short time after the analog reference is changed.\n");
        printf("\nanalogRead()\n");
        printf("Usage: analogRead(pin)\n");
        printf("This function is used to read the value from the specified pin.\nThe analogRead function interprets and returns the input voltage on our analog pins with 10-bit precision in the range of 0-1023.\nWith the conversion process performed here, the numerical equivalent of the input voltage between 0V and 5V (default) in the range of 0-1023 is reached.\nThe function performs reading from the pin it takes as a parameter.\n");
        printf("\nanalogWrite()\n");
        printf("Usage: analogWrite(pin)\n");
        printf("This function allows us to read the voltages that come as input to the pins in a 10-bit range, that is, in the range of 0 to 1023.\nWe can use this function on digital pins with PWM feature as well as analog pins.\n");
        printf("\n\nYou can watch this video for analogWrite and analogRead : https://youtu.be/5dVejyjTvVg");
        printf("\n\nTo see an example about analogRead and analogRead function press 2:\n");
        printf("---------------------------------------------------------\n");
        SKexpChange += 10;
        serial_Write("4");
        serial_Read();       // Analog pins konusunu bize anlatti
        int analogpinssecim; // Analog pins konusunundan cikmak icin burada secim yapıyoruz
        scanf("%d", &analogpinssecim);
        if (analogpinssecim == 0)
        {                    // cikmayi secerse konu ekranı seçme yerine gitmemiz lazım
          serial_Write("0"); // Konu secme ekranını seçiyoruz.
          system("cls");
          serial_Read(); // Konu seçme ekranı karşımıza geliyor.
          goto baglantisecim;
        }
        if (analogpinssecim == 2)
        {
          system("cls");
          printf("We are going to see the same example in the Breadboard example section but this is for analogRead and analogWrite\n");
          printf("\ndigitalWrite only takes 2 values because they writes digital signals for example:\n");
          printf("digitalWrite(6, HIGH), digitalWrite(6, LOW)\n");
          printf("but analogWrite can take infinite values between [0 - 255] because it writes analog signal.\n");
          printf("And analogRead can take values between [0 - 1023]\n");
          printf("\nBefore we begin to the example we should setup the circuit just like in the picture\n");
          printf("Press any key to see the setup\n");
          SKexpChange += 10;
          getch();
          system("PNG\\circuitwtester.png");
          printf("\n\nNow,you will see the LED if you write digitalWrite(6, 255) for the LED\n");
          printf("And you will see the voltage read by the analogRead(3) on the cable from analog pin 3 on the Serial Screen\n");
          printf("Press any key if you're ready\n");
          SKexpChange += 10;
          getch();
          system("PNG\\255andRead.png");
          printf("\n\nNow,you will see the LED if you write digitalWrite(6, 20) for the LED\n");
          printf("And you will see the voltage read by the analogRead(3) on the cable from analog pin 3 on the Serial Screen\n");
          printf("Press any key if you're ready\n");
          SKexpChange += 10;
          getch();
          system("PNG\\20andRead.png");
          printf("\n\nNow you will see the difference between analogWrite(6,255) and analogWrite(6,20)\n");
          printf("Press any key if you're ready\n");
          SKexpChange += 10;
          getch();
          system("PNG\\20vs255.png");
          printf("\n\nSo You can see the difference between the power of the LED's brightness\n");
          serial_Write("4");
          serial_Read();       // Analog pins konusunu bize anlatti
          int analogpinssecim; // Analog pins konusunundan cikmak icin burada secim yapıyoruz
          scanf("%d", &analogpinssecim);
          if (analogpinssecim == 0)
          {                    // cikmayi secerse konu ekranı seçme yerine gitmemiz lazım
            serial_Write("0"); // Konu secme ekranını seçiyoruz.
            system("cls");
            serial_Read(); // Konu seçme ekranı karşımıza geliyor.
            goto baglantisecim;
          }
        }
      }
      if (baglantisecim == 5)
      { // Power pins konusunu sectik
        system("cls");
        printf("---------------------------------------------------------\n");
        printf("POWER PINS\n\n");
        printf("We provide the electric power to Arduino by using USB cable between our computer and Arduino.\nSo the power source is our computer.\n");
        printf("But what if we use our Arduino as a power source to provide power for Arduino's external devices and hardwares?\n");
        printf("Then we use the POWER PINS on the Arduino.\n");
        printf("\nYou can see the POWER PINS at the bottom of this image: https://bit.ly/33vEuOC\n");
        printf("---------------------------------------------------------\n");
        SKexpChange += 10;
        serial_Write("5");
        serial_Read();
        int powerpinssecim; // Power pins konusunundan cikmak icin burada secim yapıyoruz
        scanf("%d", &powerpinssecim);
        if (powerpinssecim == 0)
        {                    // cikmayi secerse konu ekranı seçme yerine gitmemiz lazım
          serial_Write("0"); // Konu secme ekranını seçiyoruz.
          system("cls");
          serial_Read(); // Konu seçme ekranı karşımıza geliyor.
          goto baglantisecim;
        }
      }
      if (baglantisecim == 6)
      { // Digital PWM konusunu sectik
        system("cls");
        printf("---------------------------------------------------------\n");
        printf("So what is PWM pins?\n\n");
        printf("PWM stands for Pulse Width Modulation.\n");
        printf("To understand PWM we should know digital and analog signals.\n\n");
        printf("Digital signals are like binary numbers. They can only have two values.\nBut if we look at Analog Signals they can have any value. Unlimited. They are realistic.\n");
        printf("To get a better understanding we can give this example: Digital clock And the Wall Clock.\nThe Wall clock can show us every value of time but Digital clocks shows us spesific values of time.\n");
        printf("\nIn this link you can see analog and digital signal's difference better: https://bit.ly/3Ip9MFF\n");
        printf("\nSo, what does PWM pins?\n");
        printf("Because of we work on digital environment(Arduino) we can only get digital signals.\n");
        printf("But PWM pins helps us to convert digital signals to analog signals, so that we can have:\n");
        printf("Instead of getting one value of brightness we can have every value of brightness from very fade to very bright.\nBecause we can have different values of Volts between ( 0V - 5V).\n");
        printf("But in digital signals we can only have 0V(LOW) or 5V(HIGH).\n");
        printf("\nIn this video you can see the using of PWM pins to arrange the brightness of a led just as I just tell you above:\n");
        printf("https://youtu.be/2cNC4k8FMhQ?t=470\n");
        printf("\nFor now, this information is enough for you to understand the basics.\n");
        printf("---------------------------------------------------------\n");
        SKexpChange += 10;
        serial_Write("6");
        serial_Read();
        int pwmpinssecim; // Digital PWM konusunundan cikmak icin burada secim yapıyoruz
        scanf("%d", &pwmpinssecim);
        if (pwmpinssecim == 0)
        {                    // cikmayi secerse konu ekranı seçme yerine gitmemiz lazım
          serial_Write("0"); // Konu secme ekranını seçiyoruz.
        }
        system("cls");
        serial_Read(); // Konu seçme ekranı karşımıza geliyor.
        goto baglantisecim;
      }
      if (baglantisecim == 9)
      {
        SKwhile = 0;
        baglantisecim = 9;
        serial_Write("9");
        break;
      }
    }
  }
  return SKexpChange;
}
COORD Tcoordinate = {0, 0}; //İnitial coordinate for cursor
void cursor_coordinator(int x, int y)
{ //it is moving your consol cursor (it can use for easter egg :) if there is an opportunity )
  Tcoordinate.X = x;
  Tcoordinate.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Tcoordinate);
}

void umsleep(__int64 usec)
{
  HANDLE timer;
  LARGE_INTEGER ft;

  ft.QuadPart = -(10 * usec); // Convert to 100 nanosecond interval, negative value indicates relative time

  timer = CreateWaitableTimer(NULL, TRUE, NULL);
  SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
  WaitForSingleObject(timer, INFINITE);
  CloseHandle(timer);
}

void cursoreaster(int k)
{
  int i, j, p;
  p = 10000 / (8 + k);
  for (i = 0; i < 5 + k; i++)
  {
    for (j = 0; j < 125; j++)
    {
      cursor_coordinator(j, i);
      umsleep(p);
    }
  }
  umsleep(1000);
}

void Ttakeuserinfo(char st[30])
{
  fgets(st, 30, stdin);
  st[strlen(st) - 1] = '\0';
}

void Tclearpass(char pass[30], int show)
{
  int f = 0;
  for (f = 0; pass[f] != '\0'; f++)
  {
    umsleep(1000);
    printf("\b");
  }
  if (show)
    for (f = 0; pass[f] != '\0'; f++)
    {
      umsleep(1000);
      printf("%c", pass[f]);
    }
  else
    for (f = 0; pass[f] != '\0'; f++)
    {
      umsleep(1000);
      printf("*");
    }
}

int Ttpass(char pass[30], char ch, int *i, int show)
{
  int j;
  if (ch == 13 || ch == 9)
  { //if user enter enter or tab end the password will ended
    pass[(*i)] = '\0';
    return 1;
  }
  else if (ch == 8)
  {
    if ((*i) > 0)
    {
      (*i)--;
      printf("\b \b"); //back 1 step the cursor, change with space and back again
    }
  }
  else
  {
    pass[(*i)] = ch;
    (*i)++;
    pass[(*i)] = '\0';
    if (show)
      printf("%c \b", ch);
    else
      printf("* \b");
  }
  return 0;
}

void Ttakepassword(char pass[30])
{
  int i = 0, a = 1, z;
  char ch;
  int show = 0;
  while (1)
  {
    ch = getch();
    if (ch == 45)
    {
      if (show == 0)
        show = 1;
      else
        show = 0;
      Tclearpass(pass, show);
    }
    else if (Ttpass(pass, ch, &i, show))
      break;
  }
}

int *SKloginsystem_main(int *Tsab)
{
  FILE *Tfile1;
  int Tbas[2];
  int Tthink = 0;
  int a = 0;
  int *pointersalih = &a;
  FILE *Tfile2;
  char Tchoice, Tvvv;
  struct Tuser Tuserinf;
  int i, j, k, y, Tgd = 0;
  int *Tdg;
  Tdg = &Tgd;
  int SKa = 0;

  printf("\n\t\t\t-----------Welcome To DEMONSTRUCT Login Page-----------\n");
  while (SKa == 0)
  {
    printf(
        "\nPlease select your operation\n"
        "1. Login\n"
        "2. Signup\n"
        "3. Exit\n");
    printf("\nYOUR CHOICE:");
    scanf("%d", &Tchoice);
    fgetc(stdin); //To get the \n character clicked at the end of the scanf

    switch (Tchoice)
    {

    case 1:;
      char Tsinguser[30], Tsingpass[30];
      struct Tuser Tuserf;
      int m, n;

      printf("\nEnter your user name: ");
      Ttakeuserinfo(Tsinguser);
      printf("\nEnter your password (Press - to show password)): ");
      Ttakepassword(Tsingpass);

      Tfile2 = fopen("Users.dat", "r");
      int SKi = 0;
      while (fread(&Tuserf, sizeof(struct Tuser), 1, Tfile2))
      {
        Tgd += 1;
        Tthink = 0;
        if (!strcmp(Tuserf.user_name, Tsinguser))
        {
          if (!strcmp(Tuserf.password, Tsingpass))
          {
            for (m = 0; m < 30; m++)
            {
              cursor_coordinator(0, m);
              for (n = 0; n < 125; n++)
              {
                printf(" ");
              }
            }
            cursor_coordinator(0, 0);
            printf("\n\t\t\t---------Welcome To DEMONSTRUCT %s---------", Tuserf.name);
            printf("\n\n\t\tExperience:%d", Tuserf.experience);
            //connection point
            SKa = 1;
            sleep(2);
            Tbas[0] = Tuserf.experience;
            Tbas[1] = Tgd;
            Tsab = Tbas;
            return Tsab;
          }
          else
          {
            Tthink = 1;
          }
        }
        else
        {
          Tthink = 2;
        }
        SKi++;
        if (SKi == 3)
        {
          break;
        }
      }
      fclose(Tfile2);
      Beep(300, 500);
      if (Tthink == 1)
      {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
        printf("\nInvalid password");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        sleep(1);
      }

      if (Tthink == 2)
      {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
        printf("\nInvalid username");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        sleep(1);
      }
      break;
    case 2:
      //cursoreaster(4);
      printf("\nACCOUNT CREATION ");
      printf("\nEnter your name: ");
      Ttakeuserinfo(Tuserinf.name);
      //cursoreaster(7);
      printf("\nEnter your user name: ");
      Ttakeuserinfo(Tuserinf.user_name);
      printf("\nEnter your password (Press - to show password)): ");
      Ttakepassword(Tuserinf.password);
      Tuserinf.experience = 0;
      Tfile1 = fopen("Users.dat", "a+");
      fwrite(&Tuserinf, sizeof(struct Tuser), 1, Tfile1);

      if (fwrite != 0)
      {
        printf("\nYour account created succesfully");
        printf("\nYou are being redirected ");
        for (y = 0; y < 5; y++)
        {
          printf("%d", 5 - y);
          sleep(1);
          printf("\b \b");
        }
        for (m = 0; m < 30; m++)
        {
          cursor_coordinator(0, m);
          for (n = 0; n < 125; n++)
          {
            printf(" ");
          }
        }
        cursor_coordinator(0, 0);
        printf("\n\t\t\t---------Welcome To DEMONSTRUCT %s---------", Tuserinf.name);
        printf("\n\n\t  Experience:%d", Tuserinf.experience);
        //connection point
      }
      else
      {

        printf("\nUpps, something went wrong");
      }
      fclose(Tfile1);
      break;
    case 3:
      for (m = 0; m < 30; m++)
      {
        cursor_coordinator(0, m);
        for (n = 0; n < 125; n++)
        {
          printf(" ");
        }
      }
      cursor_coordinator(50, 13);
      printf("You can't exit");
      umsleep(1500000);
      for (y = 0; y < 17; y++)
      {
        printf("\b \b");
      }
      printf("I don't let you >:(");
      umsleep(1500000);
      for (y = 0; y < 19; y++)
      {
        printf("\b \b");
      }
      printf("It was just a joke");
      umsleep(1500000);
      for (y = 0; y < 19; y++)
      {
        printf("\b \b");
      }
      printf("   Exiting ");
      for (y = 0; y <= 3; y++)
      {
        printf("%d", 3 - y);
        sleep(1);
        printf("\b \b");
        if (y == 3)
        {
          exit(0);
        }
      }
    }
  }
  //return pointersalih;
}

int Exp_save(int Texp, int Tusrcnt)
{
  FILE *Tfile3;
  FILE *Tfile4;
  char Tvvv;
  struct Tuser Tuserinfk;
  int i, j, k, y, Tadana = 0;
  int SKa = 0;

  Tfile3 = fopen("Users.dat", "r");
  Tfile4 = fopen("Copy.dat", "w");
  while (fread(&Tuserinfk, sizeof(struct Tuser), 1, Tfile3))
  {
    (Tadana) += 1;
    if ((Tadana) == (Tusrcnt))
    {
      Tuserinfk.experience = Texp;
    }
    fwrite(&Tuserinfk, sizeof(struct Tuser), 1, Tfile4);
  }
  fclose(Tfile3);
  fclose(Tfile4);
  umsleep(10000);
  Tfile3 = fopen("Users.dat", "w");
  Tfile4 = fopen("Copy.dat", "r");
  while (fread(&Tuserinfk, sizeof(struct Tuser), 1, Tfile4))
  {

    fwrite(&Tuserinfk, sizeof(struct Tuser), 1, Tfile3);
  }
  fclose(Tfile3);
  fclose(Tfile4);
  return Texp;
}


int SKarduinoCodes()
{

  //MADE BY EMRE ATEŞOĞLU

  int SKexpChange = 0;

  int MA_lesson_select;

  printf("Welcome to basic arduino syntax education.\nIn this part we will learn most important arduino codes.\nTo see lesson menu press any button.\n");
  getch();
  system("cls");

selectmenu:
  printf("Please select from menu.\n");
  printf("(1)Serial Communication codes.\n"
         "(2)Other essential codes.\n"
         "(3)Digital/Analog I/O codes\n"
         "(0)Exit\n");

  scanf("%d", &MA_lesson_select);
  system("cls");

  switch (MA_lesson_select)
  {

  case 1:

  serialselect:

    printf("(1)Serial.begin()\n"
           "(2)Serial.print()\n"
           "(3)Serial.read()\n"
           "(4)Serial.available()\n"
           "(0)Previous Menu\n");
    scanf("%d", &MA_lesson_select);

    if (MA_lesson_select == 0)
    {
      system("cls");
      goto selectmenu;
    }

    switch (MA_lesson_select)
    {

    case 1:
      system("cls");
      printf("We use Serial.begin() code to open a serial communication port between arduino and computer.\n"
             "We put Serial.begin() to setup part of our code.\n"
             "Between parenthesis we should enter communication rate as bits per second (baud).\n"
             "Generally we use 9600 baud.\n\n");

      printf("Press any key to see example.");
      getch();

      system("cls");

      printf("void setup(){\n"
             "Serial.begin(9600);\n"
             "}\n"
             "void loop(){\n"
             "...\n"
             "}\n\n");
      printf("This way we start a serial communication with data transfer rate of 9600 bits per second\n");
      printf("Press any key to go back.\n");
      SKexpChange += 10;
      getch();
      system("cls");
      goto serialselect;

    case 2:
      system("cls");
      printf("We use Serial.print() to print a string or integer to serial monitor.\n"
             "We can also use Serial.println(). Difference is Serial.println() goes to next line after printing.\n"
             "It is similar to \\n in C language.\n");

      printf("Press any key to see example.");
      getch();

      system("cls");

      printf("void setup(){\n"
             "Serial.begin(9600);\n"
             "}\n"
             "void loop(){\n"
             "Serial.println(''Hello world'')\n"
             "}\n\n");

      printf("As output we should see Hello world in serial monitor.\n"
             "Since it is in void loop, it should keep printing hello world.\n");
      printf("Press any key to go back.\n");
      SKexpChange += 10;
      getch();
      system("cls");
      goto serialselect;

    case 3:
      system("cls");
      printf("We use Serial.read() to get user input from serial monitor.\n");

      printf("Press any key to see example.");
      getch();

      system("cls");

      printf("int userinput;\n\n"
             "void setup(){\n"
             "Serial.begin(9600);\n"
             "}\n"
             "void loop(){\n"
             "userinput = Serial.read()\n;"
             "}\n\n");

      printf("Now we can change value of userinput variable with user inputs.\n");
      printf("Press any key to go back.\n");
      SKexpChange += 10;
      getch();
      system("cls");
      goto serialselect;

    case 4:
      system("cls");
      printf("Our final code is Serial.available().\n"
             "Serial.available gets the number of characters available for reading from serial port.\n"
             "We can use Serial.available in if statements to make our program wait until user input.\n");
      printf("Press any key to see example.");
      getch();

      system("cls");

      printf("int userinput=0;\n\n"
             "void setup(){\n"
             "Serial.begin(9600);\n"
             "}\n"
             "void loop(){\n"
             "if(Serial.avaiable() > 0){\n"
             "userinput = Serial.read();\n"
             "\n"
             "Serial.print(''I received: '');\n"
             "Serial.println(userinput, DEC);\n"
             " }\n"
             "}\n\n");

      printf("This program prints inputted characters as byte values.\n");
      printf("Press any key to go back.\n");
      SKexpChange += 10;
      getch();
      system("cls");
      goto serialselect;
    }

  case 2:

  otherselect:

    printf("(1)delay()\n"
           "(2)delayMicroseconds()\n"
           "(3)randomseed()\n"
           "(4)random()\n"
           "(0)Previous Menu\n");
    scanf("%d", &MA_lesson_select);
    system("cls");

    if (MA_lesson_select == 0)
    {
      system("cls");
      goto selectmenu;
    }

    switch (MA_lesson_select)
    {

    case 1:

      printf("With delay() function we can make our program wait a certain amount of time.\n"
             "Inside parenthesis we put the amount of time we want our program to wait.\n"
             "This amount determines the delay time in miliseconds(1 Second = 1000 miliseconds)\n");

      printf("Press any key to see example.");
      getch();

      system("cls");

      printf("void setup(){\n"
             "Serial.begin(9600);\n"
             "}\n"
             "void loop(){\n"
             "Serial.println(''Hello World'')\n"
             "delay(1000);\n"
             "}\n\n");

      printf("This program waits 1000 miliseconds(1 second) after printing each Hello World \n");
      printf("Press any key to go back.\n");
      SKexpChange += 10;
      getch();
      system("cls");
      goto otherselect;

    case 2:
      printf("delayMicroseconds() works same as delay()\n"
             "delayMicroseconds waits in microseconds not in miliseconds(1 milisecond = 1000 microseconds)\n"
             "We use delayMicroseconds() function in programs that we need very small delay time.\n"
             "For example we use delayMicroseconds() function while setting up our HC-SR04 ultrasonic sensor.\n");
      printf("Press any key to go back.\n");
      SKexpChange += 10;
      getch();
      system("cls");
      goto otherselect;

    case 3:
      printf("We use randomseed() function to setup pseudo random generator.\n"
             "To get better results we can choose analogRead() on an unconnected pin as seed.(We will learn this function later.)\n"
             "This function should be in setup part of our code\n"
             "You can see example of random number generator after next lesson(random() function)");
      printf("Press any key to go back.\n");
      SKexpChange += 10;
      getch();
      system("cls");
      goto otherselect;

    case 4:
      printf("After setting up pseudo random generator we can get random numbers using random() function.\n"
             "Inside parenthesis we can put min and max numbers. random(min,max)\n"
             "You don't need to pick a minimum number. If you enter only one number it will be the max amount.\n"
             "Remember that our result can include min. But it excludes max number.\n");

      printf("Press any key to see example.");

      getch();

      system("cls");

      printf(
          "long randnumber;\n\n"
          "void setup(){\n"
          "Serial.begin(9600);\n"
          "randomseed(analogRead(0))\n"
          "}\n"
          "void loop(){\n"
          "randnumber = random(300);\n"
          "Serial.println(randnumber);\n"
          "delay(500);\n"
          "}\n\n");

      printf("Press any key to go back.\n");
      SKexpChange += 10;
      getch();
      system("cls");
      goto otherselect;
    }

  case 3:
  digitalanalogselect:

    printf("(1)pinMode()\n"
           "(2)digitalWrite()\n"
           "(3)digitalRead()\n"
           "(4)analogRead()\n"
           "(5)analogWrite()\n"
           "(6)pulseIn\n"
           "(0)Previous Menu\n");
    scanf("%d", &MA_lesson_select);
    system("cls");

    if (MA_lesson_select == 0)
    {
      system("cls");
      goto selectmenu;
    }

    switch (MA_lesson_select)
    {

    case 1:
      printf("With pinMode() function we can set selected digital pin to output or input mode.\n"
             "We use this function in setup part of our code.\n");

      printf("Press any key to see example.");
      getch();

      system("cls");

      printf("void setup(){\n"
             " Serial.begin(9600);\n"
             " pinMode(7,OUTPUT);\n"
             " pinMode(8, INPUT);\n"
             "}\n"
             "void loop(){\n"
             "...\n"
             "}\n\n");

      printf("In this situation digital pin 7 is set to output mode.\nOur arduino will get give outputs to device connected to digital pin 7.\n");
      printf("And for pin 8, arduino will get inputs from the device connected to digital pin 8.\n");

      printf("Press any key to go back.\n");
      SKexpChange += 10;
      getch();
      system("cls");
      goto digitalanalogselect;

    case 2:
      printf("After setting up pins to either input or output mode we can change the state of pin with digitalWrite() function.\n"
             "digitalWrite() writes HIGH or LOW value to selected pin. HIGH represents 5V and LOW represents 0V\n");

      printf("Press any key to see example.");
      getch();

      system("cls");

      printf("void setup(){\n"
             " Serial.begin(9600);\n"
             " pinMode(7,OUTPUT);\n"
             "}\n"
             "void loop(){\n"
             " digitalWrite(7, HIGH);\n"
             " delay(500);\n"
             " digitalWrite(7, LOW);\n"
             " delay(500);\n"
             "}\n\n");

      printf("If we connect a LED to pin 7 digitalWrite(7, HIGH) will turn LED on.\n"
             "After 500 miliseconds of delay digitalWrite(7, LOW) will turn LED off.\n"
             "So we get a blinking LED which wait half a second between each state.\n");
      printf("Press any key to go back.\n");
      SKexpChange += 10;
      getch();
      system("cls");
      goto digitalanalogselect;

    case 3:
      printf("With digitalRead() function we can get input from a device connected to a digital pin.\n"
             "Just like digitalWrite() digitalRead() gets either HIGH or LOW value.\n");

      printf("Press any key to see example.");
      getch();

      system("cls");

      printf("int value = 0;\n"
             "void setup(){\n"
             " Serial.begin(9600);\n"
             " pinMode(7,OUTPUT);\n"
             " pinMode(8, INPUT);\n"
             "}\n"
             "void loop(){\n"
             " value = digitalRead(8);\n"
             " digitalWrite(7,val);\n"
             "}\n\n");

      printf("In this situation we connect a LED to pin 7 and a push button to pin 8.\n"
             "With digitalRead() we can get the state of push button.\n"
             "If we press the button value variable becomes HIGH.\n"
             "Since digitalWrite() sends the value variable, LED will turn on.\n"
             "After a moment push button's state becomes LOW and LED turns off.\n"
             "We will give better examples of these kind of programs with devices later.\n");

      printf("Press any key to go back.\n");
      SKexpChange += 10;
      getch();
      system("cls");
      goto digitalanalogselect;

    case 4:
      printf("analogRead() raeds value from analog pins.\n"
             "Read value can be between 0 to 1023\n"
             "Most basic example from analogRead() is use of potetiometer.\n"
             "With potentiometer we can vary the brightness of a LED or speed of a motor.\n");

      printf("Press any key to see example.");
      getch();

      system("cls");

      printf(""
             "int analogpin = 3;\n"
             "int val=0;\n"
             "\n"
             "void setup(){\n"
             "Serial.begin(9600);\n"
             "}\n"
             "\n"
             "void loop(){\n"
             " val = analogRead(analogpin);\n"
             " Serial.println(val);\n"
             "}\n\n");

      printf("In this example we have a potetiometer connected to analog pin 3\n"
             "This code prints the value from potentiometer to serial monitor.\n"
             "As we stated this value varies from 0 to 1023\n");

      printf("Press any key to go back.\n");
      SKexpChange += 10;
      getch();
      system("cls");
      goto digitalanalogselect;

    case 5:
      printf("analogWrite() writes analog values to a pin.\n"
             "We can use analogWrite() to light a LED at varying brightnesses.\n"
             "Instead of HIGH or LOW, analogWrite() can write values from 0 to 255.\n");

      printf("Press any key to see example.");
      getch();

      system("cls");

      printf(""
             "int ledpin = 9;\n"
             "int analogpin = 3;\n"
             "int val=0;\n"
             "\n"
             "void setup(){\n"
             " pinMode(ledpin, OUTPUT);\n"
             "}\n"
             "\n"
             "void loop(){\n"
             " val = analogRead(analogPin);\n"
             " analogWrite(ledpin, val/4);\n"
             "}\n\n");

      printf("In this code we connect a LED to digital pin 9 and a potentiometer to analog pin 3.\n"
             "Since analogRead() read value from 0 to 1023 to need to divide that value to 4.\n"
             "With this code we can change the brightness of LED with potetiometer.\n");

      printf("Press any key to go back.\n");
      SKexpChange += 10;
      getch();
      system("cls");
      goto digitalanalogselect;

    case 6:
      printf("Our final function is pulseIn()\n"
             "We usually use this function with ultrasonic sensor.\n"
             "As you can understand from the name pulseIn reads a pulse from a pin.\n"
             "If we set it up to HIGH it waits until pin goes to HIGH from LOW and measures the time until it goes back to LOW.\n"
             "Return results is in microseconds\n");

      printf("Press any key to see example.");
      getch();

      system("cls");

      printf(""
             "int pin = 9;\n"
             "unsigned long duration;"
             "\n"
             "void setup(){\n"
             " Serial.begin(9600);\n"
             " pinMode(pin, INPUT);\n"
             "}\n"
             "\n"
             "void loop(){\n"
             " duration = pulseIn(pin,HIGH);\n"
             " Serial.println(duration);\n"
             "}\n\n");

      printf("This example measures the pulse from digital pin 9.\n"
             "We didn't use int, instead we used unsigned long because returned value can be very big.\n"
             "We can see better examples after learning about ultrasonic sensor.\n");

      printf("Press any key to go back.\n");
      SKexpChange += 10;
      getch();
      system("cls");
      goto digitalanalogselect;
    }

  case 0:
    break;
  }
  return SKexpChange;
}


void SKarduinoConnection()
{

  HANDLE SKcommHandle;
  char SKportName[] = "\\\\.\\COM5"; // it depends on device
  BOOL SKstatus;

  SKcommHandle = CreateFile(SKportName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL); // opens the serial port
  if (SKcommHandle == -1)
  {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    printf("\n\nPort couldn't be opened. Please check the C code file and put your port name in line 10 and 59.\n\n Suggestion: \n1-Open the Arduino IDE\n2-In the menu, click on Tools. The currently selected port is displayed in the Port row.\n3-Hover over the Port row to display all ports. For Arduino devices, the board name will typically be displayed after the port.");
    
    printf("\n\nIf you want a quick fix, just connect your arduino to COM5.\n\nPress any key to exit.");
    getch();
    exit(0);
  }
  else
  {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    printf("\n\nYour arduino has connected succesfully. Welcome to Demonstruct"); 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);


    
    DCB dcbserialParams = {0};                                                                            //For configuring parameters of communication, DCB structure is needed.
    dcbserialParams.DCBlength = sizeof(dcbserialParams);

    SKstatus = GetCommState(SKcommHandle, &dcbserialParams);

    dcbserialParams.BaudRate = CBR_9600;
    dcbserialParams.ByteSize = 8;
    dcbserialParams.StopBits = ONESTOPBIT;
    dcbserialParams.Parity = NOPARITY;

    SKstatus = SetCommState(SKcommHandle, &dcbserialParams);

    COMMTIMEOUTS SKtimeouts = {0}; //COMMTIMEOUTS structure contains the time-out parameters for a communication device.

    SKtimeouts.ReadIntervalTimeout = 50;
    SKtimeouts.ReadTotalTimeoutConstant = 50;
    SKtimeouts.ReadTotalTimeoutMultiplier = 10;
    SKtimeouts.WriteTotalTimeoutConstant = 50;
    SKtimeouts.WriteTotalTimeoutMultiplier = 10;

    char lpBuffer[10];

    CloseHandle(SKcommHandle);
  }
}


int SKhardwarePart()
{

  int SKwhile = 1;
  int SKexpChange = 0;
  int temp, a;

  while (SKwhile == 1)
  {
    printf("Welcome to Arduino Hardware Menu. Press any key to continue. ");
    getch();
    system("cls");

  initialmenu:
    printf("Select a hardware.\n\n"
           "(1)LED\n(2)Button\n(3)Buzzer\n(4)Potentiometer\n(5)Heat Sensor\n(6)Ultrasonic Sensor\n(0)Exit\n");

    printf("\nEnter here: ");
    scanf("%d", &temp);
    system("cls");

    switch (temp)
    {

    case 1:
    LEDs:
      printf("You can connect LEDs to Arduino by using a breadboard, a 220 ohm resistor and some wires.\n\n"
             "Please connect the LED getting help from the image.\n\n"
             "Press 2 to get a helping image.\n\n"
             "Press 1 when you're done connecting.\n\n"
             "Press 0 to go back to Hardware Selection Menu. ");
             SKexpChange+=10;
      scanf("%d", &temp);
      system("cls");
      switch (temp)
      {

      case 2:
        system("PNG\\LED1st.png");
        system("cls");
        goto LEDs;

      case 1:
        serial_Write("1");
        serial_Read();
        scanf("%d", &temp);
        system("cls");
        if (temp == 1)
        {
        LED2nd:
          printf("Here's a code that blinks an LED with a period of 200 ms (0.2 s). Try it!\n\n"
                 "Properly do the connections getting help from the image.\n\n"
                 "Press 1 to get a helping image.\n\n");
          printf("int LED = 13\n\n"
                 "void setup() {\n"
                 "pinMode(LED, OUTPUT);\n"
                 "}\n\n"

                 "void loop(){\n"
                 "digitalWrite(LED, HIGH);    // turn on LED\n"
                 "delay(200);                  // wait for 200ms\n"
                 "digitalWrite(LED, LOW);    // turn off LED\n"
                 "delay(200);                  // wait for 200ms and run the program again\n"
                 "}\n\n");
                 SKexpChange+=10;

          printf("Press 0 to go to Hardware Selection Menu.\n");
          scanf("%d", &temp);
          if (temp == 1)
          {
            system("PNG\\LED2nd.png");
            SKexpChange+=10;
            system("cls");
            goto LED2nd;
          }
          else if (temp == 0)
          {
            system("cls");
            goto initialmenu;
          }
        }
        else if (temp == 0)
        {
          system("cls");
          goto LEDs;
        }

      case 0:
        system("cls");
        goto initialmenu;
      }

    case 2:
    button:
      printf("You can get input from the user using a button.\n\n"
             "Please connect the button getting help from the image.\n\n"
             "Press 2 to get a helping image.\n\n"
             "Press 1 WHILE HOLDING THE BUTTON when you're done connecting.\n\n"
             "Press 0 to go back to Hardware Selection Menu. ");
             SKexpChange+=10;
      scanf("%d", &temp);
      system("cls");
      switch (temp)
      {

      case 2:
        system("PNG\\Button1st.png");
        system("cls");
        SKexpChange+=10;
        goto button;

      case 1:
        serial_Write("2");
        serial_Read();
        scanf("%d", &temp);
        system("cls");
        if (temp == 1)
        {
        button2nd:
          printf("Here's a code that turns on the LED when you press the button. Try it!\n\n"
                 "Properly do the connections getting help from the image.\n\n"
                 "Press 1 to get a helping image.\n\n");
          printf("const int LEDpin 8;\n"
                 "const int buttonPin 7;\n\n"
                 "void setup() {\n"
                 "  pinMode(LEDpin, OUTPUT);\n"
                 "  pinMode(buttonPin, INPUT);\n"
                 "}\n\n"

                 "void loop(){\n"
                 "  if (digitalRead(buttonPin) == HIGH) {;\n"
                 "    digitalWrite(LEDpin, HIGH);\n"
                 "  }\n"
                 "  else {\n"
                 "    digitalWrite(LEDpin, LOW);\n"
                 "  }\n"
                 "}\n\n");
                 SKexpChange+=10;

          printf("Press 0 to go to Hardware Selection Menu.\n");
          scanf("%d", &temp);
          if (temp == 1)
          {
            system("PNG\\Button2nd.jpg");
            system("cls");
            goto button2nd;
          }
          else if (temp == 0)
          {
            system("cls");
            goto initialmenu;
          }
        }

        else if (temp == 0)
        {
          system("cls");
          goto button;
        }

      case 0:
        system("cls");
        goto initialmenu;
      }

    case 3:
    buzzer:
      printf("The buzzer pin vibrates just like your phone on vibrate mode.\n\n"
             "Please connect the buzzer getting help from the image.\n\n"
             "Press 2 to get a helping image.\n\n"
             "Press 1 when you're done connecting.\n\n"
             "Press 0 to go back to Hardware Selection Menu. ");
             SKexpChange+=10;
      scanf("%d", &temp);
      system("cls");
      switch (temp)
      {

      case 2:
        system("PNG\\Buzzer1st.png");
        system("cls");
        SKexpChange+=10;
        goto buzzer;

      case 1:
        serial_Write("3");
        serial_Read();
        scanf("%d", &temp);
        system("cls");
        if (temp == 1)
        {
        buzzer2nd:
          printf("Here's a code that vibrates the buzzer with a period of 1000 ms (1 s). Try it!\n\n"
                 "Properly do the connections getting help from the image. (pay attention to +&- sides)\n\n"
                 "Press 1 to get a helping image.\n\n"
                 "Try it on your Arduino.\n\n");
          printf("int buzzerpin = 7;\n\n"
                 "void setup() {\n"
                 "pinMode(buzzerpin, OUTPUT);\n"
                 "}\n\n"

                 "void loop(){\n"
                 "  digitalWrite(buzzerpin, HIGH);\n"
                 "  delay(1000);\n"
                 "  digitalWrite(buzzerpin, LOW);\n"
                 "  delay(1000);\n"
                 "}\n\n");
                 SKexpChange+=10;

          printf("Press 0 to go to Hardware Selection Menu.\n");
          scanf("%d", &temp);
          if (temp == 1)
          {
            system("PNG\\Buzzer2nd.png");
            system("cls");
            SKexpChange+=10;
            goto buzzer2nd;
          }
          else if (temp == 0)
          {
            system("cls");
            goto initialmenu;
          }
        }

        else if (temp == 0)
        {
          system("cls");
          goto buzzer;
        }

      case 0:
        system("cls");
        goto initialmenu;
      }

    case 4:
    potentiometer:
      printf("A potentiometer is a device that provides a varying amount of resistance when you turn its shaft.\n\n"
             "It can be used to change the brightness of a LED.\n\n"
             "Please connect the potentiometer getting help from the image.\n\n"
             "Press 2 to get a helping image.\n\n"
             "Press 1 when you're done connecting.\n\n"
             "Press 0 to go back to Hardware Selection Menu. ");
             SKexpChange+=10;
      scanf("%d", &temp);
      system("cls");

      switch (temp)
      {

      case 2:
        system("PNG\\Potentiometer1st.png");
        system("cls");
        SKexpChange+=10;
        goto potentiometer;

      case 1:
        serial_Write("4");
        serial_Read();
        scanf("%d", &temp);
        system("cls");
        if (temp == 1)
        {
        potentiometer2nd:
          printf("Here's a code that changes brightness of an LED when the potentiometer's shaft is turned. Try it!\n\n"
                 "Properly do the connections getting help from the image.\n\n"
                 "Press 1 to get a helping image.\n\n");
          printf("int sensorval;\n"
                 "const int LEDpin 11;\n"
                 "const int potentiometerPin A1;\n"
                 "void setup() {\n"
                 "  pinMode(LEDpin, OUTPUT);\n"
                 "}\n\n"

                 "void loop(){\n"
                 "  int potentiometerValue = analogRead(potentiometerPin);\n"
                 "  int brightness = potentiometerValue / 4;\n"
                 "  analogWrite(LEDpin, brightness);\n"
                 "  delay(1);\n"
                 "}\n"
                 "//see bit.ly/3AnAn2W for further explanation\n\n");
                 SKexpChange+=10;

          printf("Press 0 to go to Hardware Selection Menu.\n");
          scanf("%d", &temp);
          if (temp == 1)
          {
            system("PNG\\Potentiometer2nd.png");
            system("cls");
            goto potentiometer2nd;
          }
          else if (temp == 0)
          {
            system("cls");
            goto initialmenu;
          }
        }

        else if (temp == 0)
        {
          system("cls");
          goto potentiometer;
        }

      case 0:
        system("cls");
        goto initialmenu;
      }

    case 5:
    heatsensor:
      printf("Heat sensor lets you know what the temperature of the environment is.\n\n"
             "Please connect the heat sensor getting help from the image.\n\n"
             "Press 2 to get a helping image.\n\n"
             "Press 1 when you're done connecting.\n\n"
             "Press 0 to go back to Hardware Selection Menu. ");
             SKexpChange+=10;

      scanf("%d", &temp);
      system("cls");
      switch (temp)
      {

      case 2:
        system("PNG\\HeatSensor1st.png");
        system("cls");
        SKexpChange+=10;
        goto heatsensor;

      case 1:
        serial_Write("5");
        serial_Read();
        scanf("%d", &temp);
        system("cls");
        if (temp == 1)
        {
        heatsensor2nd:
          printf("Here's a code that prints the temperature on the Serial Monitor continuously. Try it!\n\n"
                 "Properly do the connections getting help from the image.\n\n"
                 "Press 1 to get a helping image.\n\n");
          printf("int sensorval;\n"
                 "int sensorPin = 1;\n"
                 "float celsius;\n\n"
                 "void setup() {\n"
                 "  Serial.begin(9600);\n"
                 "}\n\n"

                 "void loop(){\n"
                 "  sensorval = analogRead(sensorPin);\n"
                 "  celsius = (sensorval/1023:)*500; //convert sensor value to celsius\n"
                 "  Serial.print(\"Temperature: \");\n"
                 "  Serial.print(celsius);\n"
                 "  Serial.println(\" *C\");\n"
                 "  delay(100);\n"
                 "}\n\n");
                 SKexpChange+=10;

          printf("Press 0 to go to Hardware Selection Menu.\n");
          scanf("%d", &temp);
          if (temp == 1)
          {
            system("PNG\\HeatSensor2nd.png");
            system("cls");
            SKexpChange+=10;
            goto heatsensor2nd;
          }
          else if (temp == 0)
          {
            system("cls");
            goto initialmenu;
          }
        }

        else if (temp == 0)
        {
          system("cls");
          goto heatsensor;
        }

      case 0:
        system("cls");
        goto initialmenu;
      }

    case 6:
    ultrasound:
      printf("An ultrasound sensor helps determine the distance of an object using soundwaves.\n"
             "It can read values between 2 cm and 400 cm.\n\n"
             "Please connect the ultrasonic sensor getting help from the image.\n\n"
             "Press 2 to get a helping image.\n\n"
             "Press 1 when you're done connecting.\n\n"
             "Press 0 to go back to Hardware Selection Menu. ");
             SKexpChange+=10;

      scanf("%d", &temp);
      system("cls");
      switch (temp)
      {

      case 2:
        system("PNG\\Ultrasonic1st.png");
        SKexpChange+=10;
        system("cls");
        goto ultrasound;

      case 1:
        serial_Write("6");
        serial_Read();
        scanf("%d", &temp);
        system("cls");
        if (temp == 1)
        {
        ultrasound2nd:
          printf("Here's a code that prints on the Serial Monitor the distance \n"
                 "of an object in front of the ultrasonic sensor continuously. Try it!\n\n"
                 "Properly do the connections getting help from the image.\n\n"
                 "Press 1 to get a helping image.\n\n");
          printf("long duration;\n"
                 "int distance;\n\n"
                 "void setup() {\n"
                 "  Serial.begin(9600);\n"
                 "}\n\n"

                 "void loop(){\n"
                 " delay(100);\n"
                 " // You can see 'trig' and 'echo' written on the sensor\n"
                 "  int trigPin=4; \n"
                 "  int echoPin=3;\n"
                 "  pinMode(trigPin, OUTPUT); \n"
                 "  pinMode(echoPin, INPUT);\n\n"
                 "  digitalWrite(trigPin, LOW);\n"
                 "  delayMicroseconds(2);\n\n"
                 "  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds\n"
                 "  digitalWrite(trigPin, HIGH);\n"
                 "  delayMicroseconds(10);\n"
                 "  digitalWrite(trigPin, LOW);\n\n"
                 "  // Reads the echoPin, returns the sound wave travel time in microseconds\n"
                 "  duration = pulseIn(echoPin, HIGH);\n\n"
                 "  // Calculating the distance\n"
                 "  distance = duration * 0.034 / 2;   // Speed of sound wave divided by 2 (go and back)\n\n"
                 "  Serial.print(\"Distance: \");\n"
                 "  Serial.print(distance);\n"
                 "  Serial.println(\" cm\");\n"
                 "}\n"
                 "//see bit.ly/33NpFXw for further explanation\n\n");
                 SKexpChange+=10;

          printf("Press 0 to go to Hardware Selection Menu.\n");
          scanf("%d", &temp);
          if (temp == 1)
          {
            system("PNG\\Ultrasonic2nd.png");
            system("cls");
            SKexpChange+=10;
            goto ultrasound2nd;
          }
          else if (temp == 0)
          {
            system("cls");
            goto initialmenu;
          }
        }

        else if (temp == 0)
        {
          system("cls");
          goto ultrasound;
        }

      case 0:
        system("cls");
        goto initialmenu;
      }

    case 0:
      serial_Write("0");
      SKwhile = 0;
    }
  }
  SKwhile = 1;
  return SKexpChange;
}


int SKprojectsPart()
{   
  sleep(1);
    serial_Write("4");
    system("cls");
    int SKexpChange=0;
    while(1){
    
    int SKi = 1, SKa, SKcount = 0, SKj, SKk = 0, SKinput;
    char SKreadString[256], SKreadChar;

    char SKchoice;

    printf("Welcome to projects category. Here you will create basic projects to understand arduino better.\n");
    printf("\nPlease select a project:\n\n[1]Traffic light controller\n[2]Button press counter\n[3]Ultrasonic range meter\n[0]EXIT");
    scanf("%s", &SKchoice);

    system("cls");

    if (SKchoice == '1')
    {
        serial_Write("1");
        printf("Components needed:\n\n-1 x 10k-ohm resistor\n-1 x pushbutton switch\n-6 x 220-ohm resistors\n-6 x 220-ohm resistors\n-Connecting wires\n-Red, yellow and green LEDs\n\nIf you have gathered all of these, press any key to continue.");
        getch();
        system("cls");
        printf("SETTING UP THE BREADBOARD\n\nTRY TO BUILD INCOMING SCHEMA");
        sleep(3);
        system("PNG\\Arduino_Traffic_Light.png");
        SKexpChange+=10;
        while (SKi == 1)
        {
            system("cls");
            printf("\nTo check if your wirings and connections are correct, press 1.");
            printf("\n\nIf you want to see  the schema again, press 2.");
            if (SKk > 0)
            {
                printf("\n\n----You have checked your circuit. To go to the next step, press 3.----");
            }
            printf("\n\nPress 0 to exit.");
            scanf("%d", &SKj);
            if (SKj == 1)
            {

                serial_Write("1");
                printf("Please wait for 5 seconds.");
                sleep(5);
                system("cls");
                printf("\nNow please connect the pin 11 on arduino and a2 on breadboard with a cable. If you already did, unplug the cable from breadboard and replug.\nWhen you are done, press any key to continue.");
                getch();
                serial_Write("1");
                system("cls");
                printf("Result of connection checking is:");
                serial_Read();
                getch();
                SKk++;
                SKexpChange+=10;
            }
            else if (SKj == 2)
            {
                system("PNG\\Arduino_Traffic_Light.png");
            }
            else if (SKj == 3)
            {
                SKi = 0;
            }
            else if (SKj == 0)
            {
                break;
            }
        }
        system("cls");
        printf("Now, let's code! If you look at your arduino, I will be running an example of the code!");
        while (SKi == 0)
        {
            system("cls");
            printf("\n\n\n-Press 1 to initialize the example and see what code will run on it.\n-If you want to try yourself, press 2 to see tips and tricks which can help you code better.\n-To exit, press 0.");
            scanf("%d", &SKinput);
            serial_Write("2");
            if (SKinput == 1)
            {
                serial_Write("2");
                system("cls");
                printf("int red = 10;\nint yellow = 9;\nint green = 8;\n\nvoid setup()\n    pinMode(red, OUTPUT);\n    pinMode(yellow, OUTPUT);\n    pinMode(green, OUTPUT);\n}\nvoid loop(){\n    changeLights();\n    delay(15000);\n}\nvoid changeLights(){\n    // green off, yellow on for 3 seconds    digitalWrite(green, LOW);\n    digitalWrite(yellow, HIGH);\n    delay(3000);\n    // turn off yellow, then turn red on for 5 seconds\n    digitalWrite(yellow, LOW);\n    digitalWrite(red, HIGH);\n    delay(5000);\n    // red and yellow on for 2 seconds (red is already on though)\n    digitalWrite(yellow, HIGH);\n    delay(2000);\n    // turn off red and yellow, then turn on green\n    digitalWrite(yellow, LOW);\n    digitalWrite(red, LOW);\n    digitalWrite(green, HIGH);\n    delay(3000);\n}\n\nPress any key to close.");
                getch();
                SKexpChange+=10;
            }
            else if (SKinput == 2)
            {
                printf("-Make your variable names as descriptive as possible.\n-Improve the visual cue by Indentation.\n-Simple comments can ease up future coding.\n-Organize and reuse your code with functions()\n-Documentation is key,In-depth documentation always saves money and time for backend tasks as it will otherwise \nbe daunting to get a grip of the work for someone who is reading your work for the first time.");
                getch();
                SKexpChange+=10;
            }
            else
            {
                serial_Write("0");
                SKi = 2;
            }
        }
    }
    if (SKchoice == '2')
    {
        serial_Write("2");
        printf("\n\n-1 x pushbutton switch\n-2 x 220-ohm resistors\n-Connecting wires\n-1 x Red, yellow or green LED\n\nIf you have gathered all of these, press any key to continue.");//component needs will be put here
        getch();
        system("cls");
        printf("SETTING UP THE BREADBOARD\n\nTRY TO BUILD INCOMING SCHEMA");
        sleep(3);
        system("PNG\\Arduino-counter.png");
        SKexpChange+=10;
        while (SKi == 1)
        {
            system("cls");
            printf("\n-To check if your wirings and connections are correct, press 1.\n\n-If you want to see  the schema again, press 2.");
            if (SKk > 0)
            {
                printf("\n\n----You have checked your circuit. To go to the next step, press 3.----");
            }
            printf("\n\n-To exit, press 0.");
            scanf("%d", &SKj);
            if (SKj == 1)
            {

                system("cls");
                printf("\nNow i after this message, i need you to press down the button and stay still until the program tells you if your circuit is complete or not. \nPress any key to continue.");
                getch();
                serial_Write("1");
                system("cls");
                printf("Result of connection checking is:");
                serial_Read();
                getch();
                SKk++;
                SKexpChange+=10;
            }
            else if (SKj == 2)
            {
                system("PNG\\Arduino-Counter.png");
            }
            else if (SKj == 3)
            {
                SKi = 0;
            }else if(SKj==0){
              serial_Write("0");
                break;
            }
                system("cls");
            printf("Now, let's code! If you look at your arduino, I will be running an example of the code!");
            while (SKi == 0)
            {
                system("cls");
                printf("\n\n\n-Press 1 to initialize the example and see what code will run on it.\n-If you want to try yourself, press 2 to see tips and tricks which can help you code better.");
                printf("\n-Press 0 to exit.");
                scanf("%d", &SKinput);
                serial_Write("2");
                if (SKinput == 1)
                {
                    serial_Write("2");
                    system("cls");
                    printf("const int buttonPin = 2;     // the number of the pushbutton pin\nconst int ledPin =  9;      // the number of the LED pin\n\n// variables will change:\nint buttonState = 0;         // variable for reading the pushbutton status\nint count_value =0;\nint prestate =0;\nvoid setup() {\n  // initialize the LED pin as an output:\n  pinMode(ledPin, OUTPUT);\n  // initialize the pushbutton pin as an input:\n  pinMode(buttonPin, INPUT);\n  Serial.begin(9600);\n}\n\nvoid loop() {\n  // read the state of the pushbutton value:\n  buttonState = digitalRead(buttonPin);\n\n  // check if the pushbutton is pressed. If it is, then the buttonState is HIGH:\n  if (buttonState == HIGH && prestate == 0) {\n    count_value++;\n    Serial.println(count_value);\n    // turn LED on\n    digitalWrite(ledPin, HIGH);\n    delay(100);\n    // turn LED off\n    digitalWrite(ledPin, LOW);\n\n    prestate = 1;  } else if(buttonState == LOW) {\n    prestate = 0;\n  }\n}\n\nPress any key to start the interactive example.");
                    getch();
                    system("cls");
                    char SK_i[] = {0};
                    SKcount = 0;
                    while (1)
                    {
                        serial_Read();
                        SKcount++;
                        if (SKcount % 15 == 0)
                        {
                            printf("Press 1 to exit the program.");
                            scanf("%s", &SK_i);
                            if (SK_i[0] == '1')
                            {
                                serial_Write("1");
                                break;
                            }
                        }SKexpChange+=10;
                    }
                }
                else if (SKinput == 2)
                {
                    printf("-Make your variable names as descriptive as possible.\n-Improve the visual cue by Indentation.\n-Simple comments can ease up future coding.\n-Organize and reuse your code with functions()\n-Documentation is key,In-depth documentation always saves money and time for backend tasks as it will otherwise \nbe daunting to get a grip of the work for someone who is reading your work for the first time.");
                    getch();
                    SKexpChange+=10;
                    
                } else{
                    SKi=2;
                }                
            }
        }
    }
    if (SKchoice == '3')
    {
        serial_Write("3");
        printf("This project is under maintenance. Please wait for a further update.");
        SKexpChange+=10;
    }
    if(SKchoice=='0'){
      serial_Write("0");
        break;
    }
    }
    return SKexpChange;
}