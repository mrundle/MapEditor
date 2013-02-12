#ifndef _MAPEDITOR_H_
    #define _MAPEDITOR_H_
 
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <stdlib.h>
#include "Define.h"
#include "Event.h"
#include "Surface.h"
#include "Map.h"
#include "Camera.h"
#include <iostream>
 
class MapEditor : public Event {
    private:
	bool Running;

	// SDL surfaces
	SDL_Surface* Surf_Display;
	SDL_Surface* Control_Display;
	SDL_Surface* Control_Bar_One;
	SDL_Surface* Control_Bar_Two;

	// game map
	Map gameMap;

    private:

    public:
        MapEditor();
 
        int OnExecute();

    public:

		bool OnInit();
 
        void OnEvent(SDL_Event* Event);

		// When left mouse button clicks, gets position 
		void OnLButtonDown(int mX, int mY);

		void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

		void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

		void OnExit();
 
        void OnLoop();
 
        void OnRender();
 
        void OnCleanup();
};
 
#endif
