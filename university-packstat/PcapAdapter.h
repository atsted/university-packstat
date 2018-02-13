#pragma once

#include <iostream>
#include <pcap.h>
#include <WinSock2.h>

#include "Packet.h"

#define SIZE_ETHERNET	14
#define DUMP_FILE		"Captured/sun_tcpdump.log"


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
	in_addr *getNextIP();
};

