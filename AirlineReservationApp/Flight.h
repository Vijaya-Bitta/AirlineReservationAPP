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
		Flight(const std::string& Destination, const std::string& Departure, 
			int SeatsAmount, int flightNumber, const std::string& date, 
			const std::string& arrivalTime, const std::string& departTime);
		void ReserveSeat(Passenger& passenger);
		
		void SetDestination(const std::string& Destination);
		const std::string GetDestination() const;
		void SetDeparture(const std::string& Departure);
		const std::string GetDeparture() const;


		void setFlightDate(int flightDate);
		const std::string& getFlightDate() const;

		void setDepartTime(const std::string& departtime);
		const std::string& getDepartTime() const;

		void setArriveTime(const std::string& arrivetime);
		const std::string& getArriveTime() const;

		void SetFlightNumber(int flightNumber);
		int GetFlightNumber() const;
		void SetSeatsAvailble(const std::vector<int>& seatsAvailable);
		std::vector<int>& GetSeatsAvailble();
		void SetPassenger(const std::vector<Passenger>& passengers);
		std::vector<Passenger>& GetPassengers();
	private:
		std::string mDestination;
		std::string mDeparture;

		std::string mFlightDate;

		std::string mDepartTime;
		std::string mArriveTime;

		//float mFlightDur;

		int mFlightNumber = -1;
		std::vector<Passenger> mPassengers;
		std::vector<int> mSeatsAvailable;
	};
}

