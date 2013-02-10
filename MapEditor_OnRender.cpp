#include "MapEditor.h"
 
void MapEditor::OnRender() {
	// Draw background to screen based on the character's position
	//CSurface::OnDraw(Surf_Display,Surf_BG,0,0,x_pos-300,y_pos-300,600,600);
	Area::AreaControl.OnRender(Surf_Display, Camera::CameraControl.GetX(), Camera::CameraControl.GetY());
	// the last 4 inputs are determining the direction that the character sprite is facing
	// 20x25 is the dimension of each box containing the sprite, th charDirX and charDirY are providing
	// the coordinate of the upper lefthand corner of the sprite's location on the sheet
	Surface::OnDraw(Surf_Display,Surf_Char,320,240,Anim_Char.GetCurrentFrame()*20,0,20,25);

	// Draw the entities
	for(int i=0;i<Entity::EntityList.size();i++){
		if(!Entity::EntityList[i]) continue;
	
		Entity::EntityList[i]->OnRender(Surf_Display);
	}

	// Refreshes the buffer and displays Surf_Display to screen
	SDL_Flip(Surf_Display);
}
