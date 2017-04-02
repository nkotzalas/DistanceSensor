/*
	DistanceSensor.h - Library for controlling a distance sensor.

	Created by Nick Kotzalas, December 30, 2016
	Released into the public domain
*/

#include "Arduino.h"
#include "DistanceSensor.h"

bool debugEnabled = false;

/**
 * Constructor of the movement handler
 */
DistanceSensor::DistanceSensor(bool debug, int trigPin, int echoPin)
{
	debugEnabled = debug;
	_trigPin = trigPin;
	_echoPin = echoPin;
}

/*
 * Setup the distance sensor's pins
 */
void DistanceSensor::setup()
{
	if (debugEnabled) {
		Serial.println("Initializing the distance sensor...");
		Serial.print("Echo Pin: ");
		Serial.print(_echoPin);
		Serial.print(" - Trig Pin: ");
		Serial.println(_trigPin);
	}

	pinMode(_echoPin, INPUT);
	pinMode(_trigPin, OUTPUT);

	if (debugEnabled) {
		Serial.println("Distance sensor has been initialized");
	}
}

/*
 * Calculates the distance (in cm) to the next obstacle
 */
long DistanceSensor::calculateDistance()
{
	digitalWrite(_trigPin, LOW);
	delayMicroseconds(2);

	digitalWrite(_trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(_trigPin, LOW);

	long duration = pulseIn(_echoPin, HIGH);

	// Calculate the distance in cms
	long distance = (duration/2) / 29.1;

	return distance;
}
