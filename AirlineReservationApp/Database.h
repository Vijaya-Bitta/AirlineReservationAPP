#include "Flight.h"
#include <vector>
#include <iostream>

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

