/* 
 * File:   Body.h
 * Author: nadrieril
 *
 * Created on March 20, 2014, 10:14 AM
 */

#ifndef BODY_H
#define	BODY_H
#include "../../maths/integrator/Integrator.h"

class Body {
public:
	Body(double mass, Integrator& integrator) : mass(mass), integrator(integrator){};
	// virtual ~Body();

	virtual void evolve(double dt, std::function<Vector3D ()> acc) {
		integrator.evolve(dt, acc);
	};
	virtual Vector3D getPosition() const {
		return integrator.getPosition();
	};
	virtual Vector3D getVelocity() const {
		return integrator.getVelocity();
	};

	double getMass() const {return mass;};

protected:
	double mass;
	Integrator& integrator;
};

#endif	/* BODY_H */
