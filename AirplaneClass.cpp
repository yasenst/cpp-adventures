#include "AirplaneClass.hpp"

std::vector<Airplane*> airplanes;

AirplaneClass::AirplaneClass()
{
    this->id = (++AirplaneClass::count);
}

AirplaneClass::AirplaneClass(std::string manufacturer, std::string model, int seats, int trackLength)
{
    setManufacturer(manufacturer);
    setModel(model);
    setSeats(seats);
    setTrackLength(trackLength);
    this->id = (++AirplaneClass::count);
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
    //std::cout << "Entering AirplaneClass destructor " + manufacturer + " " + model << std::endl;
    for(unsigned int i = 0; i < airplanes.size(); i++)
    {
       delete airplanes[i];
       //std::cout << "Deleted " << std::endl;
    }
}

std::ostream& operator<<(std::ostream& stream, const AirplaneClass& obj)
{
    stream << obj.id << " " << obj.manufacturer << " " << obj.model << " " << obj.seats << " " << obj.trackLength << '\n';

    return stream;
}

int AirplaneClass::count = 0;

int AirplaneClass::getId() { return id; }

std::string AirplaneClass::getManufacturer() const { return manufacturer; }

std::string AirplaneClass::getModel() const { return model; }

int AirplaneClass::getSeats() const { return seats; }

int AirplaneClass::getTrackLength() const { return trackLength; }

void AirplaneClass::setId(int id) { this->id = id; }

void AirplaneClass::setManufacturer(std::string manufacturer)
{
    if (manufacturer.empty() || manufacturer.length() <= 1)
        throw "Manufacturer name should be at least 2 characters!";
    this->manufacturer = manufacturer;
}

void AirplaneClass::setModel(std::string model)
{
    if (model.empty() || model.length() <= 1)
        throw "Model name should be at least 2 characters!";
    this->model = model;
}

void AirplaneClass::setSeats(int seats)
{
    if (seats <= 0)
        throw "Number of seats must be a positive number!";

    this->seats = seats;
}

void AirplaneClass::setTrackLength(int trackLength)
{
    if (trackLength <= 0)
        throw "Track length must be a positive number!";

    this->trackLength = trackLength;
}

std::vector<Airplane*> AirplaneClass::getAirplanes()
{
    return airplanes;
}

void AirplaneClass::addAirplane(Airplane* airplane)
{
    airplanes.push_back(airplane);
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
