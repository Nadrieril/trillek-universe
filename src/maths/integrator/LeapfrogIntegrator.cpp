/* 
 * File:   LeapfrogIntegrator.cpp
 * Author: nadrieril
 * 
 * Created on March 21, 2014, 7:11 PM
 */

#include "LeapfrogIntegrator.h"

void LeapfrogIntegrator::evolve(double dt, std::function<Vector3D() > acc) {
	if(init){
		this->acc=acc();
	}
	vel += 0.5 * this->acc * dt;
	pos += vel * dt;
	this->acc=acc();
	vel += 0.5 * this->acc * dt;

	init=false;
}
