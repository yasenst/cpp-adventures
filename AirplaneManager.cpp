#include "AirplaneManager.hpp"
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>

std::vector<AirplaneClass*> airplaneClasses;

AirplaneManager::AirplaneManager()
{

}

AirplaneManager::~AirplaneManager()
{
    //std::cout << "Entering AirplaneManager destructor." << std::endl;
    for(uint32_t i = 0; i < airplaneClasses.size(); i++)
    {
       delete airplaneClasses[i];
       //std::cout << "Deleted AirplaneClass." << std::endl;
    }
    //std::cout << "Leaving AirplaneManager destructor." << std::endl;
}

void AirplaneManager::addAirplane()
{
    std::cout << "Available Airplane classes: " << std::endl;

    showAirplaneClasses();

    std::string classId;
    std::cout << "Choose class id: ";
    std::cin >> classId;

    int classIdToInt;
    try {
        classIdToInt = std::stoi(classId);
    } catch (const std::invalid_argument& ia) {
        throw "Class ID should be an integer!";
    }

    if (!airplaneClassIdExists(classIdToInt))
        throw "No such class ID!";

    std::string averageSpeed;
    std::string tankVolume;
    std::string fuelConsumptionPerKm;

    std::cout << "Average speed(km/h): ";
    std::cin >> averageSpeed;
    std::cout << "Tank volume(litres): ";
    std::cin >> tankVolume;
    std::cout << "Fuel consumption(litre per km): ";
    std::cin >> fuelConsumptionPerKm;

    Airplane* airplane = new Airplane(averageSpeed, tankVolume, fuelConsumptionPerKm);
    airplane->setClassId(classIdToInt);

    addAirplaneByClassId(airplane, classIdToInt);
}

bool AirplaneManager::airplaneClassIdExists(int id)
{
    for (AirplaneClass* a : airplaneClasses)
    {
        if (a->getId() == id)
        {
            return true;
        }
    }
    return false;
}

void AirplaneManager::addAirplaneByClassId(Airplane *airplane, int id)
{
    for (AirplaneClass *a : airplaneClasses)
    {
        if (a->getId() == id)
        {
            a->addAirplane(airplane);
        }
    }
}

void AirplaneManager::addAirplaneClass()
{
    std::string manufacturer;
    std::string model;
    std::string seats;
    std::string trackLength;

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
        std::cout << "ID #" << *(*it);
    }
}

void AirplaneManager::loadAirplaneClasses()
{
    std::ifstream in("airplaneClasses.txt");

    int id;
    std::string manufacturer, model, seats, trackLength;

    while (in >> id >> manufacturer >> model >> seats >> trackLength)
    {
        AirplaneClass* airplaneClass = new AirplaneClass(manufacturer, model, seats, trackLength);
        airplaneClass->setId(id);
        airplaneClasses.push_back(airplaneClass);
        AirplaneClass::setCount(airplaneClasses.size());
    }

    in.close();
}

void AirplaneManager::loadAirplanes()
{
    std::ifstream in("airplanes.txt");

    int id, classId;
    std::string averageSpeed, tankVolume, fuelConsumptionPerKm;

    int count = 0;
    while (in >> id >> classId >> averageSpeed >> tankVolume >> fuelConsumptionPerKm)
    {
        Airplane *airplane = new Airplane(averageSpeed, tankVolume, fuelConsumptionPerKm);
        airplane->setId(id);
        airplane->setClassId(classId);

        for (AirplaneClass *airplaneClass : airplaneClasses)
        {
            if (airplaneClass->getId() == airplane->getClassId())
            {
                airplaneClass->addAirplane(airplane);
                count++;
                break;
            }
        }

    }
    Airplane::setCount(count);

    in.close();
}

void AirplaneManager::saveAirplanes()
{
    std::ofstream out1, out2;

    out1.open("airplaneClasses.txt");
    out2.open("airplanes.txt");

    for (AirplaneClass *airplaneClass : airplaneClasses)
    {
        out1 << *airplaneClass;
        for (Airplane *airplane : airplaneClass->getAirplanes())
        {
            out2 << *airplane;
        }
    }

    out1.close();
    out2.close();
}
