class Flight
{
private;

    static int count = 0;
    final int id;
    final Airplane airplane;

public:

    Flight(Airplane airplane);
    Flight(const Flight &obj);
    ~Flight();

    int getId() const;
    int getAirplane() const;
};
