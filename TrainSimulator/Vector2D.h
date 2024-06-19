#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <compare>


/**
*@brief Klasa zawierajaca polozenie punktu na mapie oraz operatory odpowiadajace za dzialania na tej klasie
*@param x pozycja pozioma na mapie
*@param y pozycja pozioma na mapie
*/
class Vector2D
{
private:

public:
	float x;
	float y;

	Vector2D();
	Vector2D(float x, float y);
	/**
	*@brief Metoda obliczajaca dlugosc odcinka
	*/
	int Distance();

	/**
	*@brief Metoda odpowiadajaca za dodawanie wartosci
	*@param vec wartosc punktu wektora jaka ma zostac dodana
	*/
	Vector2D& Add(const Vector2D& v1);

	/**
	*@brief Metoda odpowiadajaca za odejmowanie wartosci
	*@param vec wartosc punktu wektora jaka ma zostac odjeta
	*/
	Vector2D& Subtract(const Vector2D& v1);

	/**
	*@brief operator porownania trojstronnego
	*@param v1 wektor wzgledem ktorego wykonujemy porownanie
	*/
	auto operator<=>(const Vector2D& v1) const;

	/**
	*@brief operator porownania
	*@param v1 wektor wzgledem ktorego wykonujemy porownanie
	*/
	bool operator==(Vector2D& v1);

	/**
	*@brief operator porownania
	*@param v1 wektor wzgledem ktorego wykonujemy porownanie
	*/
	bool operator!=(Vector2D& v1);

	/**
	*@brief operator porownania 
	*@param v1 wektor wzgledem ktorego wykonujemy porownanie
	*/
	bool operator<=(Vector2D& v1);

	/**
	*@brief operator porownania 
	*@param v1 wektor wzgledem ktorego wykonujemy porownanie
	*/
	bool operator>=(Vector2D& v1);

	/**
	*@brief operator porownania 
	*@param v1 wektor wzgledem ktorego wykonujemy porownanie
	*/
	bool operator<(Vector2D& v1);

	/**
	*@brief operator porownania  
	*@param v1 wektor wzgledem ktorego wykonujemy porownanie
	*/
	bool operator>(Vector2D& v1);
};