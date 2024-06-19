#pragma once
#include "ITrain.h"


/**
*@brief Klasa opisujaca szczegolny typ pociagu
*/
class TrainLocomotive : public ITrain
{
private:

public:
    TrainLocomotive() {}

    /**
    *@brief Metoda wirtualna pobierajaca predkosc
    */
    virtual int GetSpeed() { return 3; }
    
    /**
    *@brief Metoda wirtualna pobierajaca teksture
    */
    virtual std::string GetTexture() { return "assets/TrainLocomotive.png"; }

    /**
    *@brief Metoda zwracajaca referencje do obiektu
    */
    static ITrain* GetSingleton()
    {
        static TrainLocomotive singleton;
        return &singleton;
    }
};