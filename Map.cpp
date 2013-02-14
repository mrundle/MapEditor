#include "Map.h"
#include "MapEditor.h"

Map::Map() {
	Surf_Tileset = NULL;
}

bool Map::OnLoad(char* File, bool Load,char* filenameLoad, int currentTileXID, int currentTileYID) {
	TileList.clear();

	if(Load == false){
		// generate a fresh map
		for(int Y=0;Y<MAP_HEIGHT;Y++) {
			for(int X=0;X<MAP_WIDTH;X++) {
				
				Tile tempTile;
			
				// Creates generic map
				tempTile.TileXID = currentTileXID;
				tempTile.TileYID = currentTileYID;
				tempTile.TypeID = TILE_TYPE_NORMAL;

				TileList.push_back(tempTile);
			}
		}
	}
	

	if(Load == true){
	// Load in a map from memory

		FILE* FileHandle = fopen(filenameLoad, "r");

		if(FileHandle == NULL) {
			cout << "fail";
			return false;
		}

		for(int Y=0;Y<MAP_HEIGHT;Y++) {
			for(int X=0;X<MAP_WIDTH;X++) {
				Tile tempTile;

				fscanf(FileHandle, "%d:%d ", &tempTile.TileXID, &tempTile.TileYID);

				TileList.push_back(tempTile);
			}
			fscanf(FileHandle, "\n");
		}

		fclose(FileHandle);

	}

		myfile.close();

	return true;

}

void Map::OnRender(SDL_Surface* Surf_Display, int MapX, int MapY) {
	if(Surf_Tileset == NULL){
		return;
	}

	int TilesetWidth = Surf_Tileset-> w / TILE_SIZE;
	int TilesetHeight = Surf_Tileset-> h / TILE_SIZE;

	int ID = 0;

	for(int Y=0;Y<MAP_HEIGHT;Y++) {
		for(int X=0;X<MAP_WIDTH;X++) {
			if(TileList[ID].TypeID == TILE_TYPE_NONE) {
				ID++;
				continue;
			}

			int tX = MapX + (X * TILE_SIZE);
			int tY = MapY + (Y * TILE_SIZE);

			int TilesetX = (TileList[ID].TileXID) * TILE_SIZE;
			int TilesetY = (TileList[ID].TileYID) * TILE_SIZE;

			Surface::OnDraw(Surf_Display, Surf_Tileset, tX, tY, TilesetX, TilesetY, TILE_SIZE, TILE_SIZE);

			ID++;
		}
	}
}


