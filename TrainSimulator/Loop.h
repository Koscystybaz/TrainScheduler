#pragma once

#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>

#include "MapTexture.h"
#include "ECS/Components.h"
#include "Train.h"
#include "Schedule.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Vector2D.h"
#include "Renderer.h"
#include "TrainComponent.h"


/**
*@brief Klasa odpowiadajaca za dzialanie programu w petli
*@param isRunning zmienna stanu petli
*@param window okno programu
*@param map mapa po ktorej poruszaja sie obiekty
*@param manager zmienna odpowiadajaca za odswiezanie obiektow
*@param schedule zmienna zawierajaca trasy oraz punkty stacji
*@param trains wektor obiektow pociagu
*/
class Loop {

private:
	bool isRunning;
	SDL_Window* window;
	MapTexture* map;

	Manager manager;
	Schedule schedule;

	std::vector<TrainComponent> trains;

public:
	Loop();
	~Loop();

	/**
	*@brief Metoda inicjalizujaca okno programu
	*@param title nazwa okna
	*@param xpos pozycja w osi x
	*@param ypos pozycja w osi y
	*@param width szerokosc okna
	*@param height wysokosc okna
	*@param fullscreen zmienna odpowiadajaca za pelny ekran
	*/
	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	/**
	*@brief Metoda odpowiadajaca za reagowanie na dzialanie eventow
	*/
	void HandleEvents();

	/**
	*@brief Metoda odswiezajaca
	*/
	void Uptade();

	/**
	*@brief Metoda renderujaca
	*/
	void Render();
	/**
	*@brief Metoda odswiezajaca
	*/
	void Clean();

	/**
	*@brief Metoda odpowiadajaca za stan petli
	*/
	bool Running() { return isRunning; };

	/**
	*@brief Metoda dodajaca obiekt pociagu na mape
	*@param type szczegolny typ pociagu
	*@param stacja docelowa
	*/
	void AddTrain(TrainType type, std::string connection);
};