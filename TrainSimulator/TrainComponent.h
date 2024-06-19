#pragma once
#include "Train.h"
#include "ECS/ECS.h"


/**
*@brief Klasa opakowujaca dla pociagu
*@param train wskaznik na obiekt pociagu
*@param entity komponenty dla obiektu pociagu
*/
class TrainComponent
{
public:
	Train* train;
	Entity& entity;

	TrainComponent(Train* train, Entity& entity);
};