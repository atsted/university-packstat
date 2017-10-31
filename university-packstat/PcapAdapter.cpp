#include "PcapAdapter.h"

PcapAdapter::PcapAdapter() {}

PcapAdapter::~PcapAdapter() {
	pcap_close(this->handle);
}

void PcapAdapter::open() {
	this->handle = pcap_open_offline("dump.pcap", this->errbuf);
	if (this->handle == NULL) {
		std::cout << this->errbuf << std::endl;
		exit(1);
	}
}

char *PcapAdapter::getNextIP() {
	const u_char *packet;
	const struct sniff_ethernet *ethernet;
	const struct sniff_ip *ip;
	packet = pcap_next(this->handle, &this->header);
	ethernet = (struct sniff_ethernet *)(packet);
	ip = (struct sniff_ip *)(packet + SIZE_ETHERNET);
	return inet_ntoa(ip->ip_src);
}