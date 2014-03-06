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

SpaceBody::SpaceBody(double mass, SpaceBody *center, float e, long long a, float M0,
        float i, float w, float W) {
    this->mass = mass;
    orbit = new Orbit(center, this, e, a, M0, i, w, W);
}

SpaceBody::~SpaceBody() {
	// TODO Auto-generated destructor stub
}

double SpaceBody::getMass() const {
	return mass;
}


Position3D SpaceBody::getPosition(long time) const {
    return orbit->getSatellitePosition(time);
}
