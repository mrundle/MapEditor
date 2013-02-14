#include "MapEditor.h"


// Save game
void MapEditor::OnSave() {

	ofstream myfile;
	myfile.open (filenameSave);
	if(myfile.is_open()==false){
		cout << "Could not open file.\n";
	}

	int i=0;
	for(int Y=0;Y<MAP_HEIGHT;Y++) {
		for(int X=0;X<MAP_WIDTH;X++) {
			myfile << gameMap.TileList[i].TileXID << ":" << gameMap.TileList[i].TileYID << " ";
			i++;			
		}
		myfile << "\n";
	}

	myfile.close();

}
