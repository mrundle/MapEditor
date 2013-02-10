#include "MapEditor.h"

bool MapEditor::OnInit() {

//=====================================================================================
// Initialize all SDL components

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
		return false;
	}

//======================================================================================
// Load the graphics

	/*
	Create window and surface
	SDL_SetVideoMode(window width, window height, bit resolution [16 or 32 recommended],display flags)
	SDL_HWSURFACE tells SDL to use hardware memory for storing images and such
	SDL_DOUBLEBUF tells SDL to use double buffering, important to keep screen from flickering
	another flag of interest is SDL_FULLSCREEN which makes the window go full screen
	*/
	if((Surf_Display = SDL_SetVideoMode(WWIDTH,WHEIGHT,32,SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL){
		return false;
	}

	// Name the window
	SDL_WM_SetCaption("PokeClone",NULL);

	// Load the character
	if((Surf_Char = Surface::OnLoad("./graphics/pokecharAnim.png")) == NULL){
		std::cout << "char";
		return false;
	}

	// Load the background
	//if((Surf_BG = CSurface::OnLoad("./gfx/pokemon.png")) == NULL){
	//	return false;
	//}

	// Makes the pink background of the "X" and "Y" images transparent
	Surface::Transparent(Surf_Char,255,0,255);

//==========================================================================
// Load map tileset and camera

if(MapEditor::AreaControl.OnLoad("./maps/1.area") == false) {
	std::cout << "maps";
	return false;
}

//==========================================================================
// Load the entities

if(Entity1.OnLoad("./graphics/pokecharAnim.png",20,25,3) == false) {
	return false;
}

if(Entity2.OnLoad("./graphics/pokecharAnim.png",20,25,3) == false) {
	return false;
}

Entity1.X = 1040;
Entity2.Y = 4295;

Entity2.X = 1090;
Entity2.Y = 4295;

Entity::EntityList.push_back(&Entity1);
Entity::EntityList.push_back(&Entity2);

//==========================================================================
// Load sound bites and play the music

	// Open audio player
    	//Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );

	// Load the music file
	//mus = Mix_LoadMUS("./sounds/HeyThere.wav");
	//if(mus==NULL){
	//	std::cout << "Error loading sounds." << std::endl;
	//	return false;	
	//}

	// Load the sound effects
	// http://rpg.hamsterrepublic.com/ohrrpgce/Free_Sound_Effects#Battle_Sounds
	//sfx1 = Mix_LoadWAV("./sounds/DrainMagic.ogg");
	//sfx2 = Mix_LoadWAV("./sounds/MediumExplosion.ogg");
	//sfx3 = Mix_LoadWAV("./sounds/Powerup.ogg"); 
	//sfx4 = Mix_LoadWAV("./sounds/SmallExplosion.ogg");
	//if(sfx1==NULL || sfx2==NULL || sfx3==NULL || sfx4==NULL){
	//	return false;
	//}
	//
	//if(Mix_PlayingMusic() == 0){
	//	Mix_PlayMusic(mus,-1);
	//}

//==============================================================================
// Set keyboard repeat count

SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

//===============================================================================
// if everything loaded without errors

return true;

}
