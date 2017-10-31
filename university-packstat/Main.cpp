#include "Data.h"
#include "PcapAdapter.h"

#include <iostream>
#include <vector>
#include <map>
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>


int main() {

	PcapAdapter pa;
	pa.open();
	std::cout << pa.getNextIP() << std::endl;
	std::cout << pa.getNextIP() << std::endl;
	std::cout << pa.getNextIP() << std::endl;
	std::cout << pa.getNextIP() << std::endl;
	std::cout << pa.getNextIP() << std::endl;

	system("PAUSE");
	return 0;
}