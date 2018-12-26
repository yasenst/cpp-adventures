#include<vector>
#include "AirplaneClass.hpp"

class AirplaneManager
{
private:

    //std::vector<Airplane*> airplanes;
    std::vector<AirplaneClass*> airplaneClasses;

public:
    AirplaneManager();
    ~AirplaneManager();
    void addAirplane();
    void addAirplaneClass();
    std::vector<AirplaneClass*> getAirplaneClasses();
    void showAirplaneClasses();
    void writeAirplanes(std::ostream& o, const std::vector<AirplaneClass*>& AirplaneClassToBeWritten);
    void writeAirplanes(std::ostream&& o, const std::vector<AirplaneClass*>& AirplaneClassToBeWritten);
    void loadAirplaneClasses();
    void loadAirplanes();
    void saveAirplanes();
};
