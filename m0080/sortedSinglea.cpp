#include "sortedSingle.h"

/*
Due 10/15 11:59pm

functions in this file:
default constructor
destructor
empty()
size
find
retrievePosition
*/

sortedSingle::sortedSingle()
{
    headptr = nullptr;
}

sortedSingle::~sortedSingle()
{
    clear();
    headptr = nullptr;
}

bool sortedSingle::empty()
{
    if (headptr == nullptr)
    {
        return true;
    }

    return false;
}

int sortedSingle::size() {
    node* temp = headptr;
    int size = 0;

    while (temp != nullptr)
    {
        size++;
        temp = temp->next;
    }

    return size;
}

bool sortedSingle::find(int item)
{
    int pos = retrievePosition(item);
    if (pos != 0) return true;

    return false;
}

int sortedSingle::retrievePosition(int item)
{
    node* temp = headptr;
    int pos = 1;

    while (temp != nullptr)
    {
        if (temp->theItem == item)
        {
            return pos;
        }
        else {
            pos++;
            temp = temp->next;
        }
    }

    return 0;
}