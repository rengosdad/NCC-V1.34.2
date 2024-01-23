#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,6,5,4,3);
float value=0;
float rev=0;
int rpm;
int oldtime=0;
int time;
int sec;
//sensor chan 2
void isr() //interrupt service routine
{
rev++;
}

void setup()
{
lcd.begin(16,2);                //initialize LCD
attachInterrupt(0,isr,RISING);  //attaching the interrupt
 Serial.begin(9600);
  
 }

void loop()
{
delay(1000);
detachInterrupt(0);           //detaches the interrupt
time=millis()-oldtime;        //finds the time 
rpm=(rev/time)*60000;         //calculates rpm
oldtime=millis();             //saves the current time
rev=0;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("  RPM  COUNTER  ");

lcd.setCursor(0,1);
lcd.print(     rpm);
Serial.println(rpm);
Serial.print("   RPM   ");
lcd.print(" RPM");

lcd.print(" ");
sec=rpm/60;
lcd.print(   sec);
//Serial.print(rpm/60);
//Serial.print("   sec  ");
lcd.print("/s");

attachInterrupt(0,isr,RISING);
 


}

 
