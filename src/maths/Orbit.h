/*
 * Orbit.h
 *
 *  Created on: Mar 4, 2014
 *      Author: nadrieril
 */

#ifndef ORBIT_H_
#define ORBIT_H_

#include <cmath>
#include "Vector3D.h"
#define G 6.67384e-11


class Orbit {
public:
    Orbit();
    Orbit(double centerMass, double satelliteMass, float e, double a, float M0,
            float i, float w, float W);
    virtual ~Orbit();

    /** Calculates the position of the satellite relative to the central body at a given time
     *
	 * @param time
	 * @return
	 */
	Vector3D getSatellitePosition(long time) const;

protected:
	/** Solves Kepler equation for E given M
	 * See http://en.wikipedia.org/wiki/Kepler's_equation
	 * Method taken from http://murison.alpheratz.net/dynamics/twobody/KeplerIterations_summary.pdf
	 * \see Orbit::getSatellitePosition
	 *
	 * @param M The mean anomaly
	 * @return Returns the approximated eccentric anomaly E
	 */
	double solveForE(double M) const;

	float e;
	double a;
	double n;
	float M0;
	float i;
	float w;
	float W;
};

#endif /* ORBIT_H_ */
