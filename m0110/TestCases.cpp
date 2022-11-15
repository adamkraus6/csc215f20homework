/** ***************************************************************************
 * @file    
 *
 * @brief   Where a students test cases will be written for the enqueue,
 *          dequeue, front and copy constructor member functions.
 *       
 *****************************************************************************/
#include "..\catch.hpp"
#include <sstream>
#include "myQueue.h"

using namespace std;

void printQueue( Queue q, ostream &out );


//write your test cases here
TEST_CASE("enqueue - empty queue")
{
    Queue q;
    ostringstream o;

    REQUIRE(q.enqueue("one") == true);
    q.print(o);
    REQUIRE(o.str() == "one");
}

TEST_CASE("enqueue - many items")
{
    Queue q;
    ostringstream o;

    REQUIRE(q.enqueue("one") == true);
    REQUIRE(q.enqueue("two") == true);
    REQUIRE(q.enqueue("three") == true);
    q.print(o);
    REQUIRE(o.str() == "one, two, three");
}

TEST_CASE("dequeue - empty")
{
    Queue q;
    ostringstream o;
    string word;

    REQUIRE(q.dequeue(word) == false);
}

TEST_CASE("dequeue - single item")
{
    Queue q;
    ostringstream o;
    string word;

    REQUIRE(q.enqueue("one") == true);
    REQUIRE(q.dequeue(word) == true);

    q.print(o);
    REQUIRE(o.str() == "");
    REQUIRE(word == "one");
}

TEST_CASE("dequeue - many items")
{
    Queue q;
    ostringstream o;
    string word;

    REQUIRE(q.enqueue("three") == true);
    REQUIRE(q.enqueue("two") == true);
    REQUIRE(q.enqueue("one") == true);
    REQUIRE(q.dequeue(word) == true);

    q.print(o);
    REQUIRE(o.str() == "two, one");
    REQUIRE(word == "three");
}

TEST_CASE("front - empty")
{
    Queue q;
    string word;

    q.front(word);
    REQUIRE(word == "");
}

TEST_CASE("front - many")
{
    Queue q;
    string word;

    SECTION("one, two, three")
    {
        REQUIRE(q.enqueue("one") == true);
        REQUIRE(q.enqueue("two") == true);
        REQUIRE(q.enqueue("three") == true);

        q.front(word);
        REQUIRE(word == "one");
    }

    SECTION("three, two, one")
    {
        REQUIRE(q.enqueue("three") == true);
        REQUIRE(q.enqueue("two") == true);
        REQUIRE(q.enqueue("one") == true);

        q.front(word);
        REQUIRE(word == "three");
    }
}

TEST_CASE("copy con - empty")
{
    Queue q;
    ostringstream o, o2;

    printQueue(q, o);
    REQUIRE(o.str() == "");
    q.print(o2);
    REQUIRE(o2.str() == "");
}

TEST_CASE("copy con - single")
{
    Queue q;
    ostringstream o, o2;

    REQUIRE(q.enqueue("one") == true);
    printQueue(q, o);
    REQUIRE(o.str() == "one");
    q.print(o2);
    REQUIRE(o2.str() == "one");
}

TEST_CASE("copy con - many")
{
    Queue q;
    ostringstream o, o2;

    REQUIRE(q.enqueue("one") == true);
    REQUIRE(q.enqueue("two") == true);
    REQUIRE(q.enqueue("three") == true);

    printQueue(q, o);
    REQUIRE(o.str() == "one, two, three");
    q.print(o2);
    REQUIRE(o2.str() == "one, two, three");
}

void printQueue( Queue q, ostream &out )
{
    // write the code to print a queue to the screen destroying the
    // contents of the queue when done. It is pass by value.
    
    string word;

    while (q.size() > 0)
    {
        q.dequeue(word);
        out << word;
        if (q.size() > 0) out << ", ";
    }
}

