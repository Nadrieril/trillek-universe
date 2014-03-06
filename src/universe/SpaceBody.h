/*
 * SpaceBody.h
 *
 *  Created on: Mar 4, 2014
 *      Author: nadrieril
 */

class SpaceBody;

#ifndef SPACEBODY_H_
#define SPACEBODY_H_

#include "Orbit.h"

class SpaceBody {
public:
    SpaceBody();
	SpaceBody(double mass, SpaceBody *center, float e, long long a, float M0=0,
            float i=0, float w=0, float W=0);
	virtual ~SpaceBody();

	double getMass() const;
	virtual Position3D getPosition(long time) const;

protected:
	double mass;
	Orbit *orbit;
};

#endif /* SPACEBODY_H_ */
