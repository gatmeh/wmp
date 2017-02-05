
int analogA0 = 0;
int analogA1 = 1;
int analogA2 = 2;

int sensor0 = 0;
int sensor1 = 0;
int sensor2 = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);          //  setup serial

}

void loop() {
  // put your main code here, to run repeatedly:

  sensor0 = analogRead(analogA0);    // read the input pin
  sensor1 = analogRead(analogA1); 
  sensor2 = analogRead(analogA2); 

  Serial.println(sensor0);             // debug value
  Serial.println(sensor1); 
  Serial.println(sensor2); 
  Serial.println("======================");
  delay(500);

}
