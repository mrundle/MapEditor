#ifndef ANIMATION_H_
	#define ANIMATION_H_

#include "SDL/SDL.h"

class Animation {

	private:

		int CurrentFrame;
		int FrameInc;

	private:

		int FrameRate; // Milliseconds
		int OldTime;

	public:

		int MaxFrames;
		bool Oscillate;

	public:

		Animation();
		void OnAnimate();

	public:

		void SetFrameRate(int Rate);
		void SetCurrentFrame(int Frame);
		int GetCurrentFrame();

};

#endif
