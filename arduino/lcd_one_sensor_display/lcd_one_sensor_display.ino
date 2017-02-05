
#include <LiquidCrystal.h>

//Initialize LCD 
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

int sensor1Pin = A0;
int sensor2Pin = A1;
int sensor3Pin = A2;

int sensor1Val = 0;
int sensor2Val = 0;
int sensor3Val = 0;

// to filter
int windowSize = 5;
int delay_rate = 10; //ms
int sensor1Filt[5];
int sensCount  = 0;

// for bpm
int bpm_count  = 0;
int bpm_tick   = 0;
int bpm_window = 1000/delay_rate; 
int bpm = 0;


void setup() {
  // put your setup code here, to run once:
  // initialize serial communications at 9600 bps:
//  Serial.begin(9600);
  
  //Set LCD Display Size
  lcd.begin(16,2);
  lcd.clear();

  for(int i=0; i<windowSize; i++){
    sensor1Filt[i] = 0;
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  // read the value from the sensor:
  sensor1Val = analogRead(sensor1Pin);
  sensor2Val = analogRead(sensor2Pin);
  sensor3Val = analogRead(sensor3Pin);

  if(sensCount < windowSize){
    sensor1Filt[sensCount] = sensor1Val;
    sensCount += 1;
  }else{
    sensCount = 0;
    int avg = 0;
    for(int i=0; i<windowSize; i++){
      avg += sensor1Filt[i];
    }
    avg /= windowSize;
    lcd.setCursor(2,0);
  //  lcd.print(String(sensor1Val));
//    lcd.print(String(sensor1Filt[0]));
//    lcd.print(" ");
//    lcd.print(String(sensor1Filt[1]));
//    lcd.print(" ");
//    lcd.print(String(sensor1Filt[2]));
//    lcd.print(" ");

    
    lcd.setCursor(0,1);
    lcd.print("avg1 = ");
    lcd.print(String(avg));

    if (avg>900){
      bpm_tick += 1;
    }
  }

  bpm_count += 1;

  if (bpm_count>bpm_window){
    bpm       = bpm_tick*60;
    bpm_tick  = 0;
    bpm_count = 0;
  }

  // print the results to lcd
  delay(delay_rate); 
  lcd.setCursor(0,0);
  lcd.print("BPM:");
  lcd.print(String(bpm));
  lcd.print(" ");

}

