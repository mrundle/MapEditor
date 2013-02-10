#include "Entity.h"

std::vector<Entity*> Entity::EntityList;

Entity::Entity(){
	Surf_Entity = NULL;

	X = Y = 0.0f;

	Width = Height = 0;

	AnimState = 0;
}

Entity::~Entity(){
}

bool Entity::OnLoad(char* File, int Width, int Height, int MaxFrames) {
	if((Surf_Entity = Surface::OnLoad(File)) == NULL) {
		return false;
	}

	Surface::Transparent(Surf_Entity, 255, 0, 255);

	this->Width = Width;
	this->Height = Height;

	Anim_Control.MaxFrames = MaxFrames;

	return true;
}

void Entity::OnLoop(){
	Anim_Control.OnAnimate();
}

void Entity::OnRender(SDL_Surface* Surf_Display) {
	if(Surf_Entity == NULL || Surf_Display == NULL) return;

	//CSurface::OnDraw(Surf_Display, Surf_Entity, X, Y, Anim_Control.GetCurrentFrame() * Width, 0, Width, Height);
	Surface::OnDraw(Surf_Display,Surf_Entity,330,330,0,0,20,25);
}

void Entity::OnCleanup() {
	if(Surf_Entity) {
		SDL_FreeSurface(Surf_Entity);
	}

	Surf_Entity = NULL;
}
