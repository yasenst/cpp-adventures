#include "Airplane.hpp"
//#include "AirplaneClass.hpp"

Airplane::Airplane(AirplaneClass airplaneClass, int averageSpeed,int tankVolume,  double fuelConsumptionPerKm)
                    {
                        this->id = (count++);
                        this->airplaneClass = airplaneClass;
                        this->tankVolume = tankVolume;
                        this->averageSpeed = averageSpeed;
                        this->fuelConsumptionPerKm = fuelConsumptionPerKm;
                    }

Airplane::Airplane(const Airplane &obj)
{
    this->tankVolume = obj.tankVolume;
    this->averageSpeed = obj.averageSpeed;
    this->fuelConsumptionPerKm = obj.fuelConsumptionPerKm;
}


std::ostream& operator<<(std::ostream& stream, const Airplane& obj) {
    stream << "Airplane(Manufacturer: " << obj.airplaneClass.getManufacturer() << ", model: " << obj.airplaneClass.getModel()
      << ", seats: " << obj.airplaneClass.getSeats() << ", minimum track length: " << obj.airplaneClass.getTrackLength()
      << ", tank volume: " << obj.tankVolume << ", average speed " << obj.averageSpeed
    << ", fuel consumption per km: " << obj.fuelConsumptionPerKm << ")" << '\n';
    return stream;
}

int Airplane::count = 0;

double Airplane::getFuelConsumption() const { return fuelConsumptionPerKm; }

int Airplane::getTankVolume() const { return tankVolume; }

int Airplane::getAverageSpeed() const { return averageSpeed; }

AirplaneClass Airplane::getAirplaneClass() { return airplaneClass; }

void Airplane::setFuelConsumptionPerKm(double fuelConsumptionPerKm) { this->fuelConsumptionPerKm = fuelConsumptionPerKm; }

void Airplane::setTankVolume(int tankVolume) { this->tankVolume = tankVolume; }

void Airplane::setAverageSpeed(int averageSpeed) { this->averageSpeed = averageSpeed; }
