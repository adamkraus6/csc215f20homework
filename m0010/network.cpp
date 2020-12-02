#include "network.h"

ip compressOctets(octet oct1, octet oct2, octet oct3, octet oct4) {
    ip address = oct1;
    address <<= 8;
    address |= oct2;
    address <<= 8;
    address |= oct3;
    address <<= 8;
    address |= oct4;


    return address;
}

void extractOctets(ip address, octet& oct1, octet& oct2, octet& oct3, octet& oct4) {
    ip add = address;
    int mask = 0xFF;
    oct4 = octet(add) & mask;
    add >>= 8;
    oct3 = octet(add) & mask;
    add >>= 8;
    oct2 = octet(add) & mask;
    add >>= 8;
    oct1 = add;
}


networkType getNetworkType(ip address) {
    octet oct1 = 0, oct2 = 0, oct3 = 0, oct4 = 0;
    extractOctets(address, oct1, oct2, oct3, oct4);

    if (oct1 == 0) {
        return INVALID; // 0
    }
    else if (oct1 >= 0 && oct1 <= 127) {
        //class A
        if (oct1 == 10) return APRIVATE; // 2
        if (oct1 == 127) return LOCALHOST; // 3
        return CLASSA; // 1
    }
    else if (oct1 >= 128 && oct1 <= 191) {
        //class B
        if (oct1 == 172 && (oct2 >= 16 && oct2 <= 31)) return BPRIVATE; // 5
        return CLASSB; // 4
    }
    else if (oct1 >= 192 && oct1 <= 223) {
        //class C
        if (oct1 == 192 && oct2 == 168) return CPRIVATE; // 7
        return CLASSC; // 6
    }
    else if (oct1 >= 224 && oct1 <= 239) {
        //class D
        return CLASSD; // 8
    }
    else {
        //class E
        return CLASSE; // 9
    }
}