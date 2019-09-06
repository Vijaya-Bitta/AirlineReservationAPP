#include "Database.h"
#include <iostream>
#include <string>
using namespace std;
namespace AirlineReservationApp
{
	void Database::AddFlight(const Flight& flight)
	{
		mFlights.push_back(flight);
	}
	Flight& Database::GetFlight(int flightNumber) 
	{
		for (auto& flight : mFlights)
		{
			if (flight.GetFlightNumber() == flightNumber)
			{
				return flight;
			}
		}
		throw logic_error("This flight number doesn't exist, please check your records.");
	}
	std::vector<Flight>& Database::GetAllFlights() 
	{
		return mFlights;
	}
}