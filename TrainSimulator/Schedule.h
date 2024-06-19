#pragma once

#include <map>
#include <vector>
#include "Vector2D.h"
#include "RouteManager.h"

/**
*@brief Klasa zawierjaca trasy, punkty stacji oraz obliczanie tras
*@param stations mapa stacji
*@param stations mapa tras
*/
class Schedule
{
private:
	typedef std::map<char, Vector2D> Stations;
	static Stations stations;

	typedef std::map<std::string, std::string> Routes;
	static Routes routes;

public:
	
	/**
	*@brief Metoda znajdujaca trase
	*@param connection stacja docelowa pociagu 
	*/
	static std::string GetFromConnectionMap(std::string connection);

	/**
	*@brief Metoda znajdujaca stacje
	*@param station nazwa stacji 
	*/
	static Vector2D GetStationPosition(char station);
};