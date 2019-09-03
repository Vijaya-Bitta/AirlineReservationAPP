#pragma once
#include <string>
namespace AirlineReservationApp
{
	class Passenger
	{
	public:
		Passenger() = default;
		Passenger(const std::string& firstName, const std::string& lastName);
		void SetPassengerFirstName(const std::string& firstName);
		const std::string GetPassengerFirstName() const;
		void SetPassengerLastName(const std::string& lastName);
		const std::string GetPassengerLastName() const;
		void SetPassengerEmail(const std::string& emailId);
		const std::string GetPassengerEmail() const;
		void SetSeatNumber(int passportNumber);
		int GetSeatNumber() const;
		void SetPassengerID(int phoneNumber);
		int GetPassengerID() const;

	private:
		std::string mfirstName;
		std::string mlastName;
		std::string mEmail;
		int mSeatNumber=-1;
		int mID=-1;
	};
}