#include "myQueue.h"

Queue& Queue::operator=(Queue& rhs)
{
    if (headptr == rhs.headptr) return rhs;
    clear();
    
    node* src;
    node* dest;

    headptr = new (nothrow) node();
    if (headptr == nullptr)
    {
        exit(1);
    }

    headptr->item = rhs.headptr->item;
    headptr->next = nullptr;

    src = rhs.headptr->next;
    dest = headptr;

    while (src != nullptr)
    {
        dest->next = new (nothrow) node();
        if (dest->next == nullptr)
        {
            exit(1);
        }

        dest = dest->next;

        dest->item = src->item;
        dest->next = nullptr;

        src = src->next;
    }

    tailptr = dest;

    return rhs;
}

bool Queue::operator==(Queue& rhs)
{
    if (size() != rhs.size()) return false;
    node* dest = headptr;
    node* src = rhs.headptr;

    while (src != nullptr && dest != nullptr)
    {
        if (dest->item != src->item)
        {
            return false;
        }

        dest = dest->next;
        src = src->next;
    }


    return true;
}

bool Queue::operator!=(Queue& rhs)
{
    if (size() != rhs.size()) return true;
    node* dest = headptr;
    node* src = rhs.headptr;

    while (src != nullptr && dest != nullptr)
    {
        if (dest->item != src->item)
        {
            return true;
        }

        dest = dest->next;
        src = src->next;
    }

    return false;
}