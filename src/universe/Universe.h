/*
 * Universe.h
 *
 *  Created on: Mar 5, 2014
 *      Author: nadrieril
 */

class Universe;

#ifndef UNIVERSE_H_
#define UNIVERSE_H_

#include <vector>
#include <memory>
#include "bodies/Body.h"


class Universe {
public:
    Universe();
    virtual ~Universe();

    std::vector<std::shared_ptr<Body>> getBodies() const;
    void addBody(Body *b);
    void removeBody(Body *b);

    void evolve(double dt);

protected:
	std::function<Vector3D ()> acc(std::shared_ptr<Body> b) const;

    std::vector<std::shared_ptr<Body>> bodies;
};

#endif /* UNIVERSE_H_ */
