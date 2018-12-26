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

    Airplane(int averageSpeed, int tankVolume, double fuelConsumptionPerKm);
    Airplane(const Airplane &obj);
    ~Airplane();

    friend std::ostream &operator<<(std::ostream& stream, const Airplane& obj);

    int getId();
    int getClassId();
    double getFuelConsumption() const;
    int getTankVolume() const;
    int getAverageSpeed() const;

    static void setCount(int c);
    void setId(int id);
    void setClassId(int classId);
    void setFuelConsumptionPerKm(double fuelConsumption);
    void setTankVolume(int tankVolume);
    void setAverageSpeed(int averageSpeed);
};

#endif // AIRPLANE_HPP
