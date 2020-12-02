#include "trim.h"
#include "..\catch.hpp"

// cTrim Test Cases
TEST_CASE("cTrim - C String with front WS")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    char theString[100] = "    Catch with Sections!";
    char theAnswer[100] = "Catch with Sections!";

    // variables reinitialize and checked
    SECTION("Front -  Just a phrase")
    {
        cTrim(theString, FRONT);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
}

TEST_CASE("cTrim - C String with end WS")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    char theString[100] = "Catch with Sections!    ";
    char theAnswer[100] = "Catch with Sections!";

    // variables reinitialize and checked
    SECTION("End -  Just a phrase")
    {
        cTrim(theString, END);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
}

TEST_CASE("cTrim - C String with both WS")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    char theString[100] = "    Catch with Sections!    ";
    char theAnswer[100] = "Catch with Sections!";

    // variables reinitialize and checked
    SECTION("Both -  Just a phrase")
    {
        cTrim(theString, FRONT);
        cTrim(theString, END);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
    // variables reinitialize and checked
    SECTION("Both -  Just a phrase")
    {
        cTrim(theString, BOTH);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
}

TEST_CASE("sTrim - C Strings with all WS")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    char theString[100] = "       ";
    char theAnswer[100] = "";

    // variables reinitialize and checked
    SECTION("Front - Just a phrase")
    {
        cTrim(theString, FRONT);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
    // variables reinitialize and checked
    SECTION("End - Just a phrase")
    {
        cTrim(theString, END);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
    // variables reinitialize and checked
    SECTION("Both - Just a phrase")
    {
        cTrim(theString, BOTH);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
}

TEST_CASE("cTrim - C Strings with empty string")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    char theString[100] = "";
    char theAnswer[100] = "";

    // variables reinitialize and checked
    SECTION("Front - Just a phrase")
    {
        cTrim(theString, FRONT);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
    // variables reinitialize and checked
    SECTION("End - Just a phrase")
    {
        cTrim(theString, END);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
    // variables reinitialize and checked
    SECTION("Both - Just a phrase")
    {
        cTrim(theString, BOTH);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
}

// sTrim Test Cases
TEST_CASE("sTrim - C++ Strings with front WS")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    string theString = "   Catch with Sections!";
    string theAnswer = "Catch with Sections!";

    // variables reinitialize and checked
    SECTION("Front -  Just a phrase")
    {
        sTrim(theString, FRONT);
        CHECK(theAnswer == theString);
    }
    // variables reinitialize and checked
    SECTION("Front - Just a phrase")
    {
        sTrim(theString, BOTH);
        CHECK(theAnswer == theString);
    }
}

TEST_CASE("sTrim - C++ Strings with end WS")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    string theString = "Catch with Sections!   ";
    string theAnswer = "Catch with Sections!";

    // variables reinitialize and checked
    SECTION("End - Just a phrase")
    {
        sTrim(theString, END);
        CHECK(theAnswer == theString);
    }
    // variables reinitialize and checked
    SECTION("End - Just a phrase")
    {
        sTrim(theString, BOTH);
        CHECK(theAnswer == theString);
    }
}

TEST_CASE("sTrim - C++ Strings with both WS")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    string theString = "    Catch with Sections!   ";
    string theAnswer = "Catch with Sections!";

    // variables reinitialize and checked
    SECTION("Both - Just a phrase")
    {
        sTrim(theString, BOTH);
        CHECK(theAnswer == theString);
    }
    // variables reinitialize and checked
    SECTION("Both - Just a phrase")
    {
        sTrim(theString, FRONT);
        sTrim(theString, END);
        CHECK(theAnswer == theString);
    }
}

TEST_CASE("sTrim - C++ Strings with all WS")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    string theString = "       ";
    string theAnswer = "";

    // variables reinitialize and checked
    SECTION("Front - Just a phrase")
    {
        sTrim(theString, FRONT);
        CHECK(theAnswer == theString);
    }
    // variables reinitialize and checked
    SECTION("End - Just a phrase")
    {
        sTrim(theString, END);
        CHECK(theAnswer == theString);
    }
    // variables reinitialize and checked
    SECTION("Both - Just a phrase")
    {
        sTrim(theString, BOTH);
        CHECK(theAnswer == theString);
    }
}

TEST_CASE("sTrim - C++ Strings with empty string")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    string theString = "";
    string theAnswer = "";

    // variables reinitialize and checked
    SECTION("Front - Just a phrase")
    {
        sTrim(theString, FRONT);
        CHECK(theAnswer == theString);
    }
    // variables reinitialize and checked
    SECTION("End - Just a phrase")
    {
        sTrim(theString, END);
        CHECK(theAnswer == theString);
    }
}

// Example Test Cases
TEST_CASE("cTrim - Testing C strings with no ws on either end")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    char theString[100] = "Catch with Sections!";
    char theAnswer[100] = "Catch with Sections!";
    CHECK(strcmp(theString, theAnswer) == 0);

    // variables reinitialize and checked
    SECTION("Front -  Just a phrase")
    {
        cTrim(theString, FRONT);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
    // variables reinitialize and checked
    SECTION("End -  Just a phrase")
    {
        cTrim(theString, END);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
    // variables reinitialize and checked
    SECTION("BOTH - Just a phrase")
    {
        cTrim(theString, BOTH);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
}

TEST_CASE("sTrim - Testing strings with no ws on either end")
{
    // These variable will be initialized and any REQUIRE/CHECK 
    // executed before each section below.
    string theString = "Catch with Sections!";
    string theAnswer = "Catch with Sections!";
    CHECK(theString == theAnswer);

    // variables reinitialize and checked
    SECTION("Front -  Just a phrase")
    {
        sTrim(theString, FRONT);
        CHECK(theAnswer == theString);
    }
    // variables reinitialize and checked
    SECTION("End - Just a phrase")
    {
        sTrim(theString, END);
        CHECK(theAnswer == theString);
    }
    // variables reinitialize and checked
    SECTION("BOTH - Just a phrase")
    {
        sTrim(theString, BOTH);
        CHECK(theAnswer == theString);
    }
}