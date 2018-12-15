#include <iostream>
#include <stdlib.h>
#include <vector>
#include "AirplaneManager.hpp"
#include "AirplaneClass.hpp"

using namespace std;

int main()
{
    AirplaneManager airplaneManager;
    AirplaneClass a("Airbus", "a380", 125, 600);
    Airplane plane(a,290,1400,45.5);

    int choice;

    do {
        system("cls");

        cout << "1. Add airplane" << endl;
        cout << "2. Add class" << endl;
        cout << "3. Quit" << endl;

        do {
            cout << "Enter number of choice: " << endl;
            cin >> choice;
        } while (choice < 1 || choice > 3);

        switch (choice) {
        case 1: cout << plane << endl;
        case 2: break;
        case 3:cout << "BYE" << endl;
        default:
            exit(0);
        }

        system("pause");
    } while (choice != 5);




    return 0;
}

