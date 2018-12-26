#include "AirplaneManager.hpp"
#include<vector>

//std::vector<Airplane> airplanes;
std::vector<AirplaneClass*> airplaneClasses;

AirplaneManager::AirplaneManager()
{
std::cout << "created manager" << std::endl;
}

AirplaneManager::~AirplaneManager()
{
    std::cout << "Entering AirplaneManager destructor." << std::endl;
     for(uint32_t i = 0; i < airplaneClasses.size(); i++)
    {
       delete airplaneClasses[i];
       std::cout << "Deleted AirplaneClass." << std::endl;
    }
    std::cout << "Leaving AirplaneManager destructor." << std::endl;
}

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

    Airplane* airplane = new Airplane(averageSpeed, tankVolume, fuelConsumptionPerKm);

    for (AirplaneClass* a : airplaneClasses)
    {
        if (a->getId() == classId)
        {
            a->addAirplane(airplane);
            std::cout << "Size of vector of airplanes  " << a->getAirplanes().size() << std::endl;
        }
    }


}



void AirplaneManager::addAirplaneClass()
{
            std::string manufacturer;
            std::string model;
            int seats;
            int trackLength;

            std::cout << "Manufacturer: ";
            std::cin >> std::ws;
            std::getline(std::cin, manufacturer);
            std::cout << "Model: ";
            std::cin >> model;
            std::cout << "Number of seats: ";
            std::cin >> seats;
            std::cout << "Track length: ";
            std::cin >> trackLength;

            AirplaneClass* airplaneClass = new AirplaneClass(manufacturer, model, seats, trackLength);
            //airplaneManager->addAirplaneClass(airplaneClass);

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

