#ifndef _MAP_H_
	#define _MAP_H_

#include "SDL/SDL.h"
#include <vector>

#include "Tile.h"
#include "Surface.h"

class Map {

	public:

		SDL_Surface* Surf_Tileset;

	private:

		std::vector<Tile> TileList;

	public:

		Map();

	public:

		bool OnLoad(char* File);

		void OnRender(SDL_Surface* Surf_Display, int MapX, int MapY);
};

#endif
