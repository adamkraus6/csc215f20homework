#include "sortedSingle.h"

/*
Due 10/22 11:59pm

functions in this file:
remove
clear
*/

bool sortedSingle::remove(int item)
{
    if (empty() || find(item) == 0) return false;
    node* curr;
    node* next;
    curr = headptr;
    int pos = 1;

    if (curr->theItem == item)
    {
        // remove from front
        headptr = curr->next;
        delete curr;
        return true;
    }

    if (size() == retrievePosition(item))
    {
        // remove from end

        // move to second to last
        while (pos < size() - 1)
        {
            curr = curr->next;
            pos++;
        }

        delete curr->next;
        curr->next = nullptr;
        return true;
    }
    else {
        // remove from middle
        while (curr->next != nullptr)
        {
            if (curr->next->theItem == item)
            {
                next = curr->next;
                curr->next = next->next;
                delete next;
                next = nullptr;
                return true;
            }
            else {
                curr = curr->next;
            }
        }
    }

    return false;
}

void sortedSingle::clear()
{
    if (empty()) return;
    node* curr;
    node* next;
    curr = headptr;

    while(curr != nullptr)
    {
        next = curr->next;

        delete curr;

        curr = next;
    }

    headptr = nullptr;
}