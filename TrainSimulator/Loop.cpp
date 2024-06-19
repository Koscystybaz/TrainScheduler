#include "Loop.h"

Loop::Loop()
{

}

Loop::~Loop()
{

}

void Loop::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Start" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created" << std::endl;
		}

		Renderer::renderer = SDL_CreateRenderer(window, -1, 0);
		if (Renderer::renderer)
		{
			SDL_SetRenderDrawColor(Renderer::renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}

		isRunning = true;
	}
	else isRunning = false;
	
	map = new MapTexture("assets/map.png", 0, 0);

	AddTrain( TrainType::ClassicTrain,"AO");
	AddTrain( TrainType::Locomotive, "BO");
	AddTrain( TrainType::TrainLocomotive,"MG");
	AddTrain( TrainType::ClassicTrain,"IA");
	AddTrain( TrainType::Locomotive,"JB");
	AddTrain( TrainType::TrainLocomotive,"FH");
	AddTrain( TrainType::Locomotive,"OJ");
}

void Loop::AddTrain(TrainType type, std::string connection)
{
	auto newTrain = new Train(type, connection);
	auto& newTrainEntity(manager.addEntity());
	newTrainEntity.addComponent<TransformComponent>(newTrain->startPosition.x, newTrain->startPosition.y);
	const char* textureFileName = newTrain->texture.c_str();
	newTrainEntity.addComponent<SpriteComponent>(textureFileName);
	TrainComponent trainComponent = TrainComponent(newTrain, newTrainEntity);
	trains.push_back(trainComponent);
}

void Loop::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;

		default:
			break;
	}
}

void Loop::Uptade()
{
	manager.refresh();
	manager.uptade();

	for (TrainComponent& trainComponent : trains) {
		if (trainComponent.train->active)
		{
			auto routeDirection = RouteManager::CalculateRoute(
				Schedule::GetStationPosition(trainComponent.train->connection[trainComponent.train->currentDestinationIndex - 1]),
				Schedule::GetStationPosition(trainComponent.train->connection[trainComponent.train->currentDestinationIndex]));

			auto routeIncrement = RouteManager::CalculateIncrement(routeDirection, trainComponent.train->speed);

			trainComponent.entity.getComponent<TransformComponent>().position.Add(routeIncrement);

			auto currentposition = trainComponent.entity.getComponent<TransformComponent>().position;

			auto result = RouteManager::Round(currentposition);

			if (result == trainComponent.train->currentDest)
			{
				trainComponent.entity.getComponent<TransformComponent>().position = trainComponent.train->currentDest;
				if (result == trainComponent.train->lastStation)
				{
					trainComponent.entity.getComponent<TransformComponent>().position.Add(Vector2D(0, 0));
					trainComponent.entity.destroy();
					trainComponent.train->active = false;
				}
				else
				{
					trainComponent.train->currentDestinationIndex++;
					trainComponent.train->currentDest = Schedule::GetStationPosition(trainComponent.train->connection[trainComponent.train->currentDestinationIndex]);
				}
			}
		}
	}
}

void Loop::Render()
{
	SDL_RenderClear(Renderer::renderer);
	map->Render();
	
	manager.draw();
	SDL_RenderPresent(Renderer::renderer);
}

void Loop::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(Renderer::renderer);
	SDL_Quit();
	std::cout << "Loop cleaned" << std::endl;
}