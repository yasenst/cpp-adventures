#include "Airplane.hpp"

Airplane::Airplane(std::string averageSpeed, std::string tankVolume,  std::string fuelConsumptionPerKm)
{
    setAverageSpeed(averageSpeed);
    setTankVolume(tankVolume);
    setFuelConsumptionPerKm(fuelConsumptionPerKm);
    this->id = (++count);
}

Airplane::Airplane(const Airplane &obj)
{
    id = obj.id;
    tankVolume = obj.tankVolume;
    averageSpeed = obj.averageSpeed;
    fuelConsumptionPerKm = obj.fuelConsumptionPerKm;
}

Airplane::~Airplane()
{
    //std::cout << "Deleting Airplane " << id << std::endl;
}


std::ostream& operator<<(std::ostream& stream, const Airplane& obj)
{
    stream << obj.id << " " << obj.classId << " " << obj.averageSpeed << " " << obj.tankVolume << " " << obj.fuelConsumptionPerKm << '\n';
    return stream;
}

int Airplane::count = 0;

int Airplane::getId() { return id; }

int Airplane::getClassId() { return classId; }

double Airplane::getFuelConsumption() const { return fuelConsumptionPerKm; }

int Airplane::getTankVolume() const { return tankVolume; }

int Airplane::getAverageSpeed() const { return averageSpeed; }

void Airplane::setCount(int c) { Airplane::count = c; }

void Airplane::setId(int id) { this->id = id; }

void Airplane::setClassId(int classId) { this->classId = classId; }

void Airplane::setFuelConsumptionPerKm(std::string fuelConsumptionPerKm)
{
    double fuelConsumptionPerKmToDouble;

    try {
        fuelConsumptionPerKmToDouble = std::stod(fuelConsumptionPerKm);
    } catch (const std::invalid_argument& ia) {
        throw "Fuel consumption must be a number!";
    }

    if (fuelConsumptionPerKmToDouble <= 0.0)
        throw "Fuel consumption must be a positive number!";

    this->fuelConsumptionPerKm = fuelConsumptionPerKmToDouble;
}

void Airplane::setTankVolume(std::string tankVolume)
{
    int tankVolumeToInt;

    try {
        tankVolumeToInt = std::stoi(tankVolume);
    } catch (const std::invalid_argument& ia) {
        throw "Tank volume must be an integer!";
    }

    if (tankVolumeToInt <= 0)
        throw "Tank volume must be a positive number!";

    this->tankVolume = tankVolumeToInt;
}

void Airplane::setAverageSpeed(std::string averageSpeed)
{
     int averageSpeedToInt;

    try {
        averageSpeedToInt = std::stoi(averageSpeed);
    } catch (const std::invalid_argument& ia) {
        throw "Average speed must be an integer!";
    }

    if (averageSpeedToInt <= 0)
        throw "Average speed must be a positive number!";

    this->averageSpeed = averageSpeedToInt;
}
