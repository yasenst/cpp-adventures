#include "AirplaneClass.hpp"

AirplaneClass::AirplaneClass() {}

AirplaneClass::AirplaneClass(std::string manufacturer, std::string model, int seats, int trackLength)
{
    this->manufacturer = manufacturer;
    this->model = model;
    this->seats = seats;
    this->trackLength = trackLength;
}

AirplaneClass::AirplaneClass(const AirplaneClass &obj)
{
    manufacturer = obj.manufacturer;
    model = obj.model;
    seats = obj.seats;
    trackLength = obj.trackLength;
}

std::string AirplaneClass::getManufacturer() const { return manufacturer; }

std::string AirplaneClass::getModel() const { return model; }

int AirplaneClass::getSeats() const { return seats; }

int AirplaneClass::getTrackLength() const { return trackLength; }

void AirplaneClass::setManufacturer(std::string manufacturer) { this->manufacturer = manufacturer; }

void AirplaneClass::setModel(std::string model) { this->model = model; }

void AirplaneClass::setSeats(int seats) { this->seats = seats; }

void AirplaneClass::setTrackLength(int trackLength) { this->trackLength = trackLength; }
