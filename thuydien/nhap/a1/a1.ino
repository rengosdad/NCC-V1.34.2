//////////////////////////////////////////////////////////////////////////////////////////////
#include <SoftwareSerial.h>
SoftwareSerial bt(12,13);
/////////////////đo dòng điện và đo vol///////////////////////////
// Define analog input
#define ANALOG_IN_PIN A0 //đo dòng điện
 #define ANALOG_IN_PIN A1 //đo vol
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

/*
* ////////////////////////////////đo áp xuất///////////////////////////////
 *
 * HX711 library for Arduino - example file
 * https://github.com/bogde/HX711
 *
 * MIT License
 * (c) 2018 Bogdan Necula
 *
**/
#include "HX711.h"


// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 4;
const int LOADCELL_SCK_PIN = 3;


HX711 scale;
/////////////////////////////////////////////////////////////////////////////////////////
  #include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); //LCD 16x02, địa chỉ I2C là 0X27
//////////////////////////////đo tốc độ vòng quay/////////////////////////////////////
int encoder_pin = 5;  // The pin the encoder is connected           
unsigned int rpm;     // rpm reading
volatile byte pulses;  // number of pulses
unsigned long timeold; 
// The number of pulses per revolution
// depends on your index disc!!
unsigned int pulsesperturn = 1;//so xung dia encode

 void counter()
 {
    //Update count
      pulses++;    
 }
 ////////////////////////////////đo lưu lượng////////////////////////////////
 /*YF- S201 water Flow sensor code for Arduino */

volatile int flow_frequency; // Đo xung cảm biến lưu lượng
unsigned int l_hour; // Tính toán số lít/giờ
unsigned char flowsensor = 2; // Cảm biến nối với chân 2
unsigned long currentTime;
unsigned long cloopTime;
void flow () // Hàm ngắt
{
   flow_frequency++;
}
void setup() {
  {
   pinMode(flowsensor, INPUT);
   digitalWrite(flowsensor, HIGH); // Optional Internal Pull-Up
   Serial.begin(9600);
   attachInterrupt(0, flow, RISING); // Setup Interrupt
   sei(); // Enable interrupts
   currentTime = millis();
   cloopTime = currentTime;
}
  Serial.begin(9600);
  
   bt.begin(9600); 
 bt.println("Ready");
  ////////////////////////////////áp xuất/////////////////////////////////
 
scale.begin(2, 3);//áp xuất
scale.set_scale(2280.f);                      // this value is obtained by calibrating the scale with known weights; see the README for details
 scale.tare();                // reset the scale to 0
////////////////////////////tốc độ////////////////////////////////////

 pinMode(4, INPUT);
   
   //Interrupt 0 is digital pin 2, so that is where the IR detector is connected
   //Triggers on FALLING (change from HIGH to LOW)
   attachInterrupt(0, counter, FALLING);
   // Initialize
   pulses = 0;
   rpm = 0;
   timeold = 0;


/////////////////////////////lưu lượng//////////////////////////////////////
  
}

  
void loop() {
 
 //////////////////////////////////đo dòng////////////////////////////////////
 float average = 0;
 for(int i = 0; i < 1000; i++) {
     average = average + (.0264 * analogRead(A0) -13.51);//for the 5A mode,  
//   average = average + (.049 * analogRead(A0) -25);// for 20A mode
// average = average + (.742 * analogRead(A0) -37.8);// for 30A mode
   delay(500);
 }
 Serial.print("Current :");
 Serial.print(average/1000);
 Serial.println(" A");
 ////////////////////////////////đo vol/////////////////////////////////
 // Read the Analog Input
  adc_value = analogRead(A1);
  
  // Determine voltage at ADC input
  adc_voltage  = (adc_value * ref_voltage) / 1024.0;
  
  // Calculate voltage at divider input
  in_voltage = adc_voltage*(R1+R2)/R2;
  
  // Print results to Serial Monitor to 2 decimal places
  Serial.print("Input Voltage = ");
  Serial.print(in_voltage, 2);
  Serial.println(" V");
  
  // Short delay
  delay(500);
//////////////////////////////////////đo áp////////////////////////////////////
  Serial.print("one reading:\t");
  Serial.print(scale.get_units(), 1);
  Serial.print("\t| average:\t");
  
  Serial.println(scale.get_units(10), 1);

  scale.power_down();              // put the ADC in sleep mode
  delay(5000);
  scale.power_up();
//////////////////////////////////đo tốc độ/////////////////////////////////////////
if (millis() - timeold >= 1000){  /*Uptade every one second, this will be equal to reading frecuency (Hz).*/
 
  //Don't process interrupts during calculations
   detachInterrupt(0);
   //Note that this would be 60*1000/(millis() - timeold)*pulses if the interrupt
   //happened once per revolution
   rpm = (60 * 1000 / pulsesperturn )/ (millis() - timeold)* pulses;
   timeold = millis();
   pulses = 0;
   
   //Write it out to serial port
   Serial.print("RPM = ");
   Serial.println(rpm,DEC);
   //Restart the interrupt processing
   attachInterrupt(0, counter, FALLING);
   }
///////////////////////////////////////đo lưu lượng/////////////////////////////////
{
   currentTime = millis();
   // Every second, calculate and print litres/hour
   if(currentTime >= (cloopTime + 1000))
   {
        cloopTime = currentTime; // Updates cloopTime
      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
      l_hour = (flow_frequency * 60 / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
      flow_frequency = 0; // Reset Counter
      Serial.print(l_hour, DEC); // Print litres/hour
      Serial.println(" L/hour");
        lcd.setCursor(0,0);
       lcd.print("LUU LUON :");
      //lcd.setCursor(11,1);
      lcd.print(l_hour);
   }
}

    
 
 
 bt.print(l_hour);//lưu lượng send distance to MIT App
 bt.print(";");
 bt.print(scale.get_units(10)); //áp xuất send distance to MIT App 
 bt.print(";");
 bt.print(rpm);//tốc độ tuabin send distance to MIT App 
 bt.print(";");
bt.print(in_voltage);//hiệu dien the tuabin send distance to MIT App 
 bt.print(";");
bt.print(average/1000);//dong dien tuabin send distance to MIT App 
 bt.print(";");
}
