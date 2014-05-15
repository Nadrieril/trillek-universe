/*
 * main.cpp
 *
 *  Created on: Mar 4, 2014
 *      Author: nadrieril
 */

#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h"

#include "../universe/Universe.h"
#include "../universe/bodies/Body.h"
#include "../maths/integrator/StaticIntegrator.h"
#include "../maths/integrator/KeplerIntegrator.h"
#include "../maths/integrator/EulerIntegrator.h"
#include "../maths/integrator/LeapfrogIntegrator.h"

void draw(SDL_Surface *screen, Uint32 time);

int main() {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Surface *screen = SDL_SetVideoMode(1024, 768, 32, SDL_HWSURFACE);
	SDL_Surface *trace = SDL_CreateRGBSurface(SDL_HWSURFACE, 1024, 768, 32, 0, 0, 0, 0);
	SDL_WM_SetCaption("Solar system demo", NULL);

	Uint32 white = SDL_MapRGB(screen->format, 255, 255, 255);
	Uint32 black = SDL_MapRGB(screen->format, 0, 0, 0);
	Uint32 red = SDL_MapRGB(screen->format, 255, 0, 0);
    Uint32 green = SDL_MapRGB(screen->format, 0, 255, 0);
    Uint32 blue = SDL_MapRGB(screen->format, 0, 0, 255);

	// Universe U;
	// Sun *sun = new Sun(1e+10);
	// U.addBody(sun);
	// U.addBody(new SpaceBody(0, sun, 0.7, 150));
	// U.addBody(new SpaceBody(0, sun, 0.5, 150, 0, 0, M_PI/4));
	Universe U;
	double sunmass = 1e+10;
	StaticIntegrator si;
	U.addBody(new Body(sunmass, si));

	KeplerIntegrator ki1(Orbit(sunmass, 0, 0.7, 150));
	U.addBody(new Body(0, ki1));

	// KeplerIntegrator ki2(Orbit(sunmass, 0, 0, 150, M_PI/2));
	// U.addBody(new Body(0, ki2));

    EulerIntegrator ei(Vector3D(150, 0, 0), Vector3D(0, -sqrt((sunmass * G)/150), 0));
    Body *eulerbody = new Body(0, ei);
    U.addBody(eulerbody);

	LeapfrogIntegrator lfi(Vector3D(150, 0, 0), Vector3D(0, -sqrt((sunmass * G)/150), 0));
	Body *leapfrogbody = new Body(0, lfi);
	U.addBody(leapfrogbody);


	SDL_Rect pos1, pos2;
	pos2.x = pos2.y = 0;
	Vector3D v;
	SDL_Surface *rect = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 0, 0, 0);
	SDL_FillRect(rect, NULL, white);
	SDL_Surface *littlerect = SDL_CreateRGBSurface(SDL_HWSURFACE, 1, 1, 32, 0, 0, 0, 0);

	bool ok = true;
	SDL_Event evt;
    Uint32 color;
    Uint32 startTime = SDL_GetTicks();
	while (ok) {
		SDL_PollEvent(&evt);
		switch (evt.type) {
			case SDL_QUIT:
				ok = false;
				break;
		}

		SDL_FillRect(screen, NULL, black);
		SDL_BlitSurface(trace, NULL, screen, &pos2);

		// for(int i=0;i<2000;i++)
            U.evolve(200);
		for (std::shared_ptr<Body> &it : U.getBodies()) {
            color=it.get() == eulerbody ? green : (it.get() == leapfrogbody ? red : blue);
			v = Vector3D(512, 384, 0) + it->getPosition();
            if(it.get() == leapfrogbody)
                v+=Vector3D(2,0,0);
			pos1.x = v.getX();
            pos1.y = v.getY();
            SDL_FillRect(littlerect, NULL, color);
            SDL_BlitSurface(littlerect, NULL, trace, &pos1);
            pos1.x -= 5;
            pos1.y -= 5;
			SDL_FillRect(rect, NULL, color);
            SDL_BlitSurface(rect, NULL, screen, &pos1);
		}

		SDL_Flip(screen);
	}

	SDL_Quit();

	return EXIT_SUCCESS;
}
