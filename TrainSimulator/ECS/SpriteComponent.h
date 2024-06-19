#pragma once

#include "Components.h"
#include "SDL.h"

/**
*@brief Klasa odpowiadajaca za przypisanie pozycji do komponentu
*@param transform wskaznik na obiekt klasy z pozycja
*@param texture tekstura
*@param srcRect punkty poczatkowe od lewej gornej krawedzi na mapie na mapie
*@param destRect punkty koncowe od lewej gornej krawedzi na mapie na mapie
*/
class SpriteComponent : public Component
{
private:

	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;

public:

	SpriteComponent() = default;
	SpriteComponent(const char* path) { setTex(path); }
	~SpriteComponent() {}

	/**
	*@brief Metoda wczytujaca tekture
	*@param path sciezka do pliku z tekstura 
	*/
	void setTex(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}

	/**
	*@brief Metoda nadpisana inicjalizujaca pozycje
	*/
	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 12;
		destRect.w = destRect.h = 8;
	}

	/**
	*@brief Metoda nadpisana odswizajaca
	*/
	void uptade() override
	{
		destRect.x = (int)transform->position.x;
		destRect.y = (int)transform->position.y;
	}

	/**
	*@brief Metoda renderujaca
	*/
	void draw()
	{
		TextureManager::Draw(texture, srcRect, destRect);
	}
};