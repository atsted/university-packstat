#include "Data.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <pcap.h>


int main() {
	Data d;
	char gateway[] = "192.168.0.1";
	char localhost[] = "127.0.0.1";
	std::vector<std::pair<std::string, int>> v;
	std::cout << d.get(localhost) << std::endl;
	d.add(localhost);
	d.add(localhost);
	d.add(localhost);
	std::cout << d.get(localhost) << std::endl;
	d.add(gateway);
	d.getAll(v);
	for (int i = 0; i < v.size(); ++i) {
		std::cout << v[i].first.c_str() << "\t" << v[i].second << std::endl;
	}
	system("PAUSE");
	return 0;
}