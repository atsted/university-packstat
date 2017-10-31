#pragma once

#include <iostream>
#include <pcap.h>
#include <WinSock2.h>

#include "Packet.h"

#define SIZE_ETHERNET 14


class PcapAdapter
{
private:
	char errbuf[PCAP_BUF_SIZE];
	struct pcap_pkthdr header;
	pcap_t *handle;

public:
	PcapAdapter();
	~PcapAdapter();
	void open();
	char *getNextIP();
};

