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

    virtual Vector3D getPosition(long time) const;
    virtual bool onOrbit() const;
};

inline Sun::Sun(double mass) {
    this->mass = mass;
}

inline Sun::~Sun() {
}

inline Vector3D Sun::getPosition(long time) const {
    return Vector3D(512, 384, 0);
}

inline bool Sun::onOrbit() const {
    return false;
}