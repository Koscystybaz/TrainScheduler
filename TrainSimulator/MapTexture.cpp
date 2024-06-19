#include "MapTexture.h"


MapTexture::MapTexture(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	
	xpose = x;
	ypose = y;

	srcRect.h = 512;
	srcRect.w = 512;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = 512;
	destRect.w = 512;
}

MapTexture::~MapTexture()
{

}

void MapTexture::Render()
{
	SDL_RenderCopy(Renderer::renderer, objTexture, &srcRect, &destRect);
}