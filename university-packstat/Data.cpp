#include "Data.h"

Data::Data() {
	this->barrier = 0;
}

Data::~Data() {}

void Data::insert(u_long ip) {
	size_t i;
	for (i = 0; i < this->barrier; i++) {
		if (ip == this->statistics[i].ip) {
			this->statistics[i].count++;
			this->bubble(i);
			break;
		}
	}
	if (i == this->barrier) {
		this->append(ip);
	}
}

void Data::append(u_long ip) {
	this->statistics[this->barrier].count = 1;
	this->statistics[this->barrier].ip = ip;
	this->shiftBarrier();
}

void Data::bubble(size_t i) {
	while ((i != 0) && (this->statistics[i - 1].count < this->statistics[i].count)) {
		this->swap(i - 1, i);
		i--;
	}
}

void Data::swap(size_t i, size_t j) {
	int tmpCount = this->statistics[i].count;
	u_long tmpIp = this->statistics[i].ip;
	this->statistics[i].count = this->statistics[j].count;
	this->statistics[i].ip = this->statistics[j].ip;
	this->statistics[j].count = tmpCount;
	this->statistics[j].ip = tmpIp;
}

void Data::shiftBarrier() {
	this->barrier = (this->barrier < 499) ? this->barrier + 1 : 499;
}

void Data::countAverages(std::vector<int> &v, std::vector<int> &a) {
	static int n = 0;
	for (size_t i = 0; i < MAX_CAPTURES_NUMBER; i++) {
		this->averages[i] = (n * this->averages[i] + this->statistics[i].count) / (n + 1);
	}
	n++;
	a.assign(this->averages, this->averages + this->barrier);
	v.resize(this->barrier);
	for (size_t i = 0; i < this->barrier; i++) {
		v[i] = this->statistics[i].count;
	}
}

void Data::clear() {
	std::fill(std::begin(this->statistics), std::end(this->statistics), Pair());
	this->barrier = 0;
}

void Data::displayWarning() {
	printf("Attack detected\n");
}

bool Data::checkAttack() {
	double sum = 0;
	for (int i = 0; i < MAX_CAPTURES_NUMBER; i++) {
		int theoretical = this->averages[i];
		int experienced = this->statistics[i].count;
		if (theoretical != 0) {
			double dn = (double)experienced - (double)theoretical;
			sum += dn * dn / theoretical;
		}
	}
	printf("%d\n", this->barrier);
	return !(sum < this->x2[this->barrier]);
}

int Data::load() {
	return 0;
}

int Data::dump() {
	return 0;
}