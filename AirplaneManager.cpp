#include "AirplaneManager.hpp"

AirplaneManager::AirplaneManager()
{

}

void AirplaneManager::addAirplane(Airplane airplane)
{
    airplanes.push_back(airplane);
}

void AirplaneManager::addAirplaneClass(AirplaneClass airplaneClass)
{
    airplaneClasses.push_back(airplaneClass);
}

std::vector<Airplane> AirplaneManager::getAirplanes()
{
    return airplanes;
}

std::vector<AirplaneClass> AirplaneManager::getAirplaneClasses()
{
    return airplaneClasses;
}
