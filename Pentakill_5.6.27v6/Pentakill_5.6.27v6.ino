//Hieu dien the                                                      chan A1
//Dong dien                                                          chan A5
//Mang hinh , ap xuat BMP 180                                        chan I2C SDA, SCL
//Luu luong (attachInterrupt(0, flow, RISING); // Setup Interrupt )  chan 2
//toc do vong quay   (attachInterrupt(1, dem_xung, RISING); )        chan 3  
// Blutooch Tx,Rx                                                    chan 12,13        



 #include <LiquidCrystal_I2C.h>
 #include <SoftwareSerial.h>
 SoftwareSerial bt(12,13);
 LiquidCrystal_I2C lcd(0x27,16,2); //LCD 16x02, địa chỉ I2C là 0X27
 LiquidCrystal_I2C lcd1(0x26,16,2);
 #define ANALOG_IN_PIN A1
 #define ANALOG_IN_PIN A5
 float adc_voltage = 0.0;
float in_voltage = 0.0;
int bawn ;
// Floats for resistor values in divider (in ohms)
float R1 = 30000.0;
float R2 = 7500.0; 
 
// Float for Reference Voltage
float ref_voltage = 5.0;
// Integer for ADC value
int adc_value = 0;
int enco = 3;//toc do vong quay chan 3
int dem = 0;
int nhip =0;
int rpm = 0; 
int timecho = 10000;// laays 1 vongf ddem laf 30 giay
int L = 0;
int Pr = 0;
int V = 0;
int I = 0;
int U = 0;
int Pn = 0;
int H = 0;
int led = 6;
unsigned long thoigian;
unsigned long hientai;

void dem_xung()
{
  dem++; //đếm xung
}
volatile int flow_frequency; // Đo xung cảm biến lưu lượng
unsigned int l_hour; // Tính toán số lít/giờ
unsigned char flowsensor = 2; // Cảm biến nối với chân 5
unsigned long currentTime;
unsigned long cloopTime;
void flow () // Hàm ngắt
{
   flow_frequency++;
}
#include <SFE_BMP180.h>
#include <Wire.h>
#include <I2Cdev.h>


SFE_BMP180 pressure;

#define ALTITUDE  0 

