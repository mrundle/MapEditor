#ifndef _MAPEDITOR_H_
    #define _MAPEDITOR_H_
 
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <stdlib.h>
#include "Define.h"
#include "Event.h"
#include "Surface.h"
#include "Animation.h"
#include "Entity.h"
#include "Area.h"
#include "Camera.h"
#include <iostream>
 
class MapEditor : public Event {
    private:
	bool Running;

	// SDL surfaces
	SDL_Surface* Surf_Display;
	SDL_Surface* Surf_Char;
	SDL_Surface* Surf_BG;

	Mix_Music *mus;
	Mix_Chunk *sfx1;
	Mix_Chunk *sfx2;
	Mix_Chunk *sfx3;
	Mix_Chunk *sfx4;

	Animation Anim_Char;

	Entity Entity1;
	Entity Entity2;

    private:
	// Keeps track of the characters x and y positions
	int x_pos;
	int y_pos;
	int goUp,goDown,goRight,goLeft;

	// Keeps track of which way the character is facing
	// accomplished by providing the x and y coordinate of upper left hand corner of 
	// sprites location on the sheet
	int charDirX, charDirY;
	//is there movement? (cues animation)
	bool isMoving;

	// Keeps track of whether the character is moving up or down
	int CurrentPlayer;

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
