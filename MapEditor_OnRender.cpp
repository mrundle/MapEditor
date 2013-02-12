#include "MapEditor.h"
 
void MapEditor::OnRender() {

	gameMap.OnRender(Surf_Display, Camera::CameraControl.GetX(), Camera::CameraControl.GetY());

	//Surface::OnDraw(Control_Display, Control_Bar_One, 18, 12);
	Surface::OnDraw(Surf_Display, Control_Display, WWIDTH - CBAR_WIDTH, 0);

	// Refreshes the buffer and displays Surf_Display to screen
	SDL_Flip(Surf_Display);
}
