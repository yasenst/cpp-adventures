#include "AirplaneManager.hpp"
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>

//std::vector<Airplane> airplanes;
std::vector<AirplaneClass*> airplaneClasses;

AirplaneManager::AirplaneManager()
{
    std::cout << "created manager" << std::endl;

    /*
    while (std::getline(in, line))
    {

        std::stringstream ss(line);
        std::string token;
        while(std::getline(ss, token, ';'))
        {
            std::cout << token << std::endl;
        }

        std::stringstream ss(line);

    }
    */
}

AirplaneManager::~AirplaneManager()
{
    std::cout << "Entering AirplaneManager destructor." << std::endl;
    //writeAirplanes(std::ofstream{"myFilename"}, airplaneClasses);
    std::ofstream out("saved.txt");
     for(uint32_t i = 0; i < airplaneClasses.size(); i++)
    {
        out << *airplaneClasses[i];
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
    airplane->setClassId(classId);

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

void AirplaneManager::writeAirplanes(std::ostream& o, const std::vector<AirplaneClass*>& AirplaneClassToBeWritten)
{
    for (auto a : AirplaneClassToBeWritten)
    {
        o << a->getId() << ";" << a->getManufacturer() << ";" << a->getModel() << ";" << a->getSeats() << ";" << a->getTrackLength();
        for (auto b : a->getAirplanes())
        {

        }
    }
}

void AirplaneManager::writeAirplanes(std::ostream&& o, const std::vector<AirplaneClass*>& AirplaneClassToBeWritten)
{
    writeAirplanes(o, AirplaneClassToBeWritten);
}
/*
void writeStudents(std::ostream& o, const std::vector<Student*>& students) {
    for(auto s: students) {
        o << s->name << ';' << s->age << '\n';
    }
}
void writeStudents(std::ostream&& o, const std::vector<Student*>& students) {
    writeStudents(o, students);
}

*/

void AirplaneManager::loadAirplaneClasses()
{
    std::ifstream in("saved.txt");

    int id, seats, trackLength;
    std::string manufacturer, model;

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

    int id, classId, averageSpeed, tankVolume, fuelConsumptionPerKm;

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
