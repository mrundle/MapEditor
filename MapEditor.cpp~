#include "MapEditor.h"

MapEditor::MapEditor() {
	// Initialize the surfaces to NULL to avoid errors
	Surf_Char = NULL;
	Surf_BG = NULL;
	Surf_Display = NULL;

	// Initializes the initial position of the character
	x_pos=0;
	y_pos=0;
	goUp = goDown = goRight = goLeft = 0;
	charDirX = charDirY = 0;
	isMoving = false;
	CurrentPlayer=1;

	// Initialize the maxFrames for teh animation
	Anim_Char.MaxFrames=3;
		// If animation should oscillate, set Anim_Char.Oscillate = true;
	
	Running = true;
}
 
int MapEditor::OnExecute() {
	// Initialize the game; if it fails, return error code and close program
	if(OnInit() == false){
		std::cout << "here";
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
