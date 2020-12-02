/** ***************************************************************************
 * @file
 *
 * @brief   Implements my Queue classes copy constructor.
 *****************************************************************************/
#include "myQueue.h"


/** ***************************************************************************
 * @brief   Copy from one Queue to another at instantiation time.
 *
 * @param [in,out]  q   A Queue to be duplicate.
 *****************************************************************************/
Queue::Queue( Queue &q )
{
    node* src;
    node* dest;
    headptr = nullptr;

    if (q.empty()) return;

    headptr = new (nothrow) node();
    if (headptr == nullptr)
    {
        exit(1);
    }

    headptr->item = q.headptr->item;
    headptr->next = nullptr;

    src = q.headptr->next;
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
}


