#include<vector>
#include "Airplane.hpp"

class AirplaneManager
{
private:

    std::vector<Airplane> airplanes;
    std::vector<AirplaneClass> airplaneClasses;

public:
    AirplaneManager();
    void addAirplane(Airplane airplane);
    void addAirplaneClass(AirplaneClass airplaneClass);
    std::vector<Airplane> getAirplanes();
    std::vector<AirplaneClass> getAirplaneClasses();
};
