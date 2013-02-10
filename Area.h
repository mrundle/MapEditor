#ifndef _AREA_H_
    #define _AREA_H_
 
#include "Map.h"
 
class Area {
    public:
        static Area            AreaControl;
 
    public:
        std::vector<Map>       MapList;
 
    private:
        int                     AreaSize;
 
        SDL_Surface*        Surf_Tileset;
 
    public:
        Area();
 
        bool    OnLoad(char* File);
 
        void    OnRender(SDL_Surface* Surf_Display, int CameraX, int CameraY);
 
        void    OnCleanup();
};
 
#endif
