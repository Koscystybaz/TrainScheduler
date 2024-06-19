#pragma once

#include "Vector2D.h"

/**
*@brief Klasa odpowiadajaca za wytyczanie tras oraz poruszanie sie
*/
class RouteManager
{
private:

public:
	
	/**
	*@brief Metoda obliczajaca predkosc
	*@param route trasa pociagu
	*@param velocity predkosc pociagu
	*/
	static Vector2D CalculateIncrement(Vector2D route, int velocity);

	/**
	*@brief Metoda obliczajaca trase
	*@param start punkt poczatkawy
	*@param end punkt koncowy
	*/
	static Vector2D CalculateRoute(Vector2D start, Vector2D end);

	/**
	*@brief Metoda obliczajaca predkosc
	*@param route trasa pociagu
	*@param velocity predkosc pociagu
	*/
	static Vector2D DivideVectorByNumber(Vector2D route, float velocity);

	/**
	*@brief Metoda zaokraglajaca punkt do calosci
	*@param pos punkt zaokraglany
	*/
	static Vector2D Round(Vector2D pos);
};