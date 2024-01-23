//Cam bien chan 2
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
#include "HX711.h"


// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 4;
const int LOADCELL_SCK_PIN = 5;
HX711 scale;
void setup()
 {

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
  Serial.println("HX711 Demo");

  Serial.println("Initializing the scale");

  // Initialize library with data output pin, clock input pin and gain factor.
  // Channel selection is made by passing the appropriate gain:
  // - With a gain factor of 64 or 128, channel A is selected
  // - With a gain factor of 32, channel B is selected
  // By omitting the gain factor parameter, the library
  // default "128" (Channel A) is used here.
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  scale.set_scale(2280.f);                      // 2280this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();                // reset the scale to 0
}
  {
  Serial.begin(9600); //Mở cổng Serial ở 9600
  lcd.init(); //Khởi động LCD
  lcd.backlight(); //Bật đèn nền
  lcd.setCursor(1,0); //Cột 1, hàng 0
   lcd1.init(); //Khởi động LCD
  lcd1.backlight(); //Bật đèn nền
  lcd1.setCursor(1,0); //Cột 1, hàng 0
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
  {
 
   Serial.begin(9600);
  
  pinMode(enco, INPUT);
  attachInterrupt(1, dem_xung, RISING);
  {
  Serial.begin(9600); //Mở cổng Serial ở 9600
  lcd.init(); //Khởi động LCD
  lcd.backlight(); //Bật đèn nền
  lcd.setCursor(1,0); //Cột 1, hàng 0
  }
  }
 }

 void loop()
 {
  {
  Serial.print("one reading:\t");
  Serial.print(scale.get_units(), 1);
  Serial.print("\t| average:\t");
  Serial.println(scale.get_units(10), 1);
  lcd.setCursor(0,1);
  lcd.print("Pr= ");
  lcd.setCursor(4,1);

  lcd.print(scale.get_units(5), 1);
  
  lcd.print(" kPa");
    Pr=(scale.get_units(5), 1);
  
  scale.power_down();              // put the ADC in sleep mode
  delay(500);
  scale.power_up();
}
  {
   currentTime = millis();
   // Every second, calculate and print litres/hour
   if(currentTime >= (cloopTime + 15000))
   {
        cloopTime = currentTime; // Updates cloopTime
      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
      l_hour = (flow_frequency * 60 / 7.5/15); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
      flow_frequency = 0; // Reset Counter
      Serial.print(l_hour, DEC); // Print litres/hour
      Serial.println(" L/hour");
        lcd.setCursor(1,0);
       lcd.print("L= ");
      //lcd.setCursor(11,1);
      
      lcd.print(l_hour);
     
      lcd.print(" l/h");
       L=(l_hour);
   }
}
  {
   thoigian = millis();
//  Serial.print("Time: "); Serial.print(thoigian); Serial.print("   ");
//  Serial.print("Hiện tại: "); Serial.println(hientai);
  
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
    Serial.print("\t\t\t\t"); Serial.print("Số xung/s: "); Serial.println(dem);
    Serial.print("\t\t\t\t"); Serial.print("RPM: "); Serial.println(rpm);
     lcd.setCursor(9,1);
     lcd.print("V=");
     lcd.setCursor(12,1);
     lcd.print(rpm);
      lcd.print(" v/p");
       V=(rpm);
       dem = 0; 
  }
  }
  {
 float average = 0;
 for(int i = 0; i < 1000; i++) {
     bawn = average =  average + (.0264 * analogRead(A0) -13.465);//for the 5A mode, 13.51 
//   average = average + (.049 * analogRead(A0) -25);// for 20A mode
// average = average + (.742 * analogRead(A0) -37.8);// for 30A mode
   delay(1);
 }
 Serial.print("APE :");
 Serial.println(average/1000);
 lcd1.setCursor(0,0);
 lcd1.print("I= ");

     lcd1.setCursor(4,0);
     lcd1.print((average/1000 ) );//
    
      lcd1.print(" A");
        I=(average);   //mA
     
}
  {
  // Read the Analog Input
  adc_value = analogRead(A1);
  
  // Determine voltage at ADC input
  adc_voltage  = (adc_value * ref_voltage) / 1024.0;
  
  // Calculate voltage at divider input
  in_voltage = adc_voltage*(R1+R2)/R2;
  
  // Print results to Serial Monitor to 2 decimal places
  Serial.print("Voltage = ");
  Serial.println(in_voltage, 2);
  lcd1.setCursor(0,1);
  lcd1.print("U= ");
  
     lcd1.setCursor(4,1);
     lcd1.print(in_voltage, 2);
    
      lcd1.print(" V");
       U=((in_voltage)*1000);//mV
     delay(500);
     
}


bt.print(L);//lưu lượng send distance to MIT App
 bt.print(";");
  bt.print(Pr); //áp xuất send distance to MIT App 
 bt.print(";");
 bt.print(V);//toc do send distance to MIT App
 bt.print(";");
 bt.print(U);//dien thetuabin send distance to MIT App 
 bt.print(";");
 bt.print(I);//dong dien tuabin send distance to MIT App 
 bt.print(";");
 //bt.print(in_voltage, 2);//hiệu dien the tuabin send distance to MIT App 
 //bt.print(";");


  }
  

 
