#include "sortedSingle.h"

/*
Due 10/19 11:59pm

functions in this file:
insert
print
*/

bool sortedSingle::insert(int item)
{
    node* temp = new (nothrow) node();
    node* temp2;
    temp->theItem = item;

    if (empty())
    {
        // insert to empty
        headptr = temp;
        return true;
    }
    else {
        if (item < headptr->theItem)
        {
            // insert to front
            temp2 = headptr;
            headptr = temp;
            temp->next = temp2;
            return true;
        }
        else {
            temp2 = headptr;
            while ( temp2->next != nullptr && temp2->next->theItem < item)
            {
                temp2 = temp2->next;
            }

            if (temp2->next == nullptr)
            {
                // insert to end
                temp2->next = temp;
                return true;
            }
            else {
                // insert to middle
                temp->next = temp2->next;
                temp2->next = temp;
                return true;
            }
        }
    }

    return false;
}

void sortedSingle::print(ostream& out, string seperator)
{
    if (empty()) return;
    node* temp = headptr;

    while (temp != nullptr)
    {
        out << temp->theItem;
        if (temp->next != nullptr)
        {
            out << seperator;
        }

        temp = temp->next;
    }
}