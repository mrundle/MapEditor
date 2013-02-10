#include "Surface.h"

Surface::Surface(){
}

// simple static function that will load a surface for us
SDL_Surface* Surface::OnLoad(char* File) {
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;
 
    if((Surf_Temp = IMG_Load(File)) == NULL) {
        return NULL;
    }
 
	// here we're optimizing the image - using "SDL_DisplayFormatAlpha" instead of "SDL_DisplayFormat" because the former allows us to designate a color channel, in our case bright pink, as transparent. This helps a lot when rendering our sprites
    Surf_Return = SDL_DisplayFormatAlpha(Surf_Temp);
    SDL_FreeSurface(Surf_Temp);
 
    return Surf_Return;
}

/*
Function to draw (blit) images.
Passes in two surfaces and two int variables. First surface is the destination surface, the one we'll draw on.
The second surface is the source surface, or the surface that we're going to use to draw the other surface.
The basic idea is that we're putting Surf_Src onto Surf_Dest. The X and Y variables is the position on the 
Surf_Dest that we're drawing this surface to.
*/
bool Surface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y){
	// Make sure we have valid surfaces
	if(Surf_Dest == NULL || Surf_Src == NULL){
		return false;
	}

	// Define SDL_Rect, an SDL structure that has four members: x,y,w,h. This creates the dimensions for a rectangle.
	SDL_Rect DestR;

	// We're only worried about where we're drawing to (not the size) so we assign X,Y coordinates.
	DestR.x = X;
	DestR.y = Y;

	// Finally, call the function to draw the image
	SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);

	return true;
}

// Adding a second OnDraw Function to handle the case where we only want to draw a PART of an image to another surface
bool Surface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H) {
    if(Surf_Dest == NULL || Surf_Src == NULL) {
        return false;
    }

   /* 
   Adding another SDL_Rect - this source rect allows us to specify what pixels from the source to copy over to the
   destination. For example, specifying 0,0,50,50 as parameters, it would only draw upper left part of the surface
   (a 50x50 square.)
   */
    SDL_Rect DestR;
 
    DestR.x = X;
    DestR.y = Y;
 
    SDL_Rect SrcR;
 
    SrcR.x = X2;
    SrcR.y = Y2;
    SrcR.w = W;
    SrcR.h = H;
 
    SDL_BlitSurface(Surf_Src, &SrcR, Surf_Dest, &DestR);
 
    return true;
}

bool Surface::Transparent(SDL_Surface* Surf_Dest, int R, int G, int B) {
    // ensure valid surface
    if(Surf_Dest == NULL) {
        return false;
    }
 
    /* Set color key as transparent
    The first argument is the surface to apply the color to, the second is some flags telling SDL how to 
    perform the operation, and the third is the color to make transparent. The flags being applied are pretty 
    basic, the first tells SDL to apply the color key to the source (the surface being passed) and the second 
    tells SDL to try to use RLE acceleration - which basically tries to make the drawing faster. The third 
    argument is a little bit more complex; here, SDL_MapRGB takes a color and matches it with the closest 
    color on that surface pallete.
    */
    SDL_SetColorKey(Surf_Dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Surf_Dest->format, R, G, B));
 
   // ADDITION - this must be included to make transparency work when using IMG_Load instead of SDL_LoadBMP
   SDL_SetAlpha(Surf_Dest, SDL_RLEACCEL, 255);

    return true;
}
