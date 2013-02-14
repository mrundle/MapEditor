#include "MapEditor.h"
 
void MapEditor::OnLoop() {
	// Check to make sure that the camera didn't move out of bounds - if so, fix
	Camera::CameraControl.CheckBounds();

	// Move camera
	if(Camera::CameraControl.MovingLeft == true){
		Camera::CameraControl.OnMove(1,0);
	}

	if(Camera::CameraControl.MovingRight == true){
		Camera::CameraControl.OnMove(-1,0);
	}

	if(Camera::CameraControl.MovingUp == true){
		Camera::CameraControl.OnMove(0,1);
	}

	if(Camera::CameraControl.MovingDown == true){
		Camera::CameraControl.OnMove(0,-1);
	}
}
