// Define analog input
#define ANALOG_IN_PIN A1
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd1(0x26,16,2);
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
 
void setup(){
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
}
 
void loop(){
  {
 float average = 0;
 for(int i = 0; i < 1000; i++) {
     average = average + (.0264 * analogRead(A0) -13.51);//for the 5A mode,  
//   average = average + (.049 * analogRead(A0) -25);// for 20A mode
// average = average + (.742 * analogRead(A0) -37.8);// for 30A mode
   delay(1);
 }
 Serial.print("APE :");
 Serial.println(average/1000);
 lcd1.setCursor(0,0);
 lcd1.print("A:");
     lcd1.setCursor(4,0);
     lcd1.print(average/1000);
     
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
  lcd1.print("V: ");
     lcd1.setCursor(4,1);
     lcd1.print(in_voltage, 2);
     delay(500);
}
}
