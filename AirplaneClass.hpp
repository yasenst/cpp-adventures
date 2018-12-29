#include <string>
#include <vector>
#include "Airplane.hpp"

#ifndef AIRPLANECLASS_HPP
#define AIRPLANECLASS_HPP
class AirplaneClass
{

private:

    static int count;
    int id;
    std::string manufacturer;
    std::string model;
    int seats;
    int trackLength;
    std::vector<Airplane*> airplanes;

public:

    AirplaneClass();
    AirplaneClass(std::string, std::string, std::string, std::string);
    AirplaneClass(const AirplaneClass &obj);
    ~AirplaneClass();

    friend std::ostream& operator<<(std::ostream& stream, const AirplaneClass& obj);

    int getId();
    std::string getManufacturer() const;
    std::string getModel();
    int getSeats() const;
    int getTrackLength() const;
    std::vector<Airplane*> getAirplanes();

    void setId(int id);
    static void setCount(int c);
    void setManufacturer(std::string manufacturer);
    void setModel(std::string model);
    void setSeats(std::string seats);
    void setTrackLength(std::string trackLength);

    void addAirplane(Airplane* airplane);
    void showAirplanes();
};


#endif // AIRPLANECLASS_HPP

