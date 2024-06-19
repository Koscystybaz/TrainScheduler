#pragma once

#include "Vector2D.h"
#include "ECS/ECS.h"
#include "Schedule.h"
#include "TrainType.h"
#include "ITrain.h"
#include "ClassicTrain.h"
#include "Locomotive.h"
#include "TrainLocomotive.h"

/**
*@brief Klasa inicjalizujaca parametry pociagu poruszajacego sie po mapie
*@param trainStrategy interfejs odpowiadajacy za predkosc i teksture
*@param currentDest punkt do ktorego aktualnie zmierza pociag
*@param lastStation punkt ostatniej stacji w ktorej zanjdowal sie pociag
*@param startPosition punkt z ktorego startuje pociag
*@param currentDestinationIndex indeks aktualnej trasy
*@param speed predkosc pociagu
*@param connection punkt do ktorego zmierza pociag
*@param texture tekstura pociagu
*@param active zmienna odpowiadajaca za sprawdzenie czy obiekt pociagu jest aktywny
*/
class Train : public Entity {

private:
	ITrain* trainStrategy;

public:
	Vector2D currentDest;
	Vector2D lastStation;
	Vector2D startPosition;
	int currentDestinationIndex;
	int speed;
	std::string connection;
	std::string texture;
	bool active;

	/**
	*@brief Metoda tworzaca obiekt pociagu 
	*@param type zmienna wyliczeniowa odpowiadajaca za typ pociagu
	*@param trainLine punk docelowy pociagu
	*/
	Train(TrainType type, std::string trainLine);

	/**
	*@brief Metoda pobierajaca specjalny typ pociagu
	*@param type zmienna wyliczeniowa odpowiadajaca za typ pociagu
	*/
	void GetStrategy(TrainType type);
};