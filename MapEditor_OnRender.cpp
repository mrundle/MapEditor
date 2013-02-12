#include "MapEditor.h"
 
void MapEditor::OnRender() {

	gameMap.OnRender(Surf_Display, Camera::CameraControl.GetX(), Camera::CameraControl.GetY());

	Surface::OnDraw(Control_Display, Tileset, 16, 0, 0 /*tileset x*/, 0 /*tileset y*/,288,32);
	Surface::OnDraw(Control_Display, Selector, 16 /* + tile number */, 0);
	Surface::OnDraw(Surf_Display, Control_Display, WWIDTH - CBAR_WIDTH, 0);

	// Refreshes the buffer and displays Surf_Display to screen
	SDL_Flip(Surf_Display);
}
