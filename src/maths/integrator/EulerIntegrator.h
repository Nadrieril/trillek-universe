/* 
 * File:   EulerIntegrator.h
 * Author: nadrieril
 *
 * Created on March 20, 2014, 11:47 AM
 */

#ifndef EULERINTEGRATOR_H
#define	EULERINTEGRATOR_H

#include "Integrator.h"

class EulerIntegrator : public Integrator {
public:
	EulerIntegrator(Vector3D pos, Vector3D vel) : Integrator(pos, vel){};

	void evolve(double dt, std::function<Vector3D ()> acc) override;
};

#endif	/* EULERINTEGRATOR_H */
