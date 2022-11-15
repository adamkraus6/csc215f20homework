#ifndef __NETWORK__H__
#define __NETWORK__H__

// write prototypes, typedefs and enumerated types here

enum networkType {INVALID, CLASSA, APRIVATE, LOCALHOST, CLASSB, BPRIVATE, CLASSC, CPRIVATE, CLASSD, CLASSE};

typedef unsigned short int octet;
typedef unsigned int ip;

ip compressOctets(octet oct1, octet oct2, octet oct3, octet oct4);

void extractOctets(ip address, octet& oct1, octet& oct2, octet& oct3, octet& oct4);

networkType getNetworkType(ip address);

#endif