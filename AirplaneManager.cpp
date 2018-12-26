#include "AirplaneManager.hpp"
#include<vector>

//std::vector<Airplane> airplanes;
std::vector<AirplaneClass*> airplaneClasses;

AirplaneManager::AirplaneManager()
{
std::cout << "created managers" << std::endl;
}

AirplaneManager::~AirplaneManager()
{
     for(int i = 0; i < airplaneClasses.size(); i++)
    {
       delete airplaneClasses[i];
       std::cout << "destructor invoked" << std::endl;
    }
}
/*
void AirplaneManager::addAirplane()
{
    std::cout << "Available Airplane classes: " << std::endl;

    showAirplaneClasses();

    int classId;
    std::cout << "Choose class id: ";
    std::cin >> classId;

    int averageSpeed;
    int tankVolume;
    double fuelConsumptionPerKm;

    std::cout << "Average speed: ";
    std::cin >> averageSpeed;
    std::cout << "Tank volume: ";
    std::cin >> tankVolume;
    std::cout << "Fuel consumption per km: ";
    std::cin >> fuelConsumptionPerKm;

    Airplane airplane(averageSpeed, tankVolume, fuelConsumptionPerKm);

    for (AirplaneClass a : airplaneClasses)
    {
        if (a.getId() == classId)
        {
            a.addAirplane(airplane);
            std::cout << a.getAirplanes().size();
        }
    }
}
*/


void AirplaneManager::addAirplaneClass(AirplaneClass* airplaneClass)
{

    airplaneClasses.push_back(airplaneClass);
}

std::vector<AirplaneClass*> AirplaneManager::getAirplaneClasses()
{
    return airplaneClasses;
}


void AirplaneManager::showAirplaneClasses()
{
    for(std::vector<AirplaneClass*>::iterator it = airplaneClasses.begin(); it != airplaneClasses.end(); ++it)
    {
        std::cout << *(*it) << std::endl;
    }
}

