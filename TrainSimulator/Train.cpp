#include "Train.h"

Train::Train(TrainType type , std::string trainLine) : Entity() , trainStrategy(nullptr)
{
	GetStrategy(type);
	speed = trainStrategy->GetSpeed();
	connection = Schedule::GetFromConnectionMap(trainLine);
	char firstStation = connection[0];
	startPosition = Schedule::GetStationPosition(firstStation);
	currentDestinationIndex = 1;
	currentDest = Schedule::GetStationPosition(connection[currentDestinationIndex]);
	lastStation = Schedule::GetStationPosition(connection.back());
	texture = trainStrategy->GetTexture();
	active = true;
}

void Train::GetStrategy(TrainType type)
{
	switch (type)
	{
	case TrainType::ClassicTrain:
		trainStrategy = ClassicTrain::GetSingleton();
		break;

	case TrainType::Locomotive:
		trainStrategy = Locomotive::GetSingleton();
		break;

	case TrainType::TrainLocomotive:
		trainStrategy = TrainLocomotive::GetSingleton();
		break;

	default:
		break;
	}
}