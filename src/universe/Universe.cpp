/*
 * Universe.cpp
 *
 *  Created on: Mar 5, 2014
 *      Author: nadrieril
 */

#include "Universe.h"

Universe::Universe() {
    // TODO Auto-generated constructor stub

}

Universe::~Universe() {
    // TODO Auto-generated destructor stub
}

std::vector<std::shared_ptr<SpaceBody> > Universe::getBodies() const {
    return bodies;
}

void Universe::addBody(SpaceBody *b) {
    bodies.push_back(std::shared_ptr<SpaceBody>(b));
}

