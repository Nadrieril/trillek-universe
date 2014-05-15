/*
 * Universe.cpp
 *
 *  Created on: Mar 5, 2014
 *      Author: nadrieril
 */

#include "Universe.h"
#define G 6.67384e-11

Universe::Universe() {
	// TODO Auto-generated constructor stub

}

Universe::~Universe() {
	// TODO Auto-generated destructor stub
}

std::vector<std::shared_ptr<Body >> Universe::getBodies() const {
	return bodies;
}

void Universe::addBody(Body *b) {
	bodies.emplace_back(b);
}

void Universe::evolve(double dt) {
	for (std::shared_ptr<Body> it : bodies) {
		it->evolve(dt, acc(it));
	}
}

std::function<Vector3D ()> Universe::acc(std::shared_ptr<Body> b) const {
	auto &bodies=this->bodies;
	return [&b, &bodies]()->Vector3D {
		Vector3D pos = b->getPosition();
		Vector3D acc = Vector3D();
		for (std::shared_ptr<Body> other : bodies) {
			if (b != other && other->getMass() > 0) {
				Vector3D dp = other->getPosition() - pos;
				acc += other->getMass() * dp / dp.length3();
			}
		}
		return G * acc;
	};
}
