//Hieu dien the                                                      chan A1
//Dong dien                                                          chan A0
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
int rpm = 0; 
int timecho = 15000;// laays 1 vongf ddem laf 15 giay
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
   currentTime = millis();
  
   if(currentTime >= (cloopTime + 15000))
   {
        cloopTime = currentTime; 
      l_hour = (flow_frequency * 60 / 7.5/15); 
      flow_frequency = 0; 
       L=(l_hour);
       if( L <0);
       L = L  *(-1);
      Serial.print(l_hour, DEC); 
      Serial.println(" L/hour");
      
   }
}
  {
   thoigian = millis();
  
  if (thoigian - hientai >= timecho)
  {
    hientai = thoigian;
    rpm = (dem/1)*60/150; 
        /*
         * Đĩa encoder có 20 xung, chúng ta đo được 120 xung/s
         * vậy lấy 120/20 = 6 vòng/s
         * ta được: 6*60 = số vòng quay / phút (RPM)
         * chia 15 vif chu kyf ddem 1 laanf 30 giay
         */
          V=(rpm);
    Serial.print("\t\t\t\t"); Serial.print("Số xung/s: "); Serial.println(dem);
    Serial.print("\t\t\t\t"); Serial.print("RPM: "); Serial.println(rpm);
      
       dem = 0; 
  }
  }
  {
 float average = 0;
 for(int i = 0; i < 1000; i++) {
     bawn = average =  average + (.0264 * analogRead(A0) -13.453);
   delay(1);
 }
    I=(average); 
    
    if( (average) < 0);
   {
average = average *(-1);  
    }
    delay(1);
 Serial.print("APE :");
 
 Serial.println(average/1000);
 lcd1.setCursor(0,0);
 lcd1.print("I= ");

     lcd1.setCursor(4,0);
     lcd1.print((average/1000 - 0.04 + 0.01 ) );
    
      lcd1.print(" A");
     
     average = 0;
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
  

 
