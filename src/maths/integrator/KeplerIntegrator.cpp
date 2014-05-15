/*
 * File:   KeplerIntegrator.cpp
 * Author: nadrieril
 *
 * Created on March 19, 2014, 11:11 PM
 */

#include "KeplerIntegrator.h"

void KeplerIntegrator::evolve(double dt, std::function<Vector3D ()> acc) {
	time += dt;
	double M = orbit.M0 + orbit.n * time;
	double E = solveForE(M);

	double cW = cos(orbit.W); double sW = sin(orbit.W);
	double ci = cos(orbit.i); double si = sin(orbit.i);
	double cw = cos(orbit.w); double sw = sin(orbit.w);
	double cE = cos(E); double sE = sin(E);

	double e = orbit.e;
	double a = orbit.a;
	double b = a * sqrt(1 - e * e);

	double px = a * (cE - e);
	double py = b * sE;
	pos.setX(px * (cW * cw - sW * ci * sw) + py * (cW * sw + sW * ci * cw));
	pos.setY(px * (-sW * cw - cW * ci * sw) + py * (-sW * sw + cW * ci * cw));
	pos.setZ(-px * si * sw + py * si * cw);

	double k = orbit.n / (1 - e * cE);
	double vx = -a * k * sE;
	double vy = b * k * cE;
	vel.setX(vx * (cW * cw - sW * ci * sw) + vy * (cW * sw + sW * ci * cw));
	vel.setY(vx * (-sW * cw - cW * ci * sw) + vy * (-sW * sw + cW * ci * cw));
	vel.setZ(-vx * si * sw + vy * si * cw);
}

double KeplerIntegrator::solveForE(double M) const {
	double e2, e3, cM;
	double E, dE;
	double e = orbit.e;
	double mindE = 1 / orbit.a;
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
}

