#include "stdafx.h"
#include "Passenger.h"
#include <iostream>
#include <string>

using namespace std;
namespace AirlineReservationApp
{
	
	Passenger::Passenger(const string& firstName, const string& lastName, int id)
	{
		mfirstName = firstName;
		mlastName = lastName;
		mID = id;
	}

	void Passenger::SetPassengerFirstName(const std::string& firstName)
	{
		mfirstName = firstName;
	}
	const std::string Passenger::GetPassengerFirstName() const
	{
		return mfirstName;
	}
	void Passenger::SetPassengerLastName(const std::string& lastName)
	{
		mfirstName = lastName;
	}
	const std::string Passenger::GetPassengerLastName() const
	{
		return mlastName;
	}

	void Passenger::SetPassengerEmail(const std::string& emailId)
	{
		mEmail = emailId;
	}
	const std::string Passenger::GetPassengerEmail() const
	{
		return mEmail;
	}
	void Passenger::SetSeatnumber(int seatNumber)
	{
		mSeatNumber = seatNumber;
	}
	int Passenger::GetSeatNumber() const
	{
		return mSeatNumber;
	}
	
	void Passenger::SetPassengerID(int Id)
	{
		mID = Id;
	}
	int Passenger::GetPassengerID() const
	{
		return mID;
	}
}