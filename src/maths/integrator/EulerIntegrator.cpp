/*
 * File:   EulerIntegrator.cpp
 * Author: nadrieril
 *
 * Created on March 20, 2014, 11:47 AM
 */

#include "EulerIntegrator.h"

void EulerIntegrator::evolve(double dt, std::function<Vector3D() > acc) {
	pos += vel * dt;
	vel += acc() * dt;
}
