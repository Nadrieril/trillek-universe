/*
 * Orbit.h
 *
 *  Created on: Mar 4, 2014
 *      Author: nadrieril
 */

struct Position3D;
class Orbit;

#ifndef ORBIT_H_
#define ORBIT_H_
#define G 6.67384e-11

#include <cmath>
#include "SpaceBody.h"


struct Position3D {
	long long x;
	long long y;
	long long z;
};


class Orbit {
public:
    Orbit();
    Orbit(SpaceBody* center, SpaceBody* satellite, float e, long long a, float M0,
            float i, float w, float W);
    virtual ~Orbit();

    /** Calculates the position of the satellite at a given time
     *
	 * @param time
	 * @return
	 */
	Position3D getSatellitePosition(long time) const;

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

	SpaceBody *center;
	float e;
	long long a;
	double n;
	float M0;
	float i;
	float w;
	float W;
};

#endif /* ORBIT_H_ */
