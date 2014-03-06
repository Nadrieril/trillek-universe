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
#include "../universe/Sun.cpp"

void draw(SDL_Surface *screen, Uint32 time);

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Surface *screen = SDL_SetVideoMode(1024, 768, 32, SDL_HWSURFACE);
    SDL_Surface *trace = SDL_CreateRGBSurface(SDL_HWSURFACE, 1024, 768, 32, 0, 0, 0, 0);
    SDL_WM_SetCaption("Solar system demo", NULL);

    Universe U;
    Sun *sun = new Sun(1e+10);
    U.addBody(sun);
    U.addBody(new SpaceBody(0, sun, 0.7, 150));
    U.addBody(new SpaceBody(0, sun, 0.2, 150, 0, 0, M_PI/4));

    SDL_Rect pos1, pos2;
    pos2.x = pos2.y = 0;
    Position3D pos3D;
    SDL_Surface *rect = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 0, 0, 0);
    SDL_FillRect(rect, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
    SDL_Surface *littlerect = SDL_CreateRGBSurface(SDL_HWSURFACE, 2, 2, 32, 0, 0, 0, 0);
    SDL_FillRect(littlerect, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

    bool ok = true;
    SDL_Event evt;
    Uint32 startTime = SDL_GetTicks();
    while (ok) {
        SDL_PollEvent(&evt);
        switch (evt.type) {
            case SDL_QUIT:
                ok = false;
                break;
        }

        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
        SDL_BlitSurface(trace, NULL, screen, &pos2);

//        for (std::vector<std::shared_ptr<SpaceBody>>::iterator it = U.getBodies().begin(); it != U.getBodies().end(); it++ )
        for (std::shared_ptr<SpaceBody> &it : U.getBodies()){
            pos3D =  it->getPosition(SDL_GetTicks() - startTime);
            pos1.x = pos3D.x - 5;
            pos1.y = pos3D.y - 5;
            SDL_BlitSurface(rect, NULL, screen, &pos1);
            pos1.x += 4;
            pos1.y += 4;
            SDL_BlitSurface(littlerect, NULL, trace, &pos1);
        }

//        pos3D = sun.getPosition(SDL_GetTicks() - startTime);
//        pos1.x = pos3D.x - 5;
//        pos1.y = pos3D.y - 5;
//        SDL_BlitSurface(rect, NULL, screen, &pos1);
//        pos1.x += 4;
//        pos1.y += 4;
//        SDL_BlitSurface(littlerect, NULL, trace, &pos1);

//		draw(screen, SDL_GetTicks()-startTime);
        SDL_Flip(screen);
    }

    SDL_Quit();

    return EXIT_SUCCESS;
}

void init() {

}
void draw(SDL_Surface *screen, Uint32 time) {

}
