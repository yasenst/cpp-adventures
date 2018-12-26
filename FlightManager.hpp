#include "Airplane.hpp"
#ifndef FLIGHTMANAGER_HPP
#define FLIGHTMANAGER_HPP
class FlightManager
{
private:
    double distance;
public:
    FlightManager();
    FlightManager(double distance);
    void setDistance(double distance);
    void analyzeFlight(Airplane* airplane);
    bool isFlightPossible(Airplane* airplane);
    double calculateFlightDuration(Airplane* airplane);
    double calculateFuelCost(Airplane* airplane);
};
#endif // FLIGHTMANAGER_HPP
