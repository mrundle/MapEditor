#include "MapEditor.h"
 
void MapEditor::OnLoop() {
	// Check to make sure that the camera didn't move out of bounds - if so, fix
	Camera::CameraControl.CheckBounds();
}
