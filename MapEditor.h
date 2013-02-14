#ifndef _MAPEDITOR_H_
    #define _MAPEDITOR_H_
 
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"

#include <stdlib.h>

#include <iostream>
#include <fstream>

#include <vector>

#include "Define.h"
#include "Event.h"
#include "Surface.h"
#include "Map.h"
#include "Camera.h"

using namespace std;
 
class MapEditor : public Event {
    private:
	bool Running;

	// SDL surfaces
	SDL_Surface* Surf_Display;
	SDL_Surface* Control_Display;
	SDL_Surface* Tileset;
	SDL_Surface* Selector;

	// game map
	Map gameMap;

	public: 
	// filename
	char filenameSave[32];
	char filenameLoad[32];
	bool Load;

	public: // need to make get/set functions for these

	// current tile choice
	int currentTileXID;
	int currentTileYID;
	static MapEditor MapEditorControl;

    public:
        MapEditor();

        int OnExecute();

		void UserInput();

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

		void OnSave();

        void OnCleanup();

};
 
#endif
