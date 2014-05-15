/*
 * File:   KeplerIntegrator.h
 * Author: nadrieril
 *
 * Created on March 19, 2014, 11:11 PM
 */

#ifndef KEPLERINTEGRATOR_H
#define	KEPLERINTEGRATOR_H

#include "Integrator.h"
#include <cmath>
#define G 6.67384e-11


class Orbit {
public:
    Orbit(double centerMass, double satelliteMass, float e, double a, float M0=0,
            float i=0, float w=0, float W=0) : e(e), a(a), M0(M0), i(i), w(w), W(W) {
		n = sqrt(((centerMass + satelliteMass) * G) / (a * a * a));
	};

// protected:
	float e;
	double a;
	double n;
	float M0;
	float i;
	float w;
	float W;
};


class KeplerIntegrator : public Integrator {
public:
	KeplerIntegrator(Orbit orbit) : orbit(orbit){};
	// KeplerIntegrator(const KeplerIntegrator& orig);
	// virtual ~KeplerIntegrator();

	void evolve(double dt, std::function<Vector3D ()> acc) override;

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

	Orbit orbit;
	double time;
};

#endif	/* KEPLERINTEGRATOR_H */

