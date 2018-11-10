#include <iostream>
#include "Flight.h"
using namespace std;

Flight::Flight()
{
	this->flightNo = 0;
	this->aircraft = nullptr;
}

Flight::Flight(int flightNo, int rowNo, int seatNo)
{
	this->flightNo = flightNo;
	this->aircraft = new Aircraft(rowNo, seatNo);
}

Flight::Flight(const Flight &f)
{
	this->flightNo = f.flightNo;
	this->aircraft = new Aircraft(*f.aircraft);
}

void Flight::operator=(const Flight &f) {
	if (this != &f) {
		this->flightNo = f.flightNo;
		if (aircraft) {
			delete aircraft;
		}
		this->aircraft = new Aircraft(*f.aircraft);
	}
}

Flight::~Flight()
{
	if (aircraft) {
		delete aircraft;
	}
}

int Flight::getRows() const
{
	return aircraft->getNumOfRows();
}

int Flight::getSeats() const
{
	return aircraft->getNumOfRowSeats();
}

int Flight::getFlightNo() const
{
	return this->flightNo;
}

void Flight::printAircraftLayout() const
{
	aircraft->printSeats();
}

int Flight::getAvailableSeats() const
{
	return aircraft->getAvailableSeats();
}

bool Flight::isSeatAvailable(const int & row, const int & col) const
{
	return aircraft->isSeatAvailable(row-1,col-1);
}

bool Flight::bookSeat(const int & row, const int & col)
{
	return aircraft->bookSeat(row,col);
}

void Flight::unBookSeat(const int & row, const int & col)
{
	aircraft->unBookSeat(row, col);
}