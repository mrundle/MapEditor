#include "MapEditor.h"
 
void MapEditor::OnLoop() {
	int moveSize=1;

	if(goUp==1) y_pos-=moveSize;
	if(goDown==1) y_pos+=moveSize;
	if(goRight==1) x_pos+=moveSize;
	if(goLeft==1) x_pos-=moveSize;

	if(isMoving == true){
		Anim_Char.OnAnimate();
	}

	for(int i=0;i<Entity::EntityList.size();i++){
		if(!Entity::EntityList[i]) continue;

		Entity::EntityList[i]->OnLoop();
	}
}
