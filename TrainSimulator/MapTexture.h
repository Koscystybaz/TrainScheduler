#pragma once

#include "SDL.h"
#include "TextureManager.h"

/**
*@brief Klasa odpowiadajaca za mape
*@param xpose punkt w osi poziomej
*@param ypose punkt w osi pionowej
*@param objTexture textura mapy
*@param srcRect punkty poczatkowe od lewej gornej krawedzi na mapie na mapie
*@param destRect punkty koncowe od lewej gornej krawedzi na mapie na mapie
*/
class MapTexture
{
private:
	int xpose;
	int ypose;
	SDL_Texture* objTexture;
	SDL_Rect srcRect; 
	SDL_Rect destRect;

public:
	MapTexture(const char* texturesheet, int x, int y);
	~MapTexture();

	/**
	*@brief Metoda renderujaca
	*/ 
	void Render();
};