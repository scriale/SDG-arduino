#include <dht.h>
#include <Adafruit_Sensor.h>
#define dht_lettura A0
#define moisture_lettura A1

int fan = 2;
int pump = 3;
int Temperature_Value;
int Humidity_Value;
int Moisture_Value;
int oktemp=20;
int okmoist=550;
String values;

String readString;
dht DHT;
 void setup() {  
  pinMode(fan, OUTPUT);
  pinMode(pump, OUTPUT);
  digitalWrite(fan, HIGH);
  digitalWrite(pump, HIGH);
 
 //Initializes the serial connection at 9600 to sent sensor data to ESP8266.
 Serial.begin(9600); 
 Serial.println("Avvio DSG\n\n");
 
delay(2000);  
  
 }
 
void loop() {
 
DHT.read11(dht_lettura);
  // get sensors data and put in to values variables as a string.
   values= (get_Temperature_Value()+','+get_Humidity_Value()+','+get_Moisture_Value());
  if (Temperature_Value>oktemp){
    digitalWrite(fan, LOW);
        }
    else
    {
      digitalWrite(fan,HIGH);
    }
    
    if (Moisture_Value>okmoist){
    digitalWrite(pump, LOW);
    
    }
    else
    {
      digitalWrite(pump,HIGH);
    }
       delay(1000);
       // removed any buffered previous serial data.
       Serial.flush();
       delay(1000);
       // sent sensors data to serial (sent sensors data to ESP8266)
       Serial.print(values);
       
       
       delay(2000);

}
String get_Temperature_Value(){ 
 
Temperature_Value =DHT.temperature;
    delay(2000);
    return String(Temperature_Value);  
    
}
String get_Humidity_Value(){ 
  
Humidity_Value =DHT.humidity;
delay(2000);
return String(Humidity_Value);  
}

String get_Moisture_Value(){ 
  
Moisture_Value =analogRead(moisture_lettura);
delay(2000);
return String(Moisture_Value);  
} 
  
