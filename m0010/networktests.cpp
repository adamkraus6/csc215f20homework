#include "..\\catch.hpp"
#include "network.h"

// compressOctets test cases
TEST_CASE("compressOctets - testing a class a ip address (instructor example)") {
    octet oct1 = 97, oct2 = 184, oct3 = 254, oct4 = 185;
    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(1639513785 == resultIP);
}

TEST_CASE("compressOctets - testing a class b ip address") {
    octet oct1 = 151, oct2 = 159, oct3 = 15, oct4 = 20;
    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(2543783700 == resultIP);
}

TEST_CASE("compressOctets - testing a class b ip address #2") {
    octet oct1 = 129, oct2 = 191, oct3 = 161, oct4 = 118;
    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(2176819574 == resultIP);
}

TEST_CASE("compressOctets - testing a class c ip address") {
    octet oct1 = 218, oct2 = 47, oct3 = 141, oct4 = 78;
    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(3660549454 == resultIP);
}

TEST_CASE("compressOctets - testing a class d ip address") {
    octet oct1 = 232, oct2 = 13, oct3 = 65, oct4 = 80;
    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(3893182800 == resultIP);
}

TEST_CASE("compressOctets - testing a class e ip address") {
    octet oct1 = 249, oct2 = 145, oct3 = 242, oct4 = 15;
    ip resultIP = compressOctets(oct1, oct2, oct3, oct4);

    REQUIRE(4187091471  == resultIP);
}

// extractOctets test cases
TEST_CASE("extractOctets - testing a class b ip to octet v1 (instructor example)") {
    ip theIP = 2543783700; // from above
    octet oct1 = 0, oct2 = 0, oct3 = 0, oct4 = 0;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(151 == oct1);
    CHECK(159 == oct2);
    CHECK(15 == oct3);
    CHECK(20 == oct4);
}

TEST_CASE("extractOctets - testing a class b ip to octet v2 (instructor example)") {
    ip theIP = compressOctets(151, 159, 15, 20);
    octet oct1 = 0, oct2 = 0, oct3 = 0, oct4 = 0;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(151 == oct1);
    CHECK(159 == oct2);
    CHECK(15 == oct3);
    CHECK(20 == oct4);
}

TEST_CASE("extractOctets - testing a class A ip to octet v1") {
    ip theIP = 1639513785;
    octet oct1 = 0, oct2 = 0, oct3 = 0, oct4 = 0;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(97 == oct1);
    CHECK(184 == oct2);
    CHECK(254 == oct3);
    CHECK(185 == oct4);
}

TEST_CASE("extractOctets - testing a class B ip to octet v2") {
    ip theIP = compressOctets(139, 158, 218, 109);
    octet oct1 = 0, oct2 = 0, oct3 = 0, oct4 = 0;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(139 == oct1);
    CHECK(158 == oct2);
    CHECK(218 == oct3);
    CHECK(109 == oct4);
}

TEST_CASE("extractOctets - testing a class C ip to octet v1") {
    ip theIP = 3660549454;
    octet oct1 = 0, oct2 = 0, oct3 = 0, oct4 = 0;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(218 == oct1);
    CHECK(47 == oct2);
    CHECK(141 == oct3);
    CHECK(78 == oct4);
}

TEST_CASE("extractOctets - testing a class D ip to octet v2") {
    ip theIP = compressOctets(232, 13, 65, 80);
    octet oct1 = 0, oct2 = 0, oct3 = 0, oct4 = 0;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(232 == oct1);
    CHECK(13 == oct2);
    CHECK(65 == oct3);
    CHECK(80 == oct4);
}

TEST_CASE("extractOctets - testing a class E ip to octet v1") {
    ip theIP = 4187091471;
    octet oct1 = 0, oct2 = 0, oct3 = 0, oct4 = 0;

    extractOctets(theIP, oct1, oct2, oct3, oct4);
    CHECK(249 == oct1);
    CHECK(145 == oct2);
    CHECK(242 == oct3);
    CHECK(15 == oct4);
}

