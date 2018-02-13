#pragma once

#include <algorithm>
#include <vector>
#include <map>
#include "Packet.h"

#define MAX_CAPTURES_NUMBER	500


typedef struct {
	u_long ip = 0;
	int count = 0;
} Pair;

class Data {
private:

	/* Points the place append new IP */
	int barrier;

	/* Contains the average statistics of occurrences */
	int averages[MAX_CAPTURES_NUMBER];

	/* Theoretical values of x2 distribution */
	double x2[30] = { 3.8, 6.0, 7.8, 9.5, 11.1, 12.6, 14.1, 15.5, 16.9, 18.3, 19.7, 21.0, 22.4, 23.7, 25.0, 26.3, 27.6, 28.9, 30.1, 31.4, 32.7, 33.9, 35.2, 36.4, 37.7, 38.9, 40.1, 41.3, 42.6, 43.8 };

	/* Contains IP address and the number of occurrences */
	Pair statistics[MAX_CAPTURES_NUMBER];

public:
	Data();
	~Data();
	void insert(u_long);
	void append(u_long);
	void bubble(size_t);
	void swap(size_t, size_t);
	void shiftBarrier();
	void countAverages(std::vector<int> &, std::vector<int> &);
	void clear();
	void displayWarning();
	bool checkAttack();
	int load();
	int dump();
};

