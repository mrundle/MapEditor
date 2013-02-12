#include "MapEditor.h"
#include <iostream>
using namespace std;
 
//==============================================================================
void MapEditor::OnEvent(SDL_Event* Event) {
	Event::OnEvent(Event);
}

//==============================================================================
void MapEditor::OnLButtonDown(int MouseXPos, int MouseYPos) {
	// On left mouse button click

	if(MouseXPos < (WWIDTH - CBAR_WIDTH)){
		int CameraXPos = Camera::CameraControl.GetX();
		int CameraYPos = Camera::CameraControl.GetY();

		int MapXPos = -1 * (CameraXPos - MouseXPos);
		int MapYPos = -1 * (CameraYPos - MouseYPos);

		int MapXRemainder = MapXPos % TILE_SIZE;
		int MapYRemainder = MapYPos % TILE_SIZE;

		int MapXTile = (MapXPos - MapXRemainder) / TILE_SIZE;
		int MapYTile = (MapYPos - MapYRemainder) / TILE_SIZE;

		int TileNumber = (MapYTile * MAP_WIDTH) + MapXTile;
		gameMap.TileList[TileNumber].TileXID = currentTileXID;
		gameMap.TileList[TileNumber].TileYID = currentTileYID;
		gameMap.TileList[TileNumber].TypeID = TILE_TYPE_NORMAL;
	}

// TYPE SELECTION
/*
	if(MouseXPos > (WWIDTH - CBAR_WIDTH)){
		
		// First row - should probably get rid of magic numbers
		if( (MouseXPos > 718) && (MouseXPos < 750) ){
			

		{



	}
*/
}

//==============================================================================
void MapEditor::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {

	int move_size=10;	
	
	switch(sym) {
		case SDLK_LEFT: {
			Camera::CameraControl.OnMove(5,0);
			break;
		}

		case SDLK_RIGHT: {
			Camera::CameraControl.OnMove(-5,0);	
			break;
		}

		case SDLK_UP: {
			Camera::CameraControl.OnMove(0,5);
			break;
		}

		case SDLK_DOWN: {
			Camera::CameraControl.OnMove(0,-5);
			break;
		}

    case SDLK_ESCAPE: {  
		OnExit();
   		break;
    }

		default: {
		}
	}
}

//------------------------------------------------------------------------------
void MapEditor::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {
		case SDLK_LEFT: {
			break;
		}

		case SDLK_RIGHT: {
			break;
		}

		case SDLK_UP: {
			break;
		}

		case SDLK_DOWN: {
		}

		default: {
		}
	}
}


//------------------------------------------------------------------------------
void MapEditor::OnExit(){
	Running = false;
}
