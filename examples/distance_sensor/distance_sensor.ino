/* Example sketch that uses the DistanceSensor library */
#include <DistanceSensor.h>

// Debug logs are enabled (switch to false to disable)
const bool debug = true;

/* Pin wiring map */
const int ECHO_PIN = 4;
const int TRIG_PIN = 7;

// Create the instance of the DistanceSensor
DistanceSensor distanceSensor = DistanceSensor(debug, TRIG_PIN, ECHO_PIN);



void setup() {
  Serial.begin(9600);

  // Initialize the distance sensor
  distanceSensor.setup();
}

/*
 * Calculates the distance to the next obstacle every 1 second and prints
 * it to the Serial monitor
 */
void loop() {
  long distance = distanceSensor.calculateDistance();
  Serial.print("Distance = ");
  Serial.println(distance);
  
  delay(1000);
}