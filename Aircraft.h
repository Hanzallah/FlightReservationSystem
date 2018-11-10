#pragma once

class Aircraft {
private:
	int numOfRows;
	// Number of seats in each row
	int numOfRowSeats;
	char **seatAlloc;
	
	
public:
	Aircraft();
	Aircraft(int numOfRows, int numOfRowSeats);
	Aircraft(Aircraft &aircraft);
	void operator=(Aircraft & aircraft);
	~Aircraft();
	int getNumOfRows() const;
	int getNumOfRowSeats() const;
	int getAvailableSeats() const;
	void printSeats() const;
	bool bookSeat(const int &row, const int &col);
	bool unBookSeat(const int &row, const int &col);
	bool isSeatAvailable(const int &row, const int &col) const;
};