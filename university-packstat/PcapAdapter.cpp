#include "PcapAdapter.h"

PcapAdapter::PcapAdapter() {}

PcapAdapter::~PcapAdapter() {
	pcap_close(this->handle);
}

void PcapAdapter::open() {
	this->handle = pcap_open_offline(DUMP_FILE, this->errbuf);
	if (this->handle == NULL) {
		std::cout << this->errbuf << std::endl;
		exit(1);
	}
}

u_long PcapAdapter::getNextIP() {
	const u_char *packet;
	const struct sniff_ethernet *ethernet;
	const struct sniff_ip *ip;
	if ((packet = pcap_next(this->handle, &this->header)) != NULL) {
		ethernet = (struct sniff_ethernet *)(packet);
		ip = (struct sniff_ip *)(packet + SIZE_ETHERNET);
		return ip->ip_src.S_un.S_addr;
	}
	return NULL;
}