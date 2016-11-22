import processing.serial.*;

Serial myPort;        
int xPos = 1;        
float height_old = 0;
float height_new = 0;
float inByte = 0;
int y , t ,n= 0;
float tmr , tmr1 = 0;
int count = 0 ;
float fr;
void setup () {
  size(400,300);
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[0], 9600);
  myPort.bufferUntil('\n');
  background(0xff);
}


void draw () {
  tmr=float(millis())/1000.0;
  
  int t = 0 ;
  int j = 0;
  String inString = myPort.readStringUntil('\n');
  if (inString != null) {
     trim off any whitespace:
      inString = trim(inString);
      stroke(0xff, 0, 0); 
       t=int(inString)-y;
      println(t-n);
     n=t;
     y=int(inString);
     j=-t-n;
   if(tmr>6)
     {
       if((j>50 || -j >  70)&& (tmr-tmr1 >1.2))
       {
         fr=(1.0/(tmr-tmr1))*60.0;
         count++;
         println("PULSE DETECTED " + j + " " + count + " " + (tmr-tmr1) + " " + fr );
         tmr1=tmr;
       }
     }
     else
     {
       background(0);
     }
      inByte = float(inString);
      inByte = map(inByte, 0, 1023, 0, height);
     height_new = height - inByte; 
     line(xPos - 1, height_old, xPos, height_new);
     height_old = height_new;
     if (xPos >= width) {
        xPos = 0;
        background(0xff);
      } 
      else {
        xPos++;
      }}
     
}