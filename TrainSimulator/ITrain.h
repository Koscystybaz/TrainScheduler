#pragma once
#include <string>

/**
*@brief Interfejs odpowiadajacy za przypisywanie tekstury i obliczanie predkosci - Polimorfizm
*/
class ITrain
{
public:
	virtual ~ITrain() {};
	/**
	*@brief Metoda wirtualna pobierajaca teksture
	*/
	virtual int GetSpeed() = 0;

	/**
	*@brief Metoda wirtualna pobierajaca teksture
	*/
	virtual std::string GetTexture() = 0;
};