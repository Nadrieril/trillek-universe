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

SpaceBody::SpaceBody(double mass, SpaceBody *center) {
    this->mass=mass;
    orbit=new Orbit(center, this, 0.5, 200, 0, 0, 0, 0);
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
