/** ***************************************************************************
 * @file    
 *
 * @brief   Implements the dequeue and front functions of the Queue class.
 *****************************************************************************/
#include "myQueue.h"


/** ***************************************************************************
 * @brief   Removes the head object from this Queue
 *
 * @author  Roger L. Schrader
 * @date    10/28/2020
 *
 * @param [in,out]  word    The word that was removed if it exists
 *
 * @returns True if it succeeds in removing a word, false if it fails.
 *****************************************************************************/
bool Queue::dequeue( string &word )
{
    node* oldHead = headptr;
    if (empty()) return false;
    
    word = oldHead->item;
    headptr = oldHead->next;
    delete oldHead;
    if (headptr == nullptr) tailptr = nullptr;

    return true;
}


/** ***************************************************************************
 * @brief   Get the first word in the Queue
 *
 * @param [in,out]  word    The word at the beginning of the Queue.
 *
 * @returns True if it succeeds and a word is at the front, false if it fails.
 *****************************************************************************/
bool Queue::front( string &word )
{
    node* head = headptr;
    if (empty()) return false;

    word = head->item;

    return true;
}
