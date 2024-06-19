#pragma once
#include "Components.h"
#include "../Vector2D.h"


/**
*@brief 
*@param position pozycja obiektu na mapie
*/
class TransformComponent : public Component
{
private:

public:

	Vector2D position;

	TransformComponent()
	{
		position.x = 0.0;
		position.y = 0.0;
	};

	TransformComponent(float x, float y)
	{
		position.x = x;
		position.y = y;
	}
};