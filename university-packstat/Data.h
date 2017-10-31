#pragma once

#include <algorithm>
#include <vector>
#include <map>


class Data {
private:
	std::map<std::string, int> clients;		/* Contains IP address and the number of occurrences */
public:
	Data();
	~Data();
	void add(char *);
	int get(char *);
	void getAll(std::vector<std::pair<std::string, int>> &);
	int load();
	int dump();
};

