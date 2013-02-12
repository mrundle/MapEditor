#include "MapEditor.h"

MapEditor::MapEditor() {
	// Initialize the surfaces to NULL to avoid errors
	Surf_Display = NULL;
	Control_Display = NULL;
	Control_Bar_One = NULL;
	Control_Bar_Two = NULL;

	currentTileXID=3;
	currentTileYID=6;

	Running = true;
}
 
int MapEditor::OnExecute() {
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

	

	OnCleanup();

	return 0;
}
 
int main(int argc, char* argv[]) {
    MapEditor theApp;
 
    return theApp.OnExecute();
}