TEST_CASE("operator=")
{
    Queue q1, q2;
    ostringstream o1, o2;

    SECTION("empty")
    {
        q1 = q2;
        q1.print(o1);
        q2.print(o2);
        REQUIRE(o1.str() == o2.str());
    }

    SECTION("many elements")
    {
        REQUIRE(q2.enqueue("one") == true);
        REQUIRE(q2.enqueue("two") == true);
        REQUIRE(q2.enqueue("three") == true);

        q1 = q2;
        q1.print(o1);
        q2.print(o2);
        REQUIRE(o1.str() == o2.str());
    }
}

TEST_CASE("operator==")
{
    Queue q1, q2;
    ostringstream o1, o2;

    SECTION("empty")
    {
        REQUIRE((q1 == q2) == true);
    }

    SECTION("different lengths")
    {
        REQUIRE(q1.enqueue("one") == true);
        REQUIRE(q1.enqueue("two") == true);
        REQUIRE(q1.enqueue("three") == true);

        REQUIRE(q2.enqueue("four") == true);
        REQUIRE(q2.enqueue("five") == true);

        q1.print(o1);
        q2.print(o2);
        REQUIRE(o1.str() != o2.str());

        REQUIRE((q1 == q2) == false);
    }

    SECTION("same elements")
    {
        REQUIRE(q1.enqueue("one") == true);
        REQUIRE(q1.enqueue("two") == true);
        REQUIRE(q1.enqueue("three") == true);

        REQUIRE(q2.enqueue("one") == true);
        REQUIRE(q2.enqueue("two") == true);
        REQUIRE(q2.enqueue("three") == true);

        q1.print(o1);
        q2.print(o2);
        REQUIRE(o1.str() == o2.str());

        REQUIRE((q1 == q2) == true);
    }

    SECTION("different elements")
    {
        REQUIRE(q1.enqueue("one") == true);
        REQUIRE(q1.enqueue("two") == true);
        REQUIRE(q1.enqueue("three") == true);

        REQUIRE(q2.enqueue("four") == true);
        REQUIRE(q2.enqueue("five") == true);
        REQUIRE(q2.enqueue("six") == true);

        q1.print(o1);
        q2.print(o2);
        REQUIRE(o1.str() != o2.str());

        REQUIRE((q1 == q2) == false);
    }
}

TEST_CASE("operator!=")
{
    Queue q1, q2;
    ostringstream o1, o2;

    SECTION("empty")
    {
        REQUIRE((q1 != q2) == false);
    }

    SECTION("different lengths")
    {
        REQUIRE(q1.enqueue("one") == true);
        REQUIRE(q1.enqueue("two") == true);
        REQUIRE(q1.enqueue("three") == true);

        REQUIRE(q2.enqueue("four") == true);
        REQUIRE(q2.enqueue("five") == true);

        q1.print(o1);
        q2.print(o2);
        REQUIRE(o1.str() != o2.str());

        REQUIRE((q1 != q2) == true);
    }

    SECTION("same elements")
    {
        REQUIRE(q1.enqueue("one") == true);
        REQUIRE(q1.enqueue("two") == true);
        REQUIRE(q1.enqueue("three") == true);

        REQUIRE(q2.enqueue("one") == true);
        REQUIRE(q2.enqueue("two") == true);
        REQUIRE(q2.enqueue("three") == true);

        q1.print(o1);
        q2.print(o2);
        REQUIRE(o1.str() == o2.str());

        REQUIRE((q1 != q2) == false);
    }

    SECTION("different elements")
    {
        REQUIRE(q1.enqueue("one") == true);
        REQUIRE(q1.enqueue("two") == true);
        REQUIRE(q1.enqueue("three") == true);

        REQUIRE(q2.enqueue("four") == true);
        REQUIRE(q2.enqueue("five") == true);
        REQUIRE(q2.enqueue("six") == true);

        q1.print(o1);
        q2.print(o2);
        REQUIRE(o1.str() != o2.str());

        REQUIRE((q1 != q2) == true);
    }
}