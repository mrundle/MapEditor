#include "MapEditor.h"
 
void MapEditor::OnRender() {

	gameMap.OnRender(Surf_Display, Camera::CameraControl.GetX(), Camera::CameraControl.GetY());

	Surface::OnDraw(Control_Display, Tileset, 16, 0, 0, currentTileYID * TILE_SIZE,9 * TILE_SIZE,TILE_SIZE);
	Surface::OnDraw(Control_Display, Selector, 16 + (currentTileXID * TILE_SIZE), 0);
	Surface::OnDraw(Surf_Display, Control_Display, WWIDTH - CBAR_WIDTH, 0);

	// Refreshes the buffer and displays Surf_Display to screen
	SDL_Flip(Surf_Display);
}
