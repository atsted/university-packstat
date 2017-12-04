#pragma once

#include <algorithm>
#include <vector>
#include <map>
#include "Packet.h"


class Data {
private:
	std::map<u_long, int> clients;		/* Contains IP address and the number of occurrences */
public:
	Data();
	~Data();
	void add(u_long);
	int get(u_long);
	void getAll(std::vector<int> &);
	void clear();
	int load();
	int dump();
};

