/*
 * File:   Integrator.h
 * Author: nadrieril
 *
 * Created on March 19, 2014, 11:07 PM
 */

#ifndef INTEGRATOR_H
#define	INTEGRATOR_H

#include <functional>
#include "../Vector3D.h"

class Integrator {
public:
	Integrator() : pos(), vel(){};
	Integrator(Vector3D pos, Vector3D vel) : pos(pos), vel(vel){};

	virtual void evolve(double dt, std::function<Vector3D ()> acc)=0;
	virtual Vector3D getPosition() const {return pos;};
	virtual Vector3D getVelocity() const {return vel;};

protected:
	Vector3D pos;
	Vector3D vel;
};

#endif	/* INTEGRATOR_H */
