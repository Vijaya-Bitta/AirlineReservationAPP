#include "Flight.h"
#include <string>
#include <vector>

namespace AirlineReservationApp
{
	class Database
	{
	public :
		void AddFlight(const Flight& flight);
		Flight& GetFlight(int flightNumber);
		std::vector<Flight>& GetAllFlights();
	private:
		std::vector<Flight> mFlights;

	};
}

