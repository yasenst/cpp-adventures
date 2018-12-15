#include <string>
#include <iostream>
#include "AirplaneClass.hpp"


#ifndef AIRPLANE_HPP
#define AIRPLANE_HPP
class Airplane
{

private:

    static int count;
    int id;
    AirplaneClass airplaneClass;
    int averageSpeed;
    int tankVolume;
    double fuelConsumptionPerKm;

public:

    Airplane(AirplaneClass airplaneClass, int averageSpeed, int tankVolume, double fuelConsumptionPerKm);
    Airplane(const Airplane &obj);

    friend std::ostream &operator<<(std::ostream& stream, const Airplane& obj);

    int getId();
    AirplaneClass getAirplaneClass();
    double getFuelConsumption() const;
    int getTankVolume() const;
    int getAverageSpeed() const;

    void setFuelConsumptionPerKm(double fuelConsumption);
    void setTankVolume(int tankVolume);
    void setAverageSpeed(int averageSpeed);
};

#endif // AIRPLANE_HPP
