#pragma once 

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

/**
*@brief Tworzenie klas bez definicji
*/
class Component;
class Entity;

/**
*@brief ID obiektu
*/
using ComponentID = std::size_t;

/**
*@brief Wstawianie ID obiektu w wybrane miejsce
*/
inline ComponentID getComponentTypeID()
{
	static ComponentID lastID = 0;
	return lastID++;
}


/**
*@brief Szablon do pobierania ID obiektu
*/
template <typename T> inline ComponentID getComponentTypeID() noexcept
{
	static ComponentID typeID = getComponentTypeID();
	return typeID;
}

/**
*@brief Maksymalna liczba obiektow w programie
*/
constexpr std::size_t maxComponents = 32;
using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;


/**
*@brief Klasa wirtualna do tworzenia komponentow
*/
class Component
{
private:

public:
	Entity* entity;

	virtual void init() {}
	virtual void uptade() {}
	virtual void draw() {}

	virtual ~Component() {}
};

/**
*@brief Klasa wirtualna do tworzenia komponentow
*@param active zmienna odpowiadajaca za okreslenie stanu
*@param components wektor komponentow z dynamiczna wielkoscia
*@param componentArray kontener na komponenty
*@param componentBitSet kontener na sekwencje bitow komponentow
*/
class Entity
{
private:

	bool active = true;
	std::vector<std::unique_ptr<Component>> components;
	ComponentArray componentArray;
	ComponentBitSet componentBitSet;

public:
	
	/**
	*@brief Metoda odswiezajaca 
	*/
	void uptade()
	{
		for (auto& c : components) c->uptade();
		
	}

	/**
	*@brief Metoda renderujaca
	*/
	void draw() 
	{
		for (auto& c : components) c->draw();
	}

	/**
	*@brief Metoda okreslajaca stan
	*/
	bool isActive() const { return active; }

	/**
	*@brief Metoda okreslajaca stan 
	*/
	void destroy() { active = false; }

	/**
	*@brief Szablon do sprawdzenia czy dany obiekt posiada juz komponent
	*/
	template <typename T> bool hasComponent() const
	{
		return componentBitSet[getComponentTypeID<T>];
	}

	/**
	*@brief Szablon do dodwania do obiektu danego komponentu
	*/
	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs)
	{
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));
		componentArray[getComponentTypeID<T>()] = c;
		componentBitSet[getComponentTypeID<T>()] = true;

		c->init();
		return *c;
	}

	/**
	*@brief Szablon do pobierania z obiektu danego komponentu
	*/
	template<typename T> T& getComponent() const
	{
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}
};

/**
*@brief Klasa
*@param entities 
*/
class Manager
{
private:

	std::vector<std::unique_ptr<Entity>> entities;

public:

	/**
	*@brief Metoda odswiezajaca
	*/
	void uptade()
	{
		for (auto& e : entities) e->uptade();
	}

	/**
	*@brief Metoda renderujaca
	*/
	void draw()
	{
		for (auto& e : entities) e->draw();
	}

	/**
	*@brief Metoda odswiezajaca
	*/
	void refresh()
	{
		auto removeFunction = std::remove_if(std::begin(entities), std::end(entities),
			[](const std::unique_ptr<Entity>& mEntity)
			{
				return !mEntity->isActive();
			});

		entities.erase(removeFunction, std::cend(entities));
	}

	/**
	*@brief Metoda rejesturaca komponenty
	*/
	Entity& addEntity()
	{
		Entity* e = new Entity();
		std::unique_ptr<Entity> uPtr{ e };
		entities.emplace_back(std::move(uPtr));
		return *e;
	}
};