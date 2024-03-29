#include "stdafx.h"
#include "Flight.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
namespace AirlineReservationApp
{
	
	Flight::Flight(const std::string& Destination,
		const std::string& Departure, int SeatsAmount, 
		int flightNumber, const string& date,
		const std::string& arrivalTime, const std::string& departTime) :
		mDestination(Destination), mDeparture(Departure), mFlightNumber(flightNumber),mFlightDate(date),
		mArriveTime(arrivalTime),mDepartTime(departTime){
		for (int i = 1; i <= SeatsAmount; i++)
		{
			mSeatsAvailable.push_back(i);
		}
	}
	
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

	void Flight::setFlightDate(int flightDate)
	{
		mFlightDate = flightDate;
	}
	const std::string& Flight::getFlightDate() const
	{
		return mFlightDate;
	}


	void Flight::setDepartTime(const std::string& departtime)
	{
		mDepartTime = departtime;
	}

	const std::string& Flight::getDepartTime() const
	{
		return mDepartTime;
	}

	void Flight::setArriveTime(const std::string& arrivetime)
	{
		mArriveTime = arrivetime;
	}

	const std::string& Flight::getArriveTime() const
	{
		return mArriveTime;
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

	void Flight::ReserveSeat(Passenger& passenger)
	{
		mPassengers.push_back(passenger);
		int seatNumber = passenger.GetSeatNumber();
		mSeatsAvailable.erase(std::remove(mSeatsAvailable.begin(), mSeatsAvailable.end(), seatNumber), mSeatsAvailable.end());
	}
	void Flight::Display() const
	{
		cout << "#" << GetFlightNumber() << " From " << GetDeparture() << " To " << GetDestination()<<" On  "<<getFlightDate() << endl;
	}
}
