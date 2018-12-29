#include<iostream>

#ifndef AIRPLANE_HPP
#define AIRPLANE_HPP

class Airplane
{

private:

    static int count;
    int id;
    int classId;
    int averageSpeed;
    int tankVolume;
    double fuelConsumptionPerKm;

public:

    Airplane(std::string averageSpeed, std::string tankVolume, std::string fuelConsumptionPerKm);
    Airplane(const Airplane &obj);
    ~Airplane();

    friend std::ostream &operator<<(std::ostream& stream, const Airplane& obj);

    int getId();
    int getClassId();
    int getTankVolume() const;
    int getAverageSpeed() const;
    double getFuelConsumption() const;

    static void setCount(int c);
    void setId(int id);
    void setClassId(int classId);
    void setFuelConsumptionPerKm(std::string fuelConsumption);
    void setTankVolume(std::string tankVolume);
    void setAverageSpeed(std::string averageSpeed);
};

#endif // AIRPLANE_HPP
