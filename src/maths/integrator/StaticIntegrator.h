#ifndef STATICINTEGRATOR_H
#define	STATICINTEGRATOR_H

#include "Integrator.h"

class StaticIntegrator : public Integrator {
public:
	StaticIntegrator(){};
	StaticIntegrator(Vector3D pos, Vector3D vel) : Integrator(pos, vel){};

	void evolve(double dt, std::function<Vector3D()> acc) override {};
};

#endif	/* STATICINTEGRATOR_H */
