/*
 * SpaceBody.cpp
 *
 *  Created on: Mar 4, 2014
 *      Author: nadrieril
 */

#include "SpaceBody.h"

SpaceBody::SpaceBody() {
    mass=0;
}

SpaceBody::SpaceBody(double mass, SpaceBody *orbitCenter, float e, double a, float M0,
        float i, float w, float W) {
    this->mass = mass;
    this->orbitCenter=orbitCenter;
    orbit = new Orbit(orbitCenter->getMass(), getMass(), e, a, M0, i, w, W);
}

SpaceBody::~SpaceBody() {
	// TODO Auto-generated destructor stub
}

double SpaceBody::getMass() const {
	return mass;
}

Vector3D SpaceBody::getPosition(long time) const {
    return orbit->getSatellitePosition(time) + orbitCenter->getPosition(time);
}
