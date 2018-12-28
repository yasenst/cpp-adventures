#include<vector>
#include "AirplaneClass.hpp"

class AirplaneManager
{
private:

    std::vector<AirplaneClass*> airplaneClasses;

public:
    AirplaneManager();
    ~AirplaneManager();

    void addAirplane();
    void addAirplaneClass();
    std::vector<AirplaneClass*> getAirplaneClasses();
    void showAirplaneClasses();
    void loadAirplaneClasses();
    void loadAirplanes();
    void saveAirplanes();
};
