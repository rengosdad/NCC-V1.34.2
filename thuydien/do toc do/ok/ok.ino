//Cam bien chan 2
 #include <LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcd(0x27,16,2); //LCD 16x02, địa chỉ I2C là 0X27
int enco = 3;
int dem = 0;
int rpm = 0; 
int timecho = 15000;// laays 1 vongf ddem laf 15 giay
unsigned long thoigian;
unsigned long hientai;

void dem_xung()
{
  dem++; //đếm xung
}


void setup()
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

 void loop()
 {
   thoigian = millis();
//  Serial.print("Time: "); Serial.print(thoigian); Serial.print("   ");
//  Serial.print("Hiện tại: "); Serial.println(hientai);
  
  if (thoigian - hientai >= timecho)
  {
    hientai = thoigian;
    rpm = (dem/1)*60/15; 
        /*
         * Đĩa encoder có 20 xung, chúng ta đo được 120 xung/s
         * vậy lấy 120/20 = 6 vòng/s
         * ta được: 6*60 = số vòng quay / phút (RPM)
         * chia 15 vif chu kyf ddem 1 laanf 30 giay
         */
    Serial.print("\t\t\t\t"); Serial.print("Số xung/s: "); Serial.println(dem);
    Serial.print("\t\t\t\t"); Serial.print("RPM: "); Serial.println(rpm);
     lcd.setCursor(8,1);
     lcd.print("T.T :");
     lcd.setCursor(12,1);
     lcd.print(rpm);
       dem = 0; 
  }
  }

 
