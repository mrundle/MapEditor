#include "MapEditor.h"
 
//==============================================================================
void MapEditor::OnEvent(SDL_Event* Event) {
	Event::OnEvent(Event);
}

//==============================================================================
void MapEditor::OnLButtonDown(int MouseXPos, int MouseYPos) {
	// On left mouse button click

	if(1 /* MouseXPos < (WWIDTH - CBAR_WIDTH) */){
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
			if(!((currentTileXID==0) && (currentTileYID==0))){
				currentTileXID--;
				if(currentTileXID < 0){
					currentTileXID=8;
					currentTileYID--;
				}
			}
			if((currentTileXID==0) && (currentTileYID==0)){
				currentTileXID=8;
				currentTileYID=18;
			}
			break;
		}

		case SDLK_RIGHT: {
			if(!((currentTileXID==8) && (currentTileYID==18))){
				currentTileXID++;
				if(currentTileXID > 8){
					currentTileXID=0;
					currentTileYID++;
				}
			}
			if((currentTileXID==8) && (currentTileYID==18)){
				currentTileXID=0;
				currentTileYID=0;
			}
			break;
		}

		case SDLK_UP: {
			if(currentTileYID > 0){
				currentTileYID--;
			}
			if(currentTileYID <= 0){
				currentTileYID=18;
			}
			break;
		}

		case SDLK_DOWN: {
			if(currentTileYID < 18){
				currentTileYID++;
			}
			if(currentTileYID >= 18){
				currentTileYID=0;
			}
			break;
		}

		// Left
		case SDLK_a: {
			Camera::CameraControl.OnMove(5,0);
			break;
		}

		// Right
		case SDLK_d: {
			Camera::CameraControl.OnMove(-5,0);	
			break;
		}

		// Up
		case SDLK_w: {
			Camera::CameraControl.OnMove(0,5);
			break;
		}

		// Down
		case SDLK_s: {
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
