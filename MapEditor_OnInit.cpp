#include "MapEditor.h"

bool MapEditor::OnInit() {

//=====================================================================================
// Initialize all SDL components

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
		return false;
	}

//======================================================================================
// Load the graphics

	// Create window and surface
	if((Surf_Display = SDL_SetVideoMode(WWIDTH,WHEIGHT,32,SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL){
		return false;
	}

	if((Control_Display = Surface::OnLoad("./graphics/controlBar.png")) == NULL){
		return false;
	}

	if((Tileset = Surface::OnLoad("./tilesets/grounds32.gif")) == NULL){
		return false;
	}
	if((Selector = Surface::OnLoad("./graphics/selector.png")) == NULL){
		return false;
	}

	// Name the window
	SDL_WM_SetCaption("MapEditor",NULL);

	// Makes the pink background transparent
	Surface::Transparent(Selector,255,0,255);
	Surface::Transparent(Control_Display,255,0,255);

//==========================================================================
// Load map tileset

if(gameMap.OnLoad("./maps/1.map") == false) {
	return false;
}

if((gameMap.Surf_Tileset = Surface::OnLoad("./tilesets/grounds32.gif")) == NULL){
	return false;
}

//==============================================================================
// Set keyboard repeat count

// Disabled key repeat because it was messing up selection of tiles
// SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

//===============================================================================
// if everything loaded without errors

return true;

}
