#include "RouteManager.h"

Vector2D RouteManager::CalculateIncrement(Vector2D route, int velocity)
{
	return DivideVectorByNumber(route, 10/velocity);
}

Vector2D RouteManager::DivideVectorByNumber(Vector2D route, float velocity)
{
	return Vector2D(route.x / (velocity * route.Distance()), route.y / (velocity * route.Distance()));
}

Vector2D RouteManager::Round(Vector2D pos)
{
	return Vector2D(round(pos.x), round(pos.y));
}

Vector2D RouteManager::CalculateRoute(Vector2D start, Vector2D end)
{
	return Vector2D(end.Subtract(start));
}