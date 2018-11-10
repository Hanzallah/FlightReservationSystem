/*
The header file for the reservation system.
Author: Hanzallah Azim Burney
ID: 21701829
*/

#pragma once
#include "Flight.h"
#include "Reservation.h"
using namespace std;

class ReservationSystem {
	private:
		int flightsSize;
		int reservationsSize;
		Flight *flights;
		Reservation *reservations;
		int resSize;

	public:
		ReservationSystem();
		~ReservationSystem();

		void addFlight(const int flightNo, const int rowNo, const int colNo);
		void altAddFlight(const int flightNo, const int rowNo, const int colNo);
		void cancelFlight(const int flightNo);

		void showAllFlights() const;
		void showFlight(const int flightNo) const;

		int makeReservation(int flightNo, int numPassengers, const int * seatRow, const char * seatCol);
		void cancelReservation(const int resCode);
		void showReservation(const int resCode) const;

		int searchFlight(const int flightNo) const;
		int searchReservation(const int resId) const;
};