#include <iostream>
#include "Reservation.h"
using namespace std;

Reservation::Reservation()
{
	this->resId = 0;
	this->size = 0;
	this->flight = nullptr;
	this->rows = nullptr;
	this->seats = nullptr;
}

Reservation::Reservation(int resId, Flight * flight, int size,const int * rows, const char * seats)
{
	this->resId = resId;
	this->size = size;
	this->flight = flight;
	this->rows = rows;
	this->seats = seats;
}

Reservation::Reservation(const Reservation & res)
{
	this->resId = res.resId;
	this->size = res.size;
	this->flight = res.flight;
	this->rows = res.rows;
	this->seats = res.seats;
}
 
void Reservation::operator=(const Reservation & res)
{
	if (this != &res) {
		this->resId = res.resId;
		this->size = res.size;
		this->flight = res.flight;
		this->rows = res.rows;
		this->seats = res.seats;
	}
}

Reservation::~Reservation()
{
}

int Reservation::getResId() const
{
	return resId;
}

int Reservation::getFlightNo() const
{
	return flight->getFlightNo();
}

void Reservation::selectSeats()
{
	int count = 0;
	bool val;
	for (register int i = 0; i < size; i++) {
		val = this->flight->isSeatAvailable(rows[i], seats[i] - 64);
		if (val == false) {
			cout << "Seat " << rows[i] << seats[i] << " is not available!" << endl;
			count++;
		}
	}
	for (register int i = 0; i < size; i++) {
		if (count == 0) {
			this->flight->bookSeat(rows[i], seats[i] - 64);
		}
	}
}

void Reservation::unSelectSeats()
{
	for (int i = 0; i < size; i++) {
		this->flight->unBookSeat(rows[i], seats[i] - 64);
	}
}

void Reservation::printReservation() const
{
	cout << "The reservation " << resId << " in flight " << flight->getFlightNo() << " : ";
	for (int i = 0; i < size; i++) {
		cout << rows[i] <<  seats[i] << " ";
	}
	cout << endl;
}
