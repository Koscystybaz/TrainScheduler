#pragma once

#include "SDL_image.h"
#include "Renderer.h"
#include "SDL.h"

/**
*@brief Klasa wczytujaca tekstury w programie
*/
class TextureManager
{
private:

public:
	/**
	*@brief Metoda wczytujaca teksture
	*@param filename sciezka pliku
	*/
	static SDL_Texture* LoadTexture(const char* filename);

	/**
	*@brief Metoda wczytujaca teksture
	*@param tex tekstura obiektu
	*@param src punkty poczatkowe od lewej gornej krawedzi na mapie na mapie
	*@param dest punkty koncowe od lewej gornej krawedzi na mapie na mapie
	*/
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};