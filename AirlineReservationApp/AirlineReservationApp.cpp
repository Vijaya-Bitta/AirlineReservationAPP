// AirlineReservationApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "stdafx.h"
#include "Database.h"
#include <iostream>

using namespace AirlineReservationApp;

using namespace std;

int DisplayMenu();
void ReserveSeat(Database& db);
void PresentFlightsSchedule(Database& db);
void DisplayPassengerInfo(Database& db);
void DisplayFlightInfo(Database& db);
void PassengerTicketInfomation(Database& db);
Flight& ChooseFlight(Database& db);
	int main()
	{
		Database db;
		
		Flight f1("California", "Seattle", 30,001);
		Flight f2("Loss Angles", "Newyork",50,002);
		Flight f3("Seattle", "Loss Vegas", 20,003);
		Flight f4("Seattle", "portland", 30,004);
		Flight f5("California", "New Jersey", 30, 005);

		db.AddFlight(f1);
		db.AddFlight(f2);
		db.AddFlight(f3);
		db.AddFlight(f4);
		db.AddFlight(f5);


		while (true) {
			int selection = DisplayMenu();
			switch (selection) {
			case 0:
				return 0;
			case 1:
				ReserveSeat(db);
				break;
			case 2:
				PresentFlightsSchedule(db);
				break;
			case 3:
				DisplayPassengerInfo(db);
				break;
			case 4:
				DisplayFlightInfo(db);
				break;
			case 5:
				PassengerTicketInfomation(db);
				break;
			default:
				cerr << "Unknown command." << endl;
				break;
			}
		}

		return 0;
	}
	


	int DisplayMenu()
	{
		int selection;
		cout << endl;
		cout << "AirLine Reservation" << endl;
		cout << "-----------------" << endl;
		cout << "1) Reserve a Seat" << endl;
		cout << "2) Flight Schedule" << endl;
		cout << "3) Display passenger info" << endl;
		cout << "4) Fligt Details" << endl;
		cout << "5) Passenger Ticket Information" << endl;
		cout << "0) Quit" << endl;
		cout << endl;
		cout << "---> ";

		cin >> selection;

		return selection;
	}
	//For Displaying all flights

	void PresentFlightsSchedule(Database& db)
	{
		vector<Flight>& allFlights = db.GetAllFlights();
		for (Flight& f : allFlights)
		{
			f.Display();
		}
	}

	Flight& ChooseFlight(Database& db)
	{
		int flightId;
		cout << "Choose flight " << endl;
		PresentFlightsSchedule(db);
		cin >> flightId;
		Flight& flight = db.GetFlight(flightId);
		return flight;
	}

	
	Passenger& GetPassengerInfo()
	{
		string firstName;
		string lastName;
		int passengerId;
		cout << "Your First name: ";
		cin >> firstName;
		cout << "Last name: ";
		cin >> lastName;
		cout << "Your Id number: ";
		cin >> passengerId;

		Passenger* passenger = new Passenger(firstName, lastName, passengerId);
		return *passenger;
	}

	void ReserveSeat(Database& db)
	{
		int chosenSeat;

		Flight& flight = ChooseFlight(db);
		vector<int>& freeSeats = flight.GetSeatsAvailble();
		for (int seat : freeSeats)
		{
			cout << seat << " ";
		}
		cout << endl << "Choose Your Seat " << endl;
		cin >> chosenSeat;

		Passenger& passenger = GetPassengerInfo();
		passenger.SetSeatnumber(chosenSeat);
		flight.ReserveSeat(passenger);
	}
	void DisplayPassengerInfo(Database& db)
	{

		Flight& flight = ChooseFlight(db);

		vector<Passenger>& passengers = flight.GetPassengers();
		for (Passenger& passenger : passengers)
		{
			cout << "Passenger Information:" << endl;
			cout << "-------------------------" << endl;
			cout << "Seat Number: " <<passenger.GetSeatNumber() << endl;
			cout << "Name: " << passenger.GetPassengerFirstName() << " " <<passenger.GetPassengerLastName() << endl;
			cout << "Flight Number: " << flight.GetFlightNumber() << endl;
			cout << "Flight From: " << flight.GetDeparture() << " To: " << flight.GetDestination() << endl;
			cout << endl;
		}
	}
	void PassengerTicketInfomation(Database& db)
	{
		Flight& flight = ChooseFlight(db);

		int userId;
		cout << "Your Id number? ";
		cin >> userId;

		vector<Passenger>& passengers = flight.GetPassengers();
		bool userFound = false;
		for (Passenger& passenger : passengers) {
			if (userId == passenger.GetPassengerID()) {
				userFound = true;
				cout << "Passenger Information:" << endl;
				cout << "-------------------------" << endl;
				cout << "Name: " << passenger.GetPassengerFirstName() << " " << passenger.GetPassengerLastName() << endl;
				cout << "Flight Number: " << flight.GetFlightNumber() << endl;
				cout << "Flight From: " << flight.GetDeparture() << " To " << flight.GetDestination() << endl;
				cout << "Seat Number: " << passenger.GetSeatNumber() << endl;
				cout << endl;
			}
		}
		if (userFound == false) {
			cout << "Passenger not found." << endl;
		}
	}
	void DisplayFlightInfo(Database& db) 
	{
		Flight& flight = ChooseFlight(db);
		flight.Display();
		vector<int>& freeSeats = flight.GetSeatsAvailble();
		vector<Passenger>& seatsBooked = flight.GetPassengers();
		cout << "Free seats left: " << freeSeats.size() << endl;
		cout << "Seats booked: " << seatsBooked.size() << endl;
	}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
