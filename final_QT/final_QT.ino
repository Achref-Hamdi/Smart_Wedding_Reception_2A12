//arduinoo
#include <LiquidCrystal.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 8, en = 9, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#include<Servo.h>

Servo servo ; 
int buttonCounter=3;
int analogEntry = 0;
char data;
char data1;
int analogEntry2 = 1;
 int barriereUp =  0 ; 
 int in=0 ;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600) ; 
lcd.begin(16, 2); 
 // Print a message to the LCD.
  //lcd.print("hello, world!");
servo.attach(6);
for(int angle = 0; angle < 105; angle += 1)    // command to move from 0 degrees to 180 degrees 
  {                                  
   servo.write(angle);                 //command to rotate the servo to the specified angle
    delay(15);                       
  } 
 
  delay(1000);

//pinMode(ldrPin,INPUT); 
}

void loop() {
  
  // put your main code here, to run repeatedly:
  
//Serial.println(analogRead(analogEntry)) ;
 
//Serial.println(analogRead(analogEntry2)) ;
 
// Serial.println(buttonCounter);
 lcd.setCursor(0, 0);
    lcd.println("Free spaces:        ");          
    lcd.setCursor(7, 1);
    lcd.print(buttonCounter);
    lcd.println("        ");

/*if( (analogRead(analogEntry)< 100 || analogRead(analogEntry2)<300) &&( in==0))
{ 
  in=1 ;
  if(barriereUp==0  )
  {
    if (analogRead(analogEntry)< 100 )
{
  buttonCounter-- ; 
  Serial.println("dagdeg");
  }

  if ( analogRead(analogEntry2)<300 )
{
  buttonCounter++;
    Serial.println("moetazzz");
}
    servo.write(0);//tetlaa
    barriereUp=1; }
   else 
    {servo.write(90);//tahbet 
    barriereUp=0;
      }
  }
  */
  if( analogRead(analogEntry)< 650 && in==0 && buttonCounter>0)
  { in =1 ;
    if(barriereUp==0  )
    { servo.write(0);
    barriereUp=1;
    buttonCounter--;
    Serial.write('o');
   }
   else {servo.write(105);
   barriereUp=0;
    Serial.write('c');}
  }
   if( analogRead(analogEntry2)< 600 && in==0 && buttonCounter<=2 )
  { in =1 ;
    if(barriereUp==0  )
    { servo.write(0);
    barriereUp=1;
    buttonCounter++;
     Serial.write('o');
  
   }
   else {servo.write(105);
   barriereUp=0;
    Serial.write('c');}
  }
  
 if ( analogRead(analogEntry)> 650 && analogRead(analogEntry2)> 600)
  {in=0;} 

if(Serial.available()){
  data=Serial.read();
  if(data=='o')
  {
    servo.write(0);

    }
    else if (data=='c')
    {servo.write(105);
      }
      else if (data=='-')
      {buttonCounter--;
        }
        else if (data=='+')
      {buttonCounter++;
        }
        
       
  }
 
  
   
}
