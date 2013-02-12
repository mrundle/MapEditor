#include "Camera.h"
 
Camera Camera::CameraControl;
 
Camera::Camera() {
    X = -(WWIDTH/2);
	Y = -(WHEIGHT/2);
 
    TargetX = TargetY = NULL;
 
    TargetMode = TARGET_MODE_NORMAL;
}
 
void Camera::OnMove(int MoveX, int MoveY) {
    X += MoveX;
    Y += MoveY;
}
 
int Camera::GetX() {
    if(TargetX != NULL) {
        if(TargetMode == TARGET_MODE_CENTER) {
            return *TargetX - (WWIDTH / 2);
        }
 
        return *TargetX;
    }
 
    return X;
}
 
int Camera::GetY() {
    if(TargetY != NULL) {
        if(TargetMode == TARGET_MODE_CENTER) {
            return *TargetY - (WHEIGHT / 2);
        }
 
        return *TargetY;
    }
 
    return Y;
}
 
void Camera::SetPos(int X, int Y) {
    this->X = X;
    this->Y = Y;
}
 
void Camera::SetTarget(int* X, int* Y) {
    TargetX = X;
    TargetY = Y;
}

// Check to make sure that the camera didn't move out of bounds - if so, fix
void Camera::CheckBounds(){
	if(Camera::CameraControl.GetX() > 0){
		Camera::CameraControl.SetPos(0,Camera::CameraControl.GetY());
	}
	if(Camera::CameraControl.GetX() < ((MAP_WIDTH*TILE_SIZE*-1)+WWIDTH-CBAR_WIDTH)){
		Camera::CameraControl.SetPos((MAP_WIDTH*TILE_SIZE*-1)+WWIDTH-CBAR_WIDTH,Camera::CameraControl.GetY());
	}	
	if(Camera::CameraControl.GetY() > 0){
		Camera::CameraControl.SetPos(Camera::CameraControl.GetX(), 0);
	}
	if(Camera::CameraControl.GetY() < ((MAP_HEIGHT*TILE_SIZE*-1)+WHEIGHT)){
		Camera::CameraControl.SetPos(Camera::CameraControl.GetX(),(MAP_HEIGHT*TILE_SIZE*-1)+WHEIGHT);
	}
}
