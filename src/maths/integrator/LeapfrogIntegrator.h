/* 
 * File:   LeapfrogIntegrator.h
 * Author: nadrieril
 *
 * Created on March 21, 2014, 7:11 PM
 */

#ifndef LEAPFROGINTEGRATOR_H
#define	LEAPFROGINTEGRATOR_H

#include "Integrator.h"

class LeapfrogIntegrator : public Integrator {
public:
	LeapfrogIntegrator(Vector3D pos, Vector3D vel) : Integrator(pos, vel){};

	void evolve(double dt, std::function<Vector3D ()> acc) override;

protected:
	Vector3D acc;
	bool init=true;
};

#endif	/* LEAPFROGINTEGRATOR_H */
