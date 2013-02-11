#include "MapEditor.h"
 
//==============================================================================
void MapEditor::OnEvent(SDL_Event* Event) {
	Event::OnEvent(Event);
}

//==============================================================================
void MapEditor::OnLButtonDown(int mX, int mY) {
/*    // move the character
	//if(x_pos>500) CurrentPlayer*=-1;
	//if(x_pos<5) CurrentPlayer*=-1;
	if(CurrentPlayer==1){
		x_pos+=20;
		y_pos+=20;
	}
	if(CurrentPlayer==-1){
		x_pos-=20;
		y_pos-=20;
	}
*/
}

//==============================================================================
void MapEditor::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {

	int move_size=10;	
	
	switch(sym) {
		case SDLK_LEFT: {
			/*//x_pos-=move_size;
			goLeft=1;
			isMoving = true;
			//Mix_PauseMusic();
			Mix_PlayChannel( -1, sfx1, 0 );*/
			Camera::CameraControl.OnMove(5,0);
			break;
		}

		case SDLK_RIGHT: {
			/*//x_pos+=move_size;
			goRight=1;
			isMoving = true;
			//Mix_ResumeMusic();			
			Mix_PlayChannel( -1, sfx2, 0 );*/
			Camera::CameraControl.OnMove(-5,0);		
			break;
		}

		case SDLK_UP: {
			/*//y_pos-=move_size;
			goUp=1;
			isMoving = true;
			Mix_PlayChannel( -1, sfx3, 0 );*/
			Camera::CameraControl.OnMove(0,5);
			break;
		}

		case SDLK_DOWN: {
			/*//y_pos+=move_size;
			goDown=1;			
			isMoving = true;
			Mix_PlayChannel( -1, sfx4, 0 );*/
			Camera::CameraControl.OnMove(0,-5);
			break;
		}

    case SDLK_ESCAPE: {
   		std::cout << Camera::CameraControl.GetX() << "," << Camera::CameraControl.GetY() << std::endl;   
		//OnExit();
   		break;
    }

		default: {
		}
	}
}

//------------------------------------------------------------------------------
void MapEditor::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {
		case SDLK_LEFT: {
			goLeft=0;
			isMoving = false;
			Anim_Char.SetCurrentFrame(0);
			break;
		}

		case SDLK_RIGHT: {
			goRight=0;
			isMoving = false;
			Anim_Char.SetCurrentFrame(0);
			break;
		}

		case SDLK_UP: {
			goUp=0;
			isMoving = false;
			Anim_Char.SetCurrentFrame(0);
			break;
		}

		case SDLK_DOWN: {
			goDown=0;
			isMoving = false;
			Anim_Char.SetCurrentFrame(0);
			break;
		}

		default: {
		}
	}
}


//------------------------------------------------------------------------------
void MapEditor::OnExit(){
	Running = false;
}
