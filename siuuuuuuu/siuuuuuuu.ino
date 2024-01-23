#include <LiquidCrystal_I2C.h>
#include "HX711.h"
#include <SoftwareSerial.h>
//unsigned long currentTime;
//unsigned long cloopTime;
unsigned long thoigian;
unsigned long hientai;
LiquidCrystal_I2C lcd(0x27,16,2); //Khai báo địa chỉ I2C (0x27 or 0x3F) và LCD 16x02
LiquidCrystal_I2C lcd1(0x26,16,2); //LCD 16x02, địa chỉ I2C là 0X27

SoftwareSerial bt(12,13);
///////////////////////////////////////////////////////////////////////////////////
//volatile int flow_frequency; // Đo xung cảm biến lưu lượng
//unsigned int l_hour; // Tính toán số lít/giờ
// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 4;
const int LOADCELL_SCK_PIN = 3;
//unsigned char flowsensor = 5;// Cảm biến nối với chân 5
HX711 scale;
#define ANALOG_IN_PIN A1
int enco = 2;
int dem = 0;
int rpm = 0; 
int timecho = 15000;//Hai
int kobt = 0;
// Define analog input
// Floats for ADC voltage & Input voltage
float adc_voltage = 0.0;
float in_voltage = 0.0;
 
// Floats for resistor values in divider (in ohms)
float R1 = 30000.0;
float R2 = 7500.0; 
 
// Float for Reference Voltage
float ref_voltage = 5.0;
 
// Integer for ADC value
int adc_value = 0;
//void flow () // Hàm ngắt
//{
 //  flow_frequency++;
//}
void dem_xung()
{
  dem++; //đếm xung
}
unsigned long tiempo_1 = 0;
unsigned long tiempo_2 = 0;
void print_tiempo(unsigned long tiempo_millis);
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
   Serial.begin(9600);
  
  pinMode(enco, INPUT);
  attachInterrupt(0, dem_xung, RISING);

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

 // Serial.println("Before setting up the scale:");
 // Serial.print("read: \t\t");
  //Serial.println(scale.read());      // print a raw reading from the ADC

 // Serial.print("read average: \t\t");
 // Serial.println(scale.read_average(20));   // print the average of 20 readings from the ADC

  //Serial.print("get value: \t\t");
  //Serial.println(scale.get_value(5));   // print the average of 5 readings from the ADC minus the tare weight (not set yet)

  //Serial.print("get units: \t\t");
 // Serial.println(scale.get_units(5), 1);  // print the average of 5 readings from the ADC minus tare weight (not set) divided
            // by the SCALE parameter (not set yet)

  scale.set_scale(2280.f);                      // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();               // reset the scale to 0

  //Serial.println("After setting up the scale:");

  //Serial.print("read: \t\t");
  //Serial.println(scale.read());                 // print a raw reading from the ADC

 // Serial.print("read average: \t\t");
 // Serial.println(scale.read_average(20));       // print the average of 20 readings from the ADC

  //Serial.print("get value: \t\t");
 // Serial.println(scale.get_value(5));   // print the average of 5 readings from the ADC minus the tare weight, set with tare()

 // Serial.print("get units: \t\t");
 // Serial.println(scale.get_units(5), 1);        // print the average of 5 readings from the ADC minus tare weight, divided
            // by the SCALE parameter set with set_scale

 // Serial.println("Readings:");
}

  {
  Serial.begin(9600); //Mở cổng Serial ở 9600
//Khởi động LCD
  lcd1.init(); //Khởi tạo màn hình LCD
  lcd1.backlight(); //Bật đèn màn hình lCD
  
  lcd.init(); //Khởi tạo màn hình LCD
  lcd.backlight(); //Bật đèn màn hình lCD
  }
  //{
   //pinMode(flowsensor, INPUT);
   //digitalWrite(flowsensor, HIGH); // Optional Internal Pull-Up
   //Serial.begin(9600);
   //attachInterrupt(0, flow, RISING); // Setup Interrupt
   //sei(); // Enable interrupts
   //currentTime = millis();
   //cloopTime = currentTime;
//}
}
void loop ()
{
  {
  Serial.print("one reading:\t");
  Serial.print(scale.get_units(), 1);
  Serial.print("\t| average:\t");
  Serial.println(scale.get_units(5), 1);
  lcd.setCursor(0,1);
  lcd.print("A.X:");
  lcd.setCursor(4,1);
  lcd.print(scale.get_units(5), 1);

  scale.power_down();              // put the ADC in sleep mode
  delay(1000);
  scale.power_up();
}
  
//{
   currentTime = millis();
   Every second, calculate and print litres/hour
   if(currentTime >= (cloopTime + 15000))//hai
   {
        cloopTime = currentTime; // Updates cloopTime
//      Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
      l_hour -= (flow_frequency * 60 / 7.5/15); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
      flow_frequency = 0; // Reset Counter
      Serial.print(l_hour, DEC); // Print litres/hour
      Serial.println(" L/hour");
        lcd.setCursor(0,0);
       lcd.print("LUU LUONG: ");
      lcd.print(l_hour);
     
  }
//}
{
    thoigian = millis();
//  Serial.print("Time: "); Serial.print(thoigian); Serial.print("   ");
//  Serial.print("Hiện tại: "); Serial.println(hientai);
  
  if (thoigian - hientai >= timecho)  //
  {
    hientai = thoigian;
    rpm = (dem/1)*60/15; //hai
        /*
         * Đĩa encoder có 20 xung, chúng ta đo được 120 xung/s
         * vậy lấy 120/20 = 6 vòng/s
         * ta được: 6*60 = số vòng quay / phút (RPM)
         */
   // Serial.print("\t\t\t\t");
   // Serial.print("Số xung/s: ");
    //Serial.println(dem);  
    dem = 0; 
   // Serial.print("\t\t\t\t");
    Serial.print("RPM: ");
    Serial.println(rpm);
     lcd.setCursor(9,1);
     lcd.print("T.D:");
     lcd.setCursor(13,1);
     lcd.print(rpm);
  }
  }
 {
  {
 float average = 0;
 for(int i = 0; i < 1000; i++) {
     average = average + (.0264 * analogRead(A0) -13.51);//for the 5A mode,  
//   average = average + (.049 * analogRead(A0) -25);// for 20A mode
// average = average + (.742 * analogRead(A0) -37.8);// for 30A mode
   delay(1);
 }
 Serial.print("APE :");
 Serial.println(average/1000 + 0.07);
 lcd1.setCursor(0,0);
     lcd1.print("A:");
     lcd1.setCursor(4,0);
     lcd1.print(average/1000 + 0.07);
     kobt == average/1000 + 0.07;
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
     lcd1.print("V:");
     lcd1.setCursor(4,1);
     lcd1.print(in_voltage, 2);
  
  // Short delay
 // delay(500);
}
}

bt.print("l");//lưu lượng send distance to MIT App
 bt.print(";");
 Serial.print("HAI: ");
 Serial.println(rpm);
 bt.print("2"); //áp xuất send distance to MIT App 
 bt.print(";");
 bt.print("4");//tốc độ tuabin send distance to MIT App 
 bt.print(";");
bt.print("3");//hiệu dien the tuabin send distance to MIT App 
 bt.print(";");
bt.print("5");//dong dien tuabin send distance to MIT App 
 bt.print(";");
 
}
