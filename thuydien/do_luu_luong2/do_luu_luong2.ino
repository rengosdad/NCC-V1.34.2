int Output_Pin = 5;

volatile int  Pulse_Count;
unsigned int  Liter_per_hour;
unsigned long Current_Time, Loop_Time;
void flow () // Hàm ngắt
{
   Pulse_Count++;
}
void setup()
{ 
   pinMode(5, INPUT);
   Serial.begin(9600); 
   //attachInterrupt(0, Detect_Rising_Edge, FALLING);
                                     
   Current_Time = millis();
   Loop_Time = Current_Time;
   //lcd.begin(16, 2);
   //lcd.clear();
  //lcd.setCursor(0,0);
   //lcd.print("Water Flow Meter");
   //lcd.setCursor(0,1);
   //lcd.print("ArduinoKIT");
} 

void loop ()    
{
   Current_Time = millis();
   if(Current_Time >= (Loop_Time + 1000))
   {
      Loop_Time = Current_Time;
      Liter_per_hour = (Pulse_Count * 60 / 7.5);
      //Pulse_Count=0
      //if(Pulse_Count != 0){
     //lcd.clear();
     // lcd.setCursor(0,0);
      //lcd.print("Rate: ");
      //lcd.print(Liter_per_hour);
     // lcd.print(" L/M");
      //Pulse_Count = 0;
      Serial.print(Liter_per_hour, DEC);
      Serial.println(" Liter/hour");
       }
    //else {
      //Serial.println(" flow rate = 10 ");
     // lcd.clear();
   //lcd.setCursor(0,0);
    // lcd.print("Rate: ");
    //lcd.print( Liter_per_hour );
  //lcd.print(" L/M");
    }
   }
   
}
void Detect_Rising_Edge ()
{ 
   Pulse_Count++;
} 
