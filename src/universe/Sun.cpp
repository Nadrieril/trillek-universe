/*
 * Sun.cpp
 *
 *  Created on: Mar 4, 2014
 *      Author: nadrieril
 */

#include "SpaceBody.h"

class Sun: public SpaceBody {
public:
    Sun(double mass);
    virtual ~Sun();

    virtual Position3D getPosition(long time) const;
};

inline Sun::Sun(double mass) {
    this->mass = mass;
}

inline Sun::~Sun() {
}

inline Position3D Sun::getPosition(long time) const {
    Position3D p;
    p.x=512;
    p.y=384;
    p.z=0;
    return p;
}

