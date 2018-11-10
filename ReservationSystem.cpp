/*
The implementation of the reservation system.
Author: Hanzallah Azim Burney
ID: 21701829
*/

#include <iostream>
#include <ctime>
#include "ReservationSystem.h"
#include "Flight.h"
using namespace std;

ReservationSystem::ReservationSystem(){
	this->flightsSize = 0;
	this->reservationsSize = 0;
	this->resSize = 0;
	this->flights = nullptr;
	this->reservations = nullptr;
}

ReservationSystem::~ReservationSystem(){
	delete[] flights;
	delete[] reservations;
}

void ReservationSystem::addFlight(const int flightNo, const int rowNo, const int seatNo)
{
	int index = searchFlight(flightNo);
	if (index == -1) {
		Flight *newFlight = new Flight(flightNo, rowNo, seatNo);
		this->flightsSize++;

		Flight *temp = nullptr;
		if (flights != nullptr) {
			temp = flights;
		}

		flights = new Flight[flightsSize];
		if (temp != nullptr) {
			for (int i = 0; i < flightsSize - 1; i++) {
				flights[i] = temp[i];
			}
		}

		// overload the = operator since copy constructor won't work as the object is already declared in an array
		// copy constructor only works if the object has not previously been declared and we are instantiating a new object
		flights[flightsSize-1] = *newFlight;

		delete newFlight;
		delete[] temp;
	}

	else {
		cout << "Flight already exists" << endl;
	}
}

void ReservationSystem::altAddFlight(const int flightNo, const int rowNo, const int colNo)
{
	int index = searchFlight(flightNo);
	if (index == -1) {
		Flight *newFlight = new Flight(flightNo, rowNo, colNo);
		this->flightsSize++;
		Flight *temp = new Flight[flightsSize];

		if (flights != nullptr) {
			for (int i = 0; i < flightsSize - 1; i++) {
				temp[i] = flights[i];
			}
		}
		delete[] flights;
		temp[flightsSize - 1] = *newFlight;

		flights = temp;
		delete newFlight;
	}
	else {
		cout << "Flight already exists" << endl;
	}
}

void ReservationSystem::cancelFlight(const int flightNo)
{
	int index = searchFlight(flightNo);
	if (index != -1) {
		this->flightsSize--;
		Flight *store = flights;
		flights = new Flight[flightsSize];

		for (int i = 0; i < index; i++) {
			flights[i] = store[i];
		}

		for (int i = index + 1; i < flightsSize + 1; i++) {
			flights[i - 1] = store[i];
		}

		delete[] store;
	}
	else {
		cout << "Flight doesn't exist!" << endl;
	}
}

void ReservationSystem::showAllFlights() const
{
	if (flightsSize == 0) {
		cout << "There are no flights!" << endl;
	}
	else {
		for (int flight = 0; flight < flightsSize; flight++) {
			cout << flights[flight].getFlightNo() << " has " << flights[flight].getAvailableSeats() << " available seats." << endl;
		}
	}
}

void ReservationSystem::showFlight(const int flightNo) const
{
	int index = searchFlight(flightNo);
	if (index != -1) {
		flights[index].printAircraftLayout();
	}
	else {
		cout << "Flight doesn't exist!" << endl;
	}
}

int ReservationSystem::makeReservation(int flightNo, int numPassengers, const int * seatRow, const char * seatCol)
{
	srand(time(nullptr));
	int resId = rand();
	int indexRes = searchReservation(resId);

	while (indexRes != -1) {
		resId = rand();
		indexRes = searchReservation(resId);
	}

	int index = searchFlight(flightNo);
	if (index != -1) {
		Reservation *newRes = new Reservation(resId, &flights[index], numPassengers, seatRow, seatCol);
		this->resSize++;

		Reservation *temp = nullptr;
		if (reservations != nullptr) {
			temp = reservations;
		}

		reservations = new Reservation[resSize];
		if (temp!=nullptr) {
			for (register int i = 0; i < resSize - 1; i++) {
				reservations[i] = temp[i];
			}
		}
		
		reservations[resSize - 1] = *newRes;
		reservations[resSize - 1].selectSeats();
		delete newRes;
		delete[] temp;

		return resId;
	}
	else {
		cout << "Flight already exists" << endl;
		return 0;
	}
}

void ReservationSystem::cancelReservation(const int resCode)
{
	int index = searchReservation(resCode);
	if (index != -1) {
		reservations[index].unSelectSeats();
		this->resSize--;
		Reservation *store = reservations;
		reservations = new Reservation[resSize];

		for (register int i = 0; i < index; i++) {
			reservations[i] = store[i];
		}

		for (register int i = index + 1; i < resSize + 1; i++) {
			reservations[i - 1] = store[i];
		}

		delete[] store;
	}
	else {
		cout << "Reservation doesn't exist!" << endl;
	}
}

void ReservationSystem::showReservation(const int resCode) const
{
	int index = searchReservation(resCode);
	if (index != -1) {
		reservations[index].printReservation();
	}
	else {
		cout << "Reservation doesn't exist!" << endl;
	}
}

int ReservationSystem::searchFlight(const int flightno) const
{
	for (register int j = 0; j < flightsSize; j++) {
		if (flights[j].getFlightNo() == flightno) {
			return j;
		}
	}
	return -1;
}

int ReservationSystem::searchReservation(const int resId) const
{
	for (register int j = 0; j < resSize; j++) {
		if (reservations[j].getResId() == resId) {
			return j;
		}
	}
	return -1;
}