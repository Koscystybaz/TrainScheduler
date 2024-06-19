#include "Vector2D.h"


Vector2D::Vector2D()
{
	x = 0.0;
	y = 0.0;
}

Vector2D::Vector2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

int Vector2D::Distance()
{
	return sqrt((x * x) + (y * y));
}

Vector2D& Vector2D::Add(const Vector2D& v1)
{
	this->x += v1.x;
	this->y += v1.y;

	return *this;
}

Vector2D& Vector2D::Subtract(const Vector2D& v1)
{
	this->x -= v1.x;
	this->y -= v1.y;

	return *this;
}


auto Vector2D::operator<=>(const Vector2D& v1) const
{
		return(x == v1.x)
		? y <=> v1.y
		: x <=> v1.x;
}

bool Vector2D::operator==(Vector2D& v1)
{
	return (x == v1.x && y == v1.y);
}

bool Vector2D::operator!=(Vector2D& v1)
{
	return (x != v1.x && y != v1.y);
}

bool Vector2D::operator<=(Vector2D& v1)
{
	return (x <= v1.x);
}

bool Vector2D::operator>=(Vector2D& v1)
{
	return (x >= v1.x);
}

bool Vector2D::operator<(Vector2D& v1)
{
	return (x < v1.x);
}

bool Vector2D::operator>(Vector2D& v1)
{
	return (x > v1.x);
}