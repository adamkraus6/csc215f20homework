#include "sortedSingle.h"
#include "..\catch.hpp"
#include <sstream>
#include <iostream>

using namespace std;

TEST_CASE("constructor")
{
    sortedSingle list1;
    REQUIRE(list1.empty() == true);
    REQUIRE(list1.size() == 0);
}

TEST_CASE("destructor")
{
    sortedSingle list1;
    list1.~sortedSingle();

    REQUIRE(list1.empty() == true);
}

TEST_CASE("empty")
{
    sortedSingle list1;
    REQUIRE(list1.empty() == true);
}

TEST_CASE("size")
{
    sortedSingle list1;
    REQUIRE(list1.size() == 0);

    sortedSingle list2;
    list2.insert(10);
    list2.insert(15);
    list2.insert(25);
    list2.insert(40);
    REQUIRE(list2.size() == 4);

    list2.clear();
    REQUIRE(list2.size() == 0);
}

TEST_CASE("find")
{
    sortedSingle list1;
    REQUIRE(list1.find(10) == false);

    sortedSingle list2;
    list2.insert(10);
    list2.insert(15);
    list2.insert(25);
    list2.insert(40);
    REQUIRE(list2.find(10) == true);
    REQUIRE(list2.find(40) == true);
    REQUIRE(list2.find(20) == false);

    list2.clear();
    REQUIRE(list2.find(10) == false);
}

TEST_CASE("retrieve position")
{
    sortedSingle list1;
    REQUIRE(list1.retrievePosition(10) == 0);

    sortedSingle list2;
    list2.insert(10);
    list2.insert(15);
    list2.insert(25);
    list2.insert(40);
    REQUIRE(list2.retrievePosition(10) == 1);
    REQUIRE(list2.retrievePosition(40) == 4);
    REQUIRE(list2.retrievePosition(20) == 0);

    list2.clear();
    REQUIRE(list2.retrievePosition(10) == 0);
}

TEST_CASE("print")
{
    ostringstream o;
    sortedSingle list1;
    
    SECTION("default")
    {
        list1.insert(5);
        list1.insert(15);
        list1.insert(10);
        list1.insert(50);

        list1.print(o);
        REQUIRE(o.str() == "5, 10, 15, 50");
    }

    SECTION("comma with no space")
    {
        list1.insert(5);
        list1.insert(10);
        list1.insert(25);
        list1.insert(5);
        list1.insert(15);
        list1.insert(1);
        list1.insert(45);

        list1.print(o, ",");
        REQUIRE(o.str() == "1,5,5,10,15,25,45");
    }

    SECTION("double spaces")
    {
        list1.insert(10);
        list1.insert(20);
        list1.insert(30);
        list1.insert(40);
        list1.insert(50);

        list1.print(o, "  ");
        REQUIRE(o.str() == "10  20  30  40  50");
    }

    SECTION("newline")
    {
        list1.insert(5);
        list1.insert(25);
        list1.insert(15);
        list1.insert(20);
        list1.insert(40);

        list1.print(o, "\n");
        REQUIRE(o.str() == "5\n15\n20\n25\n40");
    }
}

