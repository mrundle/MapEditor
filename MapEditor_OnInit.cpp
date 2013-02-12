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

	if((Control_Bar_One = Surface::OnLoad("./tilesets/controlBarOne.png")) == NULL){
		return false;
	}
	if((Control_Bar_Two = Surface::OnLoad("./tilesets/controlBarTwo.png")) == NULL){
		return false;
	}

	// Name the window
	SDL_WM_SetCaption("MapEditor",NULL);

	// Makes the pink background of the "X" and "Y" images transparent
	//Surface::Transparent(Surf_Char,255,0,255);

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

SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

//===============================================================================
// if everything loaded without errors

return true;

}
