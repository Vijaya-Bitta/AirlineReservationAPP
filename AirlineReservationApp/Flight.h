#pragma once
#include "Passenger.h"
#include <string>
#include <iostream>
#include <vector>

namespace AirlineReservationApp
{
	class Flight
	{
	public:
		Flight() = default;
		void Display() const;
		void ReserveSeat(Passenger& passenger);
		Flight(const std::string& Destination, const std::string& Departure, int SeatsAmount, int flightNumber);
		void SetDestination(const std::string& Destination);
		const std::string GetDestination() const;
		void SetDeparture(const std::string& Departure);
		const std::string GetDeparture() const;
		void SetFlightNumber(int flightNumber);
		int GetFlightNumber() const;
		void SetSeatsAvailble(const std::vector<int>& seatsAvailable);
		std::vector<int>& GetSeatsAvailble();
		void SetPassenger(const std::vector<Passenger>& passengers);
		std::vector<Passenger>& GetPassengers();
	private:
		std::string mDestination;
		std::string mDeparture;
		int mFlightNumber = -1;
		std::vector<Passenger> mPassengers;
		std::vector<int> mSeatsAvailable;
	};
}

