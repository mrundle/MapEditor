#include "MapEditor.h"
#include <iostream>
using namespace std;

MapEditor::MapEditor() {
	// Initialize the surfaces to NULL to avoid errors
	Surf_Display = NULL;
	Control_Display = NULL;
	Tileset = NULL;
	Selector =  NULL;

	currentTileXID=0;
	currentTileYID=1;

	Load = false;
	Running = true;
}

void MapEditor::UserInput(){
	char input;

	cout << "Would you like to load a file? [y/n] ";
	cin >> input;
	if(input=='y' || input == 'Y'){
		Load = true;
	}
	if(input=='n' || input == 'N'){

	}

	if(Load == true){
		cout << "Which file would you like to load?";
		cin >> filenameLoad;
	}else{
		cout << "Tile XID: ";
		cin >> currentTileXID;
		cout << "Tile YID: ";
		cin >> currentTileYID;
	}

	cout << "What filename would you like to save this under? ";
	cin >> filenameSave;

}

int MapEditor::OnExecute() {
	UserInput();

	// Initialize the game; if it fails, return error code and close program
	if(OnInit() == false){
		return -1;
	}

	SDL_Event Event;

	while(Running){
		// check for events (user input), pass one at a time to OnEvent()
		while(SDL_PollEvent(&Event)){
			OnEvent(&Event);
		}

		// Manipulate data
		OnLoop();
		// Render the output
		OnRender();
	}

	OnSave();

	// Clean up trash
	OnCleanup();

	return 0;
}

int main(int argc, char* argv[]) {

    MapEditor theApp; 
    return theApp.OnExecute();
}
