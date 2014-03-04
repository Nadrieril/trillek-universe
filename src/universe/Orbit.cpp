/*
 * Orbit.cpp
 *
 *  Created on: Mar 4, 2014
 *      Author: nadrieril
 */

#include "Orbit.h"

Orbit::Orbit(SpaceBody *center, SpaceBody *satellite, float e, long a, float M0,
        float i, float w, float W) {
    this->center = center;
    this->e = e;
    this->a = a;
    this->M0 = M0;
    this->i = i;
    this->w = w;
    this->W = W;
    n = 2 * M_PI
            * sqrt(
                    ((center->getMass() + satellite->getMass()) * G)
                            / (a * a * a));
}

Orbit::~Orbit() {
}

Position3D Orbit::getSatellitePosition(long time) const {
	double M = M0 + n * time;
	double E = solveForE(M);

	double cW = cos(W); double sW = sin(W);
	double ci = cos(i); double si = sin(i);
	double cw = cos(w); double sw = sin(w);

	double rx = a * (cos(E) - e);
	double ry = a * sqrt(1 - e * e) * sin(E);

	Position3D p;
	p.x = rx * (cW * cw - sW * ci * sw) + ry * (cW * sw + sW * ci * cw);
	p.y = rx * (-sW * cw - cW * ci * sw) + ry * (-sW * sw + cW * ci * cw);
	p.z = -rx * si * sw + ry * si * cw;

	Position3D p2=center->getPosition(time);
	p.x+=p2.x; p.y+=p2.y; p.z+=p2.z;
	return p;
}

double Orbit::solveForE(double M) const {
//    return M;

//    /*
	double e2, e3, cM;
	double E, dE;
	double mindE = 1 / a;
	M = fmod(M, 2 * M_PI);

	e2 = e * e;
	e3 = e * e2;
	cM = cos(M);
	E = M + (-0.5 * e3 + e + (e2 + 1.5 * cM * e3) * cM) * sin(M);

	dE = mindE + 1;
	double t1, t2, t3, t4, t5, t6;
	for (int count = 0; std::abs(dE) > mindE && count < 100; count++) {
		t1 = cos(E);
		t2 = e * t1 - 1;
		t3 = sin(E);
		t4 = e * t3;
		t5 = M + t4 - E;
		t6 = t5 / (0.5 * t5 * t4 / t2 + t2);
		dE = t5 / ((0.5 * t3 - t1 * t6 / 6) * e * t6 + t2);

		E = E - dE;
	}
	return E;
	//*/
}

