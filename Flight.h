#pragma once
#include "Aircraft.h"

class Flight {
private:
	int flightNo;
	Aircraft *aircraft;

public:
	Flight();
	Flight(int flightNo, int rowNo, int seatNo);
	Flight(const Flight &f);
	void operator=(const Flight &f);
	~Flight();

	int getRows() const;
	int getSeats() const;
	int getFlightNo() const;
	void printAircraftLayout() const;
	int getAvailableSeats() const;
	bool isSeatAvailable(const int & row, const int & col) const;
	bool bookSeat(const int & row, const int & col);
	void unBookSeat(const int & row, const int & col);
};