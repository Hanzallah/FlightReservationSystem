#pragma once
#include "Flight.h"

class Reservation {
private:
	int resId;
	int size;
	Flight *flight;
	const int * rows;
	const char * seats;

public:
	Reservation();
	Reservation(int resId, Flight *flight, int size,const int *rows,const char *seats);
	Reservation(const Reservation &res);
	void operator=(const Reservation &res);
	~Reservation();

	int getResId() const;
	int getFlightNo() const;
	void selectSeats();
	void unSelectSeats();
	void printReservation() const;
};