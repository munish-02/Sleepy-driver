#include <SoftwareSerial.h>
const int Alch = A7;
const int analogInPin = A4; 
const int analogOutPin = 4;
const int xpin = A3;               
const int ypin = A2;                 
const int zpin = A1; 
int sensorValue = 0;      
int outputValue = 0;        
int buzzer =13;
int cont =0;
int crap =0;
SoftwareSerial mySerial(5, 6);
char pass[]="This";
SoftwareSerial BT(10,11);
int i,y,t,n,c,m,q,p,aa,bb,cc=0;
int ii =0;
float a,b,f,k;
void setup() {
   crap=0;
   BT.begin(9600);
  Serial.begin(9600);
  mySerial.begin(9600); 
  pinMode(10, INPUT); 
  pinMode(11, INPUT); 
  pinMode(buzzer,OUTPUT);
  digitalWrite(buzzer,LOW);
  }
void loop() {
  if (crap==0) 
    checkAL();
    Serial.println("Serial");
    if(cont==0)
  {  
  if(ii==0)
  {
  //a=millis()/1000;
       if(millis()/1000.0>5)
  {
    
  int x=0;
  
  
   if((digitalRead(8) == 1)||(digitalRead(7) == 1)){
    Serial.println('!');
  }
  
   else{
    
    // send the value of analog input 0:
      x= analogRead(A0);
    Serial.print(x);
    // long unsigned int a=millis();
    // long unsigned int b=millis();
  Serial.print("\t");
     t=x-y;
  //Serial.print(t);
  Serial.print("mnjudgd\t");
  Serial.print(t-n);
  Serial.println("\t");
  if ((n-t)>150)
  {
    c++;
    Serial.println(a);
    if((c-1)%10 == 0 )
    {
      a=millis()/1000.0;
      Serial.println("BEGIN");
     }
    if (c%10==0)
    {k=(600.0/((millis()/1000.0)-a));
    
    Serial.println(k);
    delay(1000);x= analogRead(A0);
    Serial.print(x);
    // long unsigned int a=millis();
    // long unsigned int b=millis();
  Serial.print("\t");
     t=x-y;
  Serial.print(t);
  Serial.print("\t");
  Serial.print(t-n);
  Serial.println("\t");
  if ((n-t)>150)
  {
    c++;
    Serial.println(a);
    if((c-1)%10 == 0 )
    {
      a=millis()/1000.0;
      Serial.println("BEGIN");
     }
    if (c%10==0)
    {k=(600.0/((millis()/1000.0)-a));
    
    Serial.println(k);
    delay(1000);
    if (k<=65)
    {
     Serial.println("Wake up");
      WakeUpB();
      ii=1;}
      
  }
  else
  {
    Serial.print("\t");
    Serial.println(a);
  }
  
     n=t;
     y=x;
   }
  }}}
  Serial.println("You're not drunk\n \t Door opened");
  while(1)
  {
    ;
  }
  }
  else
  {
    Serial.println("You're too drunk to drive \n \t Door closed"); 
    
  }
}
  }}
 void sendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919952845775\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("You're Friend is drunk");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
void WakeUpB()
{
  int con=0;
  char guess[30];
  digitalWrite(buzzer,HIGH);
  BT.println("STOP, ENTER PASS");
  while(con==0)
  {
    
    delay(1000);
    if(BT.available())
    {
      //BT.println("b");
      delay(1000);
       readSerial(guess);
            
      if(strcmp(guess,pass)==0)
      {
        con=1;
        BT.println("Ok, You're awake");
        digitalWrite(buzzer,LOW);
        delay(1000);
      }
      else
      {
        BT.println("Try Again");
      }
    }
  }
}

int readSerial(char result[]) {
  int i = 0;
  while (1) {
   // BT.println("g");
    delay(100);
    BT.println(result);
    while (BT.available() > 0) {
      char inChar = BT.read();
      if (inChar == '\n') {
        result[i] = '\0';
        BT.flush();
        return 0;
      }
      if (inChar != '\r') {
        result[i] = inChar;
        i++;
      }
    }
  }
}

int checkAL()
{
  
  
  
  while(!(Serial.available()))
  {
    ;
  }
  Serial.println("Blow");
  
 
  
  for(i=0;i<10;i++)
  {
    int alch1=analogRead(Alch);
    if(alch1>500)
  {
      
      sendMessage();
      crap=1;
      return 0;
      
  }
  delay(1000);
}
}

/*void axcell()
{
for (int i =0;i<100;i++)  
{
  aa= (analogRead(xpin));
  bb=(analogRead(ypin));
 cc=(analogRead(zpin));
 
 if((aa-m>)7||(bb-q)>7||(cc-p)>7)
 {
     //return 1;
 }
 else if(i==99)
     //return 0;
  m=aa;
 q=bb;
 p=cc; 
}}*/
