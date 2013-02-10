#include "Animation.h"

Animation::Animation() {
	CurrentFrame = 0;
	MaxFrames = 0;
	FrameInc = 1;

	FrameRate = 100; // Milliseconds
	OldTime = 0;

	Oscillate = true;
}

void Animation::OnAnimate() {
	// This determines the FPS (how fast the animation will display). Desired rate
	// is 1 frame per second, so FrameRate = 1000 (milliseconds). OldTime starts at zero
	// and then keeps track of the time that has passed since SDL started.
	if(OldTime + FrameRate > SDL_GetTicks()) {
		return;
	}

	OldTime = SDL_GetTicks();

	CurrentFrame += FrameInc;

	if(Oscillate) {
		if(FrameInc > 0){
			if(CurrentFrame >= MaxFrames) {
				FrameInc = -FrameInc;
			}
		}else{
			if(CurrentFrame <= 0) {
				FrameInc = -FrameInc;
			}
		}
	}else{
		if(CurrentFrame >= MaxFrames) {
			CurrentFrame = 0;
		}
	}
}

void Animation::SetFrameRate(int Rate) {
	FrameRate = Rate;
}

void Animation::SetCurrentFrame(int Frame){
	if(Frame < 0 || Frame >= MaxFrames) return;

	CurrentFrame = Frame;
}

int Animation::GetCurrentFrame() {
	return CurrentFrame;
}
	
