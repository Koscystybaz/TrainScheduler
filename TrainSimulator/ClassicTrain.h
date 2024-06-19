#pragma once
#include "ITrain.h"

/**
*@brief Klasa opisujaca szczegolny typ pociagu
*/
class ClassicTrain : public ITrain
{
private:

public:
    ClassicTrain() {}
    /**
    *@brief Metoda wirtualna pobierajaca predkosc
    */
	virtual int GetSpeed() { return 10; }

    /**
    *@brief Metoda wirtualna pobierajaca teksture
    */
    virtual std::string GetTexture() { return "assets/Train.png"; }
    
    /**
    *@brief Metoda zwracajaca referencje do obiektu
    */
    static ITrain* GetSingleton()
    {
        static ClassicTrain singleton;
        return &singleton;
    }
};