TEST_CASE("insert")
{
    ostringstream o;
    sortedSingle list1;

    SECTION("empty")
    {
        REQUIRE(list1.insert(10) == true);
        list1.print(o);
        REQUIRE(o.str() == "10");
    }
    
    SECTION("front")
    {
        REQUIRE(list1.insert(10) == true);
        REQUIRE(list1.insert(5) == true);
        list1.print(o);
        REQUIRE(o.str() == "5, 10");
    }

    SECTION("end")
    {
        REQUIRE(list1.insert(5) == true);
        REQUIRE(list1.insert(10) == true);
        REQUIRE(list1.insert(20) == true);
        list1.print(o);
        REQUIRE(o.str() == "5, 10, 20");
    }

    SECTION("middle")
    {
        REQUIRE(list1.insert(5) == true);
        REQUIRE(list1.insert(20) == true);
        REQUIRE(list1.insert(10) == true);
        REQUIRE(list1.insert(15) == true);
        list1.print(o);
        REQUIRE(o.str() == "5, 10, 15, 20");
    }
    
    SECTION("duplicate")
    {
        REQUIRE(list1.insert(5) == true);
        REQUIRE(list1.insert(20) == true);
        REQUIRE(list1.insert(10) == true);
        REQUIRE(list1.insert(15) == true);

        REQUIRE(list1.insert(5) == true);
        REQUIRE(list1.insert(20) == true);
        REQUIRE(list1.insert(10) == true);
    }

    SECTION("mixture")
    {
        REQUIRE(list1.insert(15) == true);
        REQUIRE(list1.insert(25) == true);
        REQUIRE(list1.insert(20) == true);
        REQUIRE(list1.insert(5) == true);
        REQUIRE(list1.insert(50) == true);
        REQUIRE(list1.insert(1) == true);
        REQUIRE(list1.insert(45) == true);
    }
}

TEST_CASE("remove")
{
    sortedSingle list1, list2;
    ostringstream o, o2;
    REQUIRE(list1.insert(5) == true);
    REQUIRE(list1.insert(10) == true);
    REQUIRE(list1.insert(15) == true);
    REQUIRE(list1.insert(50) == true);

    SECTION("front")
    {
        REQUIRE(list1.remove(5) == true);
        list1.print(o);
        REQUIRE(o.str() == "10, 15, 50");
        REQUIRE(list1.remove(10) == true);
        list1.print(o2);
        REQUIRE(o2.str() == "15, 50");
    }

    SECTION("end")
    {
        REQUIRE(list1.remove(50) == true);
        list1.print(o);
        REQUIRE(o.str() == "5, 10, 15");
        REQUIRE(list1.remove(15) == true);
        list1.print(o2);
        REQUIRE(o2.str() == "5, 10");
    }

    SECTION("middle")
    {
        REQUIRE(list1.remove(10) == true);
        REQUIRE(list1.remove(15) == true);
        list1.print(o);
        REQUIRE(o.str() == "5, 50");
    }

    SECTION("empty")
    {
        REQUIRE(list2.remove(10) == false);
        list1.clear();
        REQUIRE(list1.remove(10) == false);
    }

    SECTION("duplicates")
    {
        REQUIRE(list1.insert(10) == true);
        list1.print(o);
        REQUIRE(o.str() == "5, 10, 10, 15, 50");
        REQUIRE(list1.remove(10) == true);
        list1.print(o2);
        REQUIRE(o2.str() == "5, 10, 15, 50");
    }
}

TEST_CASE("clear")
{
    sortedSingle list1;
    ostringstream o;

    SECTION("empty")
    {
        list1.clear();
        list1.print(o);
        REQUIRE(o.str() == "");
    }

    SECTION("one element")
    {
        REQUIRE(list1.insert(10) == true);
        list1.clear();
        list1.print(o);
        REQUIRE(o.str() == "");
    }

    SECTION("multiple elements")
    {
        REQUIRE(list1.insert(10) == true);
        REQUIRE(list1.insert(25) == true);
        REQUIRE(list1.insert(15) == true);
        REQUIRE(list1.insert(5) == true);
        list1.clear();
        list1.print(o);
        REQUIRE(o.str() == "");
    }

    SECTION("clear and then insert")
    {
        REQUIRE(list1.insert(10) == true);
        REQUIRE(list1.insert(25) == true);
        REQUIRE(list1.insert(15) == true);
        REQUIRE(list1.insert(5) == true);
        list1.clear();
        list1.print(o);
        REQUIRE(o.str() == "");

        REQUIRE(list1.insert(15) == true);
        REQUIRE(list1.insert(5) == true);
    }
}