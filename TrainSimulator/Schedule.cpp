#include "Schedule.h"

Schedule::Stations Schedule::stations = 
{
	{ 'A',  Vector2D(46, 38)},
	{ 'B',  Vector2D(46, 86)},
	{ 'C',  Vector2D(46, 192)},
	{ 'D',  Vector2D(46, 302)},
	{ 'E',  Vector2D(46, 404)},
	{ 'F',  Vector2D(142, 86)},
	{ 'G',  Vector2D(142, 192)},
	{ 'H',  Vector2D(344, 38)},
	{ 'I',  Vector2D(344, 192)},
	{ 'J',  Vector2D(402, 192)},
	{ 'K',  Vector2D(402, 298)},
	{ 'L',  Vector2D(296, 298)},
	{ 'M',  Vector2D(296, 404)},
	{ 'N',  Vector2D(460, 298)},
	{ 'O',  Vector2D(460, 404)}
};

Schedule::Routes Schedule::routes =
{
	{ "AO", "AHIJKNO"},
	{ "BO", "BFGCDEMO"},
	{ "MG", "MLKJIG"},
	{ "IA", "IHA"},
	{ "JB", "JIGCB"},
	{ "FH", "FGIH"},
	{ "OJ", "OMLKJ"},
	{ "AI", "AHABFGI"},
};

std::string Schedule::GetFromConnectionMap(std::string connection)
{
	auto it = routes.find(connection);
	if (it != routes.end())
		return it->second;
	else
		std::cout << "No connection for " << connection << std::endl;
}

Vector2D Schedule::GetStationPosition(char station)
{
	auto it = stations.find(station);
	if (it != stations.end())
		return it->second;
	else
		std::cout << "No station for " << station << std::endl;
}