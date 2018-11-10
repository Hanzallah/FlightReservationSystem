#include <iostream>
#include "Aircraft.h"
using namespace std;

Aircraft::Aircraft()
{
	this->numOfRows = 0;
	this->numOfRowSeats = 0;
	this->seatAlloc = nullptr;
}

Aircraft::Aircraft(int numOfRows, int numOfRowSeats)
{
	if (numOfRows > 0 && numOfRowSeats > 0) {
		this->numOfRows = numOfRows;
		this->numOfRowSeats = numOfRowSeats;

		this->seatAlloc = new char*[numOfRows];
		for (register int row = 0; row < numOfRows; row++) {
			this->seatAlloc[row] = new char[numOfRowSeats];
		}

		for (register int row = 0; row < numOfRows; row++) {
			for (register int c = 0; c < numOfRowSeats; c++) {
				seatAlloc[row][c] = 'o';
			}
		}
	}
	else {
		Aircraft();
		cout << "Invalid Inputs! Constructed Null Aircraft!" << endl;
	}
}

Aircraft::Aircraft(Aircraft & aircraft)
{
	if (numOfRows != aircraft.getNumOfRows()) {
		this->numOfRows = aircraft.getNumOfRows();
	}
	if (numOfRowSeats != aircraft.getNumOfRowSeats()) {
		this->numOfRowSeats = aircraft.getNumOfRowSeats();
	}
	if (numOfRows > 0 && numOfRowSeats > 0) {
		this->seatAlloc = new char*[numOfRows];
		for (register int row = 0; row < numOfRows; ++row) {
			this->seatAlloc[row] = new char[numOfRowSeats];
		}

		for (register int row = 0; row < numOfRows; ++row) {
			for (register int c = 0; c < numOfRowSeats; ++c) {
				this->seatAlloc[row][c] = aircraft.seatAlloc[row][c];
			}
		}
	}
	else {
		seatAlloc = NULL;
	}
}


void Aircraft::operator=(Aircraft & aircraft)
{
	if (this != &aircraft) {
		if (numOfRows != aircraft.getNumOfRows()) {
			this->numOfRows = aircraft.getNumOfRows();
		}
		if (numOfRowSeats != aircraft.getNumOfRowSeats()) {
			this->numOfRowSeats = aircraft.getNumOfRowSeats();
		}
		if (numOfRows > 0 && numOfRowSeats > 0) {
			this->seatAlloc = new char*[numOfRows];
			for (register int row = 0; row < numOfRows; ++row) {
				this->seatAlloc[row] = new char[numOfRowSeats];
			}

			for (register int row = 0; row < numOfRows; ++row) {
				for (register int c = 0; c < numOfRowSeats; ++c) {
					this->seatAlloc[row][c] = aircraft.seatAlloc[row][c];
				}
			}
		}
		else {
			seatAlloc = NULL;
		}
	}
}

Aircraft::~Aircraft()
{
	for (int c = 0; c < this->getNumOfRows(); c++) {
		if (seatAlloc[c]) {
			delete[] seatAlloc[c];
		}
	}
	if (seatAlloc) {
		delete[] seatAlloc;
	}
}

int Aircraft::getNumOfRows() const
{
	return this->numOfRows;
}

int Aircraft::getNumOfRowSeats() const
{
	return this->numOfRowSeats;
}

int Aircraft::getAvailableSeats() const
{
	int seats = 0;
	for (register int row = 0; row < numOfRows; ++row) {
		for (register int c = 0; c < numOfRowSeats; ++c) {
			if  (this->seatAlloc[row][c] != 'x'){
				seats++;
			}
		}
	}
	return seats;
}

void Aircraft::printSeats() const
{
	cout << "  ";
	for (register int c = 1; c <= numOfRowSeats; ++c) {
		cout << static_cast<char>('@' + c) << " ";
	}
	cout << "\n";
	for (register int row = 0; row < numOfRows; ++row) {
		cout << row+1 << " ";
		for (register int c = 0; c < numOfRowSeats; ++c) {
			cout << seatAlloc[row][c] << " ";
		}
		cout << endl;
	}
}

bool Aircraft::bookSeat(const int &row, const int &col)
{
	if (isSeatAvailable(row-1, col-1)) {
		seatAlloc[row - 1][col - 1] = 'x';
		return true;
	}
	return false;
}

bool Aircraft::unBookSeat(const int & row, const int & col)
{
	seatAlloc[row-1][col-1] = 'o';
	return true;
}

bool Aircraft::isSeatAvailable(const int &row, const int &col) const
{
	return row <= this->getNumOfRows() && col <= this->getNumOfRowSeats() && seatAlloc[row][col] != 'x';
}