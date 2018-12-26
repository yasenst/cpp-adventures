#include "Airplane.hpp"
//#include "AirplaneClass.hpp"

Airplane::Airplane(int averageSpeed, int tankVolume,  double fuelConsumptionPerKm)
{
    this->id = (++count);
    this->averageSpeed = averageSpeed;
    this->tankVolume = tankVolume;
    this->fuelConsumptionPerKm = fuelConsumptionPerKm;
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
    std::cout << "Deleting Airplane " << id << std::endl;
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

void Airplane::setFuelConsumptionPerKm(double fuelConsumptionPerKm) { this->fuelConsumptionPerKm = fuelConsumptionPerKm; }

void Airplane::setTankVolume(int tankVolume) { this->tankVolume = tankVolume; }

void Airplane::setAverageSpeed(int averageSpeed) { this->averageSpeed = averageSpeed; }
