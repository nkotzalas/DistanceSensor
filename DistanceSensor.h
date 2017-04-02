/*
	DistanceSensor.h - Library for controlling a distance sensor.

	Created by Nick Kotzalas, December 30, 2016
	Released into the public domain
*/

#ifndef DistanceSensor_h
#define DistanceSensor_h

#include "Arduino.h"

class DistanceSensor
{
	public:
		DistanceSensor(bool debug, int trigPin, int echoPin);

		/*
		 * Calculates the distance (in cm) to the next obstacle
		 */
		long calculateDistance();

		/*
		 * Setup the sensor
		 */
		void setup();

	private:
		int _echoPin;
		int _trigPin;
};

#endif