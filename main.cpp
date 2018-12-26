#include <iostream>
#include <stdlib.h>
#include <vector>
#include "AirplaneManager.hpp"
#include "AirplaneClass.hpp"
#include "FlightManager.hpp"
#include "Airplane.hpp"

using namespace std;

int main()
{

    AirplaneManager* airplaneManager = new AirplaneManager();
    FlightManager flightManager;
    /*
    AirplaneClass a("Airbus", "a380", 125, 600);
    Airplane* plane2 = new Airplane(290,1400,45.5);
    Airplane plane(290,1400,45.5);
    a.addAirplane(&plane);
    */


    int choice;

    do {
        //system("cls");

        cout << "1. Add class" << endl;
        cout << "2. Add airplane" << endl;
        cout << "3. Search airplanes" << endl;
        std::cout << "4. Quit" << std::endl;

        do {
            cout << "Enter number of choice: " << endl;
            cin >> choice;
        } while (choice < 1 || choice > 4);

        switch (choice) {
        case 1:
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
            airplaneManager->addAirplaneClass(airplaneClass);
            }


            std::cout << "Size of vector of AirplaneClass-es: " << airplaneManager->getAirplaneClasses().size() << std::endl;
            airplaneManager->showAirplaneClasses();
            break;
        case 2:
            //airplaneManager.addAirplane();
            break;
        case 3:
            double distance;
            std::cout << "Distance: ";
            std::cin >> distance;
            flightManager.setDistance(distance);
            //airplaneManager.showAirplaneClasses();
            /*
            for (AirplaneClass airplaneClass : airplaneManager.getAirplaneClasses())
            {
                std::cout << airplaneClass.getAirplanes().size();
               //std::cout << airplaneClass.getAirplanes();
              for (Airplane air : airplaneClass.getAirplanes())
              {
                  std::cout << "KUR" << std::endl;
              }

            }
            */
            break;
        case 4:cout << "BYE" << endl;
        default:
            std::cout << "Invoked default case"<< std::endl;
            delete airplaneManager;
            exit(0);
        }

        system("pause");
    } while (choice != 4);




    return 0;
}

