#include "MapEditor.h"
 
void MapEditor::OnCleanup() {
	// Free the surfaces
	SDL_FreeSurface(Surf_Display);
	SDL_FreeSurface(Control_Display);
	SDL_FreeSurface(Control_Bar_One);
	SDL_FreeSurface(Control_Bar_Two);
	SDL_FreeSurface(gameMap.Surf_Tileset);

	// Quit out of SDL
	SDL_Quit();
}
