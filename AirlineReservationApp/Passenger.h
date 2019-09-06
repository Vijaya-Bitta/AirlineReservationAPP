#pragma once
#include <string>

namespace AirlineReservationApp
{
	class Passenger
	{
	public:
		Passenger() = default;
		Passenger(const std::string& firstName, const std::string& lastName, int id);
		void SetPassengerFirstName(const std::string& firstName);
		const std::string GetPassengerFirstName() const;
		void SetPassengerLastName(const std::string& lastName);
		const std::string GetPassengerLastName() const;
		void SetPassengerEmail(const std::string& emailId);
		const std::string GetPassengerEmail() const;
		void SetPassengerID(int Id);
		int GetPassengerID() const;
		void SetSeatnumber(int seatNumber);
		int GetSeatNumber() const;


	private:
		std::string mfirstName;
		std::string mlastName;
		std::string mEmail;
		int mSeatNumber=-1;
		int mID=-1;
	};
}