// getNetworkType test cases
TEST_CASE("getNetworkType - classifying a class B network including private (instructor example)") {
    ip i = compressOctets(151, 159, 15, 20);
    networkType c = getNetworkType(i);
    REQUIRE(c == CLASSB);

    i = compressOctets(172, 18, 4, 20);
    c = getNetworkType(i);
    REQUIRE(c == BPRIVATE);
}

TEST_CASE("getNetworkType - classifying an invalid network") {
    ip i = compressOctets(0, 243, 188, 142);
    networkType c = getNetworkType(i);
    REQUIRE(c == INVALID);

    i = compressOctets(0, 188, 112, 25);
    c = getNetworkType(i);
    REQUIRE(c == INVALID);
}

TEST_CASE("getNetworkType - classifying a class A network") {
    ip i = compressOctets(4, 208, 194, 254);
    networkType c = getNetworkType(i);
    REQUIRE(c == CLASSA);

    i = compressOctets(7, 192, 44, 229);
    c = getNetworkType(i);
    REQUIRE(c == CLASSA);
}

TEST_CASE("getNetworkType - classifying a class A private network") {
    ip i = compressOctets(10, 171, 218, 87);
    networkType c = getNetworkType(i);
    REQUIRE(c == APRIVATE);

    i = compressOctets(10, 233, 222, 225);
    c = getNetworkType(i);
    REQUIRE(c == APRIVATE);
}

TEST_CASE("getNetworkType - classifying a localhost network") {
    ip i = compressOctets(127, 253, 158, 27);
    networkType c = getNetworkType(i);
    REQUIRE(c == LOCALHOST);

    i = compressOctets(127, 236, 18, 165);
    c = getNetworkType(i);
    REQUIRE(c == LOCALHOST);
}

TEST_CASE("getNetworkType - classifying a class B network") {
    ip i = compressOctets(155, 208, 199, 233);
    networkType c = getNetworkType(i);
    REQUIRE(c == CLASSB);

    i = compressOctets(187, 184, 39, 123);
    c = getNetworkType(i);
    REQUIRE(c == CLASSB);
}

TEST_CASE("getNetworkType - classifying a class B private network") {
    ip i = compressOctets(172, 27, 232, 131);
    networkType c = getNetworkType(i);
    REQUIRE(c == BPRIVATE);

    i = compressOctets(172, 17, 180, 141);
    c = getNetworkType(i);
    REQUIRE(c == BPRIVATE);
}

TEST_CASE("getNetworkType - classifying a class C network") {
    ip i = compressOctets(200, 49, 9, 243);
    networkType c = getNetworkType(i);
    REQUIRE(c == CLASSC);

    i = compressOctets(223, 160, 99, 232);
    c = getNetworkType(i);
    REQUIRE(c == CLASSC);
}

TEST_CASE("getNetworkType - classifying a class C private network") {
    ip i = compressOctets(192, 168, 4, 28);
    networkType c = getNetworkType(i);
    REQUIRE(c == CPRIVATE);

    i = compressOctets(192, 168, 133, 39);
    c = getNetworkType(i);
    REQUIRE(c == CPRIVATE);
}

TEST_CASE("getNetworkType - classifying a class D network") {
    ip i = compressOctets(235, 183, 251, 106);
    networkType c = getNetworkType(i);
    REQUIRE(c == CLASSD);

    i = compressOctets(224, 158, 109, 137);
    c = getNetworkType(i);
    REQUIRE(c == CLASSD);
}

TEST_CASE("getNetworkType - classifying a class E network") {
    ip i = compressOctets(241, 117, 236, 199);
    networkType c = getNetworkType(i);
    REQUIRE(c == CLASSE);

    i = compressOctets(255, 255, 255, 255);
    c = getNetworkType(i);
    REQUIRE(c == CLASSE);
}