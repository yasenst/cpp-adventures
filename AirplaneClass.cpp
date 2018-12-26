#include "AirplaneClass.hpp"

std::vector<Airplane*> airplanes;

AirplaneClass::AirplaneClass() {
    this->id = (++AirplaneClass::count);
}

AirplaneClass::AirplaneClass(std::string manufacturer, std::string model, int seats, int trackLength)
{
    this->id = (++AirplaneClass::count);
    this->manufacturer = manufacturer;
    this->model = model;
    this->seats = seats;
    this->trackLength = trackLength;
}

AirplaneClass::AirplaneClass(const AirplaneClass &obj)
{
    std::cout << "Copy constructor of AirplaneClass.." << std::endl;
    id = obj.id;
    manufacturer = obj.manufacturer;
    model = obj.model;
    seats = obj.seats;
    trackLength = obj.trackLength;
}

AirplaneClass::~AirplaneClass()
{
    std::cout << "Entering AirplaneClass destructor " + manufacturer + " " + model << std::endl;

     for(int i = 0; i < airplanes.size(); i++)
    {
       delete airplanes[i];
       std::cout << "Deleted " << std::endl;
    }
}

std::ostream& operator<<(std::ostream& stream, const AirplaneClass& obj)
{
     stream << obj.id << " " << obj.manufacturer << " " << obj.model << " " << obj.seats << " " << obj.trackLength << '\n';
    //stream << "Airplane Class ID: " << obj.id << " - " << obj.getManufacturer() << " " << obj.model;

    /*
    for( std::vector<Airplane>::const_iterator it = obj.airplanes.begin(); it != obj.airplanes.end(); ++it)
                 stream << (*it) << std::endl;
    */

    return stream;
}

int AirplaneClass::count = 0;

int AirplaneClass::getId() { return id; }

std::string AirplaneClass::getManufacturer() const { return manufacturer; }

std::string AirplaneClass::getModel() const { return model; }

int AirplaneClass::getSeats() const { return seats; }

int AirplaneClass::getTrackLength() const { return trackLength; }

void AirplaneClass::setId(int id) { this->id = id; }

void AirplaneClass::setManufacturer(std::string manufacturer) { this->manufacturer = manufacturer; }

void AirplaneClass::setModel(std::string model) { this->model = model; }

void AirplaneClass::setSeats(int seats) { this->seats = seats; }

void AirplaneClass::setTrackLength(int trackLength) { this->trackLength = trackLength; }

std::vector<Airplane*> AirplaneClass::getAirplanes()
{
    return airplanes;
}

void AirplaneClass::addAirplane(Airplane* airplane)
{
    airplanes.push_back(airplane);
    //showAirplanes();
}

void AirplaneClass::showAirplanes()
{
     for(std::vector<Airplane*>::iterator it = airplanes.begin(); it != airplanes.end(); ++it)
    {
        std::cout << *(*it) << std::endl;
    }
}

void AirplaneClass::setCount(int c)
{
    count = c;
}
