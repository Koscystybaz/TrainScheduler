#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
	SDL_Surface* temSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Renderer::renderer, temSurface);
	SDL_FreeSurface(temSurface);

	return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Renderer::renderer, tex, &src, &dest);
}