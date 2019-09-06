#include "Flight.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
namespace AirlineReservationApp
{
	
	Flight::Flight(const std::string& Destination, const std::string& Departure, int SeatAvailable, int flightNumber) :
		mDestination(Destination), mDeparture(Departure), mSeatsAvailable(SeatAvailable), mFlightNumber(flightNumber) {}
	
	void Flight::SetDestination(const std::string& Destination)
	{
		mDestination = Destination;
	}
	const std::string Flight::GetDestination() const
	{
		return mDestination;
	}
	void Flight::SetDeparture(const std::string& Departure)
	{
		mDeparture = Departure;
	}
	const std::string Flight::GetDeparture() const
	{
		return mDeparture;
	}
	void Flight::SetFlightNumber(int flightNumber)
	{
		mFlightNumber = flightNumber;
	}
	int Flight::GetFlightNumber() const
	{
		return mFlightNumber;
	}
	void Flight::SetSeatsAvailble(const std::vector<int>& seatsAvailable)
	{
		mSeatsAvailable = seatsAvailable;
	}
	std::vector<int>& Flight::GetSeatsAvailble()
	{
		return	mSeatsAvailable;
	}
	void Flight::SetPassenger(const std::vector<Passenger>& passengers)
	{
		mPassengers = passengers;

	}
	std::vector<Passenger>& Flight::GetPassengers()
	{
		return mPassengers;
	}

	void Flight::ReserveSeat(Passenger passenger)
	{
		mPassengers.push_back(passenger);
		int seatNumber = passenger.GetSeatNumber();
		mSeatsAvailable.erase(std::remove(mSeatsAvailable.begin(), mSeatsAvailable.end(), seatNumber), mSeatsAvailable.end());
	}
	void Flight::Display() const
	{
		cout << "#" << GetFlightNumber() << " From " << GetDestination() << " To " << GetDeparture() << endl;
	}
}
