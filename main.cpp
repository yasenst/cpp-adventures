#include <iostream>
//#include <stdlib.h>
//#include <vector>
//#include <string>
#include <cstdlib>
#include "AirplaneManager.hpp"
#include "AirplaneClass.hpp"
#include "FlightManager.hpp"
#include "Airplane.hpp"


int main()
{

    AirplaneManager* airplaneManager = new AirplaneManager();
    airplaneManager->loadAirplaneClasses();
    airplaneManager->loadAirplanes();

    std::string input;
    int choice;

    do {
        system("cls");

        std::cout << "1. Add class" << std::endl;
        std::cout << "2. Add airplane" << std::endl;
        std::cout << "3. Search airplanes" << std::endl;
        std::cout << "4. Save and Quit" << std::endl;

        do {
            std::cout << "Enter number of choice: " << std::endl;
            std::cin >> input;
            try {
                choice = std::stoi(input);
            } catch (const std::invalid_argument& ia) {
                std::cerr << "No such option! ";
            }

        } while (choice < 1 || choice > 4);

        switch (choice) {
        case 1:
            try {
                airplaneManager->addAirplaneClass();
            } catch (const char* msg) {
                std::cerr << msg << " Airplane Class not created." << std::endl;
            }
            break;
        case 2:
            try {
                airplaneManager->addAirplane();
            } catch (const char* msg) {
                std::cerr << msg << " Airplane not created." << std::endl;
            }

            break;
        case 3:
            {
                std::string distance;
                std::cout << "Distance(in km): ";
                std::cin >> distance;

                double distanceToDouble;

                try {
                    distanceToDouble = std::stod(distance);
                } catch (const std::invalid_argument& ia) {
                    std::cerr << "Distance must be a number!" << '\n';
                    break;
                }

                FlightManager flightManager(distanceToDouble);

                std::cout << "Airplanes, and their corresponding class, which can travel " << distanceToDouble << " km:" << std::endl;

                for (AirplaneClass *airplaneClass : airplaneManager->getAirplaneClasses())
                {
                    std::cout << "Class " << airplaneClass->getManufacturer() << " " << airplaneClass->getModel() << ":" << std::endl;
                    for (Airplane *airplane : airplaneClass->getAirplanes())
                    {
                        flightManager.analyzeFlight(airplane);
                    }
                }
            }
            break;
        case 4:
            std::cout << "BYE" << std::endl;
        default:
            airplaneManager->saveAirplanes();
            delete airplaneManager;
            exit(0);
        }

        system("pause");
    } while (choice != 4);

    return 0;
}