void setup()
 {
  {
    pinMode(led, OUTPUT);  
  }

  {
    Serial.begin(9600);
  
   bt.begin(9600); 
 bt.println("Ready");
  }
  {
  Serial.begin(9600);
}
{
  
  // Setup Serial Monitor
  Serial.begin(9600);
  }
  {
  Serial.begin(9600); //Mở cổng Serial ở 9600
//Khởi động LCD
  lcd1.init(); //Khởi tạo màn hình LCD
  lcd1.backlight(); //Bật đèn màn hình lCD
  
  
  }
  {
    
 Serial.begin(9600);
  Serial.println("REBOOT");

  if (pressure.begin())
    Serial.println("BMP180 init success");
  else
  {

    Serial.println("BMP180 init fail\n\n");
    while(1); 
  } 
}
  {
  Serial.begin(9600); 
  lcd.init(); 
  lcd.backlight(); 
  //lcd.setCursor(1,0); 
   lcd1.init(); 
  lcd1.backlight(); 
  //lcd1.setCursor(1,0); 
  }
  {
   pinMode(flowsensor, INPUT);
   digitalWrite(flowsensor, HIGH); 
   Serial.begin(9600);
   attachInterrupt(0, flow, RISING); 
   sei(); 
   currentTime = millis();
   cloopTime = currentTime;
}
  {
 
   Serial.begin(9600);
  
  pinMode(enco, INPUT);
  attachInterrupt(1, dem_xung, RISING);
  {
  Serial.begin(9600); 
  }
  }
 }

 void loop()
 {
  {
  char status;
  double T,P,p0,a;

  status = pressure.startTemperature();
    delay(status);

    status = pressure.getTemperature(T);
      Serial.print("T= ");
      Serial.print(T,2);
      Serial.println(" deg C, ");

      status = pressure.startPressure(3);
        delay(status);
        status = pressure.getPressure(P,T);               
          Serial.print(" Pr= ");
          Serial.print(P/7-144.897,1);
          Serial.println(" kPa, ");
          Serial.print("H= ");
          Serial.print((P/7-144.897)*0.101974,2 );
          Serial.println(" mH2O, ");
          Pr=(P/7-144.897);
          H=((P/7-144.897)*0.101974 );

          p0 = pressure.sealevel(P,ALTITUDE); 

          a = pressure.altitude(P,p0);
         

  delay(5000);  
}
  {
   currentTime = millis ();
   
  
   if(currentTime >= (cloopTime + 10000))
   {
        cloopTime = currentTime; 
      l_hour = (flow_frequency * 60 / 7.5/10); 
      flow_frequency = 0;   
             
       delay(100);
       
       //if( L <0);
       //L = L  *(-1);
      Serial.print((l_hour), DEC); 
      Serial.println(" L/hour");
      L = abs((l_hour));
      
   }
}
  {
   thoigian = millis ();
   
  
  if (thoigian - hientai >= timecho)
  {
    hientai = thoigian;
    
    
   
    rpm = (dem/1)*60/100; 
        /*
         * ÄÄ©a encoder cÃ³ 20 xung, chÃºng ta Ä‘o Ä‘Æ°á»£c 120 xung/s
         * váº­y láº¥y 120/20 = 6 vÃ²ng/s
         * ta Ä‘Æ°á»£c: 6*60 = sá»‘ vÃ²ng quay / phÃºt (RPM)
         * chia 15 vif chu kyf ddem 1 laanf 30 giay
         */
         
    Serial.print("\t\t\t\t"); Serial.print("So xung/s: "); Serial.println(dem);
    Serial.print("\t\t\t\t"); Serial.print("RPM: "); Serial.println(rpm);
      
        

    delay(100); 
    dem = 0;
     V =  abs((rpm)); 
     hientai = thoigian;  
  }
  }
  {
 float average = 0;
 for(int i = 0; i < 1000; i++) {
       //average = average + (.0264 * analogRead(A0) -13.51);//for the 5A mode,  
//   average = average + (.049 * analogRead(A0) -25);// for 20A mode
// average = average + (.742 * analogRead(A0) -37.8);// for 30A mode
     bawn = average =  average +( (.0264 * analogRead(A5) ) - 13.453);
   delay(1);
 }
    //I=(average); 
   // if( (average) <0);
//average = average  *(-1); 
 //I=abs((average)); 
 
  if( (U) <20){
 
  (average)=0; 
  I = 0 ;} 
  else {I = abs((average));}
  
 Serial.print("APE :");
 Serial.println(average/1000);
 lcd1.setCursor(0,0);
 lcd1.print("I= ");

     lcd1.setCursor(4,0);
    lcd1.print(abs(average )/1000 );
    
      lcd1.print(" A");
     
     
}
  {
  
  adc_value = analogRead(A1);  
  adc_voltage  = (adc_value * ref_voltage) / 1024.0;
  in_voltage = adc_voltage*(R1+R2)/R2;
   U=((in_voltage)*1000);//mV
  Serial.print("Voltage = ");
  Serial.println(in_voltage, 2);
  lcd1.setCursor(0,1);
  lcd1.print("U= ");
  
     lcd1.setCursor(4,1);
     lcd1.print(in_voltage, 2);
    
      lcd1.print(" V");
      
     delay(500);
     
}

digitalWrite(led, HIGH);   
  delay(1500);               
  
lcd.setCursor(0,0);
lcd.print("                ");
lcd.setCursor(0,1);
lcd.print("                ");
  
lcd.setCursor(1,1);
  lcd.print("Pr= ");
  lcd.print(Pr);    
  lcd.print(" kPa");

  lcd.setCursor(1,0);
  lcd.print("H= ");
  lcd.setCursor(6,0);
  lcd.print(H);    
  lcd.print(" m");
   delay(5000);

lcd.setCursor(0,0);
lcd.print("                ");
lcd.setCursor(0,1);
lcd.print("                ");


  lcd.setCursor(1,0);
  lcd.print("V= ");
  lcd.print(V);
  lcd.print(" v/p");
  
lcd.setCursor(1,1);
 lcd.print("L= ");
  lcd.print(L);
  lcd.print(" l/h");
 
  

 

bt.print(L);//1  lưu lượng send distance to MIT App
 bt.print(";");
  bt.print(Pr); //2  áp xuất send distance to MIT App 
 bt.print(";");
 bt.print(V);//3  toc do send distance to MIT App
 bt.print(";");
 bt.print(U);//4  dien thetuabin send distance to MIT App 
 bt.print(";");
 bt.print(I);//5  dong dien tuabin send distance to MIT App 
 bt.print(";");
 bt.print(H);//6 do cao tuabin send distance to MIT App 
 bt.print(";");
 //bt.print(in_voltage, 2);//hiệu dien the tuabin send distance to MIT App 
 //bt.print(";");


  }
  

 
