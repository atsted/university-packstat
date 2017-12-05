#pragma once

#include <algorithm>
#include <vector>
#include <map>
#include "Packet.h"

#define MAX_SIZE	500


typedef struct {
	u_long ip = 0;
	int count = 0;
} Pair;

class Data {
private:
	std::map<u_long, int> clients;		
	
	/* Points the place append new IP */
	int barrier;

	/* Contains the average statistics of occurrences */
	int averages[MAX_SIZE];

	/* Contains IP address and the number of occurrences */
	Pair statistics[MAX_SIZE];

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
	int load();
	int dump();
};

