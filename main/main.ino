int OkLED = 14;                                          //Green LED Pin (which is showing that the moisture level is perfectly fine)
int WateringLED = 12;                                    //Red LED Pin (which is showing that the plant is being watered)
int relay = 27;                                          //Relay Input Pin
const int dry = 195;                                     //Value for the Soil Moisture Sensor
const int wet = 128;                                     //Value for the Soil Moisture Sensor
void setup() {                                           //This will run only once
  pinMode(WateringLED, OUTPUT);                          //Watering LED is used as a Output Device
  pinMode(OkLED, OUTPUT);                                //OK LED is used as a Output Device
  pinMode(relay, OUTPUT);                                //Relay is used as a Output Device
  Serial.begin(115200);                                  //Serial Port communication
}

void loop() {                                            //This will run repeatedely
  int sensorVal = analogRead(13);                        //Soil Moisture Sensor Pin
  Serial.println(sensorVal);                             //Printing the Soil Moisture Value to the Serial Port communicater
  int moistureLevel = map(sensorVal, wet, dry, 100, 0);  //Converting the Soil Moisture Value to percentage
  Serial.print(moistureLevel);                           //Printing the Soil Moisture Value percentage to the Serial Port communicater
  Serial.println("%"); 
  if (moistureLevel < 75) {                              //Declaring a "if" loop that if the Soil Moisture Value percentage is less than 75% then 
    digitalWrite(relay, LOW);                            //Relay will be turned ON
    digitalWrite(WateringLED, HIGH);                     //Watering LED will be turned ON
    digitalWrite(OkLED, LOW);                            //OK LED will be turned OFF
  }else{                                                 //if the Soil Moisture Value percentage is over 75 then
    digitalWrite(relay, HIGH);                           //Relay will be OFF
    digitalWrite(WateringLED, LOW);                      //Watering LED will be OFF
    digitalWrite(OkLED, HIGH);                           //OK LED will be ON
  } 
  delay(100);                                            //All the things in the "loop" part will be repeated in 0.1 seconds(100 milliseconds)
}