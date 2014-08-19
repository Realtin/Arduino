float tempSensor = A4;
float tempvalue = 0.0;
# define BANDGAPREF 14

void setup(){
pinMode(tempSensor, INPUT);
Serial.begin(9600);
}

void loop(){
float refReading = (float)analogRead(BANDGAPREF); 
float supplyvoltage = (3300.0 / 1024.0);
tempvalue=analogRead(tempSensor);
float voltage = tempvalue * supplyvoltage;
float tempC = (voltage - 500.0)/10.0;

Serial.println(refReading);
Serial.println(supplyvoltage);
Serial.println(tempvalue);
Serial.println(voltage);
Serial.println(tempC); Serial.println("degrees C");
delay(6000);
}
