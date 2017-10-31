#include "Data.h"

Data::Data() {}

Data::~Data() {}

void Data::add(char *ip) {
	std::string _ip{ ip };
	std::map<std::string, int>::iterator it = this->clients.find(_ip);
	if (it == this->clients.end()) {
		this->clients.emplace(_ip, 1);
		return;
	}
	it->second++;
}

int Data::get(char *ip) {
	std::string _ip{ ip };
	std::map<std::string, int>::const_iterator it = this->clients.find(_ip);
	if (it == this->clients.end()) {
		return -1;
	}
	return it->second;
}

void Data::getAll(std::vector<std::pair<std::string, int>> &v) {
	v.clear();
	for (std::map<std::string, int>::const_iterator it = this->clients.begin(); it != this->clients.end(); ++it) {
		v.emplace_back(it->first, it->second);
	}
	std::sort(v.begin(), v.end(), [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {
		return (b.second < a.second);
	});
}

int Data::load() {
	return 0;
}

int Data::dump() {
	return 0;
}