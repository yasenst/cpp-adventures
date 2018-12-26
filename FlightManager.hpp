#include "Airplane.hpp"
#ifndef FLIGHTMANAGER_HPP
#define FLIGHTMANAGER_HPP
class FlightManager
{
private:
    double distance;
public:
    FlightManager();
    void setDistance(double distance);
    void analyzeFlight(const Airplane& airplane);
    bool isFlightPossible(const Airplane& airplane);
    double calculateFlightDuration(const Airplane& airplane);
    double calculateFuelCost(const Airplane& airplane);
};
#endif // FLIGHTMANAGER_HPP
