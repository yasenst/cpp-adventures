#include "FlightManager.hpp"
#include "Airplane.hpp"

FlightManager::FlightManager() {}

void FlightManager::setDistance(double distance)
{
    this->distance = distance;
}

void FlightManager::analyzeFlight(const Airplane& airplane)
{
    if (isFlightPossible(airplane) == false)
        return;

    std::cout << airplane << ", duration: " << calculateFlightDuration(airplane) << ", fuel to use: " << calculateFuelCost(airplane);
}

bool FlightManager::isFlightPossible(const Airplane& airplane)
{
    double fuelAmountNeeded = calculateFuelCost(airplane);

    return (fuelAmountNeeded <= airplane.getTankVolume()) ? true : false;
}

double FlightManager::calculateFlightDuration(const Airplane& airplane)
{
    return distance / airplane.getAverageSpeed();
}

double FlightManager::calculateFuelCost(const Airplane& airplane)
{
    return distance * airplane.getFuelConsumption();
}
