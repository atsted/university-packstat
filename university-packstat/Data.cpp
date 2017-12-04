#include "Data.h"

Data::Data() {}

Data::~Data() {}

void Data::add(u_long ip) {
	std::map<u_long, int>::iterator it = this->clients.find(ip);
	if (it == this->clients.end()) {
		this->clients.emplace(ip, 1);
		return;
	}
	it->second++;
}

int Data::get(u_long ip) {
	std::map<u_long, int>::const_iterator it = this->clients.find(ip);
	if (it == this->clients.end()) {
		return -1;
	}
	return it->second;
}

void Data::getAll(std::vector<int> &v) {
	int i = 0;
	v.resize(this->clients.size());
	for (std::map<u_long, int>::const_iterator it = this->clients.begin(); it != this->clients.end(); ++it) {
		v[i++] = it->second;
	}
	std::sort(v.begin(), v.end(), [](const int &a, const int &b) {
		return (b < a);
	});
}

void Data::clear() {
	this->clients.clear();
}

int Data::load() {
	return 0;
}

int Data::dump() {
	return 0;
}