#include <vector>

#include "Animation.h"
#include "Surface.h"

class Entity {

	public:

		static std::vector<Entity*>  EntityList;

	protected:

		Animation Anim_Control;

		SDL_Surface* Surf_Entity;

	public:

		float X;
		float Y;

		int Width;
		int Height;

		int AnimState;

	public:

		Entity();
		virtual ~Entity();

	public:

		virtual bool OnLoad(char* File, int Width, int Height, int MaxFrames);

		virtual void OnLoop();

		virtual void OnRender(SDL_Surface* Surf_Display);

		virtual void OnCleanup();

};
