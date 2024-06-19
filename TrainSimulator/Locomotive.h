#pragma once
#include "ITrain.h"


/**
*@brief Klasa opisujaca szczegolny typ pociagu
*/
class Locomotive : public ITrain
{
private:

public:
    Locomotive() {}
    /**
    *@brief Metoda wirtualna pobierajaca predkosc
    */
    virtual int GetSpeed() { return 5; }

    /**
    *@brief Metoda wirtualna pobierajaca teksture
    */
    virtual std::string GetTexture() { return "assets/Locomotive.png"; }
    
    /**
    *@brief Metoda zwracajaca referencje do obiektu
    */
    static ITrain* GetSingleton()
    {
        static Locomotive singleton;
        return &singleton;
    }
};