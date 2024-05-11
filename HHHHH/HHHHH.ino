//LOW = bật rơ lê đèn
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
#define RO1  4
#define RO2  5
#define RO3  6
#define RO4  7
int R1;
int R2;
int R3;
int R4;
int L ;
int i = 1 ;
//char array1[] = "      INOVATRIX";  
//char array2[] = "        LIKE";     
//char array3[] = "     SUBSCRIBE";   
//char array4[] = "       SHARE";

volatile int flow_frequency; 
unsigned int l_hour; 
unsigned char flowsensor = 2; 
unsigned long currentTime;
unsigned long cloopTime;
void flow () // Hàm ngắt
{
   flow_frequency++;
}     
void setup() {   
  {             
  pinMode(RO1, OUTPUT);    
    pinMode(RO2, OUTPUT);  
      pinMode(RO3, OUTPUT);  
        pinMode(RO4, OUTPUT);  
  }
  {
  {
  Serial.begin(9600); //Mở cổng Serial ở 9600
  lcd.init(); //Khởi động LCD
 lcd.backlight(); //Bật đèn nền
  //lcd.setCursor(1,0); //Cột 1, hàng 0
  }
  {
   pinMode(flowsensor, INPUT);
   digitalWrite(flowsensor, HIGH); // Optional Internal Pull-Up
   Serial.begin(9600);
   attachInterrupt(0, flow, RISING); // Setup Interrupt
   sei(); // Enable interrupts
   currentTime = millis();
   cloopTime = currentTime;
}
}
}
 
// Hàm loop chạy mãi mãi sau khi kết thúc hàm setup()
void loop() {
  {
   currentTime = millis();
   // Every second, calculate and print litres/hour
   if(currentTime >= (cloopTime + 15000))
   {
        cloopTime = currentTime; // Updates cloopTime
      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
      l_hour = (flow_frequency * 60 / 7.5/15); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
      flow_frequency = 0; // Reset Counter
      L = l_hour;
      Serial.print(l_hour, DEC); // Print litres/hour
      Serial.println(" L/hour");
//if ( L <= 0 );
 ////{
 // L = L * -1;
 //}
 Serial.println(L); // Print litres/hour
       // lcd.setCursor(1,0);
      // lcd.print("LUU LUONG :");
      //lcd.setCursor(11,1);
     // lcd.print(l_hour);
   }   
}
  {
    if ( L<100)
   { 
   digitalWrite(RO3, LOW);
   digitalWrite(RO1, HIGH);
   digitalWrite(RO2, HIGH);
   digitalWrite(RO4, LOW);
   
   lcd.setCursor(0,0);
   lcd.print("CONG1:") ;
   lcd.setCursor(7,0);
   lcd.print("OFF") ; 
   lcd.setCursor(0,1);
   lcd.print("CONG2:") ;
   lcd.setCursor(7,1);
   lcd.print("OFF");
   lcd.setCursor(0,2);
   lcd.print("DEN BAO1:"); 
   lcd.setCursor(10,2);
   lcd.print("OFF")  ;
   lcd.setCursor(0,3);
   lcd.print("DEN BAO2:");
   lcd.setCursor(10,3);
   lcd.print("OFF");
  }
  else if ( L<200 && L>100)
   {
    
   digitalWrite(RO3, LOW);
   digitalWrite(RO1, LOW);
   digitalWrite(RO2, HIGH);
   digitalWrite(RO4, HIGH);
   
   lcd.setCursor(0,0);
   lcd.print("CONG1:") ;
   lcd.setCursor(7,0);
   lcd.print("ONN") ; 
   lcd.setCursor(0,1);
   lcd.print("CONG2:") ;
   lcd.setCursor(7,1);
   lcd.print("OFF");
   lcd.setCursor(0,2);
   lcd.print("DEN BAO1:"); 
   lcd.setCursor(10,2);
   lcd.print("ONN")  ;
   lcd.setCursor(0,3);
   lcd.print("DEN BAO2:");
   lcd.setCursor(10,3);
   lcd.print("OFF");


  }
  
  
 else if ( L>200)
   {
   digitalWrite(RO3, LOW);
   digitalWrite(RO1, LOW);
   digitalWrite(RO2, LOW);
   digitalWrite(RO4, LOW);
   
   lcd.setCursor(0,0);
   lcd.print("CONG1:") ;
   lcd.setCursor(7,0);
   lcd.print("ONN") ; 
   lcd.setCursor(0,1);
   lcd.print("CONG2:") ;
   lcd.setCursor(7,1);
   lcd.print("ONN");
   lcd.setCursor(0,2);
   lcd.print("DEN BAO1:"); 
   lcd.setCursor(10,2);
   lcd.print("ONN")  ;
   lcd.setCursor(0,3);
   lcd.print("DEN BAO2:");
   lcd.setCursor(10,3);
   lcd.print("ONN");
  }
  }
  delay ( 5000);
}
