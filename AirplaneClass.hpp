#include <string>

#ifndef AIRPLANECLASS_HPP
#define AIRPLANECLASS_HPP
class AirplaneClass
{

private:

    std::string manufacturer;
    std::string model;
    int seats;
    int trackLength;

public:

    AirplaneClass();
    AirplaneClass(std::string, std::string, int, int);
    AirplaneClass(const AirplaneClass &obj);

    std::string getManufacturer() const;
    std::string getModel() const;
    int getSeats() const;
    int getTrackLength() const;

    void setManufacturer(std::string manufacturer);
    void setModel(std::string model);
    void setSeats(int seats);
    void setTrackLength(int trackLength);
};


#endif // AIRPLANECLASS_HPP

