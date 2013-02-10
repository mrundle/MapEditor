#include "MapEditor.h"
 
void MapEditor::OnCleanup() {
	// Free the surfaces
	SDL_FreeSurface(Surf_BG);
	SDL_FreeSurface(Surf_Char);
	SDL_FreeSurface(Surf_Display);

	for(int i=0;i<Entity::EntityList.size();i++){
		if(!Entity::EntityList[i]) continue;
	
		Entity::EntityList[i]->OnCleanup();
	}

	Entity::EntityList.clear();

	Area::AreaControl.OnCleanup();

	Mix_FreeMusic(mus);
	Mix_FreeChunk(sfx1);
	Mix_FreeChunk(sfx2);
	Mix_FreeChunk(sfx3);
	Mix_FreeChunk(sfx4);

	Mix_CloseAudio();

	// Quit out of SDL
	SDL_Quit();
}
