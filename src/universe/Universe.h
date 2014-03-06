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
#include "SpaceBody.h"


class Universe {
public:
    Universe();
    virtual ~Universe();

    std::vector<std::shared_ptr<SpaceBody>> getBodies() const;
    void addBody(SpaceBody *b);
    void removeBody(SpaceBody *b);

protected:
    std::vector<std::shared_ptr<SpaceBody>> bodies;
};

#endif /* UNIVERSE_H_ */
