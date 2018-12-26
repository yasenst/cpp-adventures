#include "FlightManager.hpp"
#include "Airplane.hpp"

FlightManager::FlightManager()
{
    this->distance = 0.0;
}

FlightManager::FlightManager(double distance)
{
    this->distance = distance;
}

void FlightManager::setDistance(double distance)
{
    this->distance = distance;
}

void FlightManager::analyzeFlight(Airplane* airplane)
{
    if (isFlightPossible(airplane) == false)
        return;

    std::cout << *airplane << ", duration: " << calculateFlightDuration(airplane) << ", fuel to use: " << calculateFuelCost(airplane) << std::endl;
}

bool FlightManager::isFlightPossible(Airplane* airplane)
{
    double fuelAmountNeeded = calculateFuelCost(airplane);

    return (fuelAmountNeeded <= airplane->getTankVolume()) ? true : false;
}

double FlightManager::calculateFlightDuration(Airplane* airplane)
{
    return distance / airplane->getAverageSpeed();
}

double FlightManager::calculateFuelCost(Airplane* airplane)
{
    return distance * airplane->getFuelConsumption();
}
