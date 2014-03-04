/*
 * main.cpp
 *
 *  Created on: Mar 4, 2014
 *      Author: nadrieril
 */

#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h"

#include "../universe/Sun.cpp"

void draw(SDL_Surface *screen, Uint32 time);

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Surface *screen = SDL_SetVideoMode(1024, 768, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Solar system demo", NULL);

    Sun sun = Sun(1e+10);
    SpaceBody earth = SpaceBody(0, &sun);

    SDL_Rect pos;
    Position3D pos3D;
    SDL_Surface *rect = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 0, 0, 0);

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

//        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

        pos3D = earth.getPosition(SDL_GetTicks() - startTime);
        pos.x = pos3D.x - 5;
        pos.y = pos3D.y - 5;
        SDL_FillRect(rect, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
        SDL_BlitSurface(rect, NULL, screen, &pos);

        pos3D = sun.getPosition(SDL_GetTicks() - startTime);
        pos.x = pos3D.x - 5;
        pos.y = pos3D.y - 5;
        SDL_FillRect(rect, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
        SDL_BlitSurface(rect, NULL, screen, &pos);

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
