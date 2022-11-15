#include "trim.h"

/*
This will be a non-valued function that will have two arguments. The first argument is a c style string
and the second argument will be the enumerated value for the method. If the method is equal to
FRONT, you will remove all whitespace from the beginning of the c string. If the method is equal to END,
you will remove all whitespace from the back of the c string. If the method is equal to BOTH, you will
remove all whitespace from both ends of the c string.

1. You must use the isspace function that is in the cctype library for detecting characters that are a
whitespace character.
2. You must use the strcpy function to move data when removing whitespace from the front of the
C string.
3. You may not reverse the string.
4. You may not call the function from inside the cTrim function.
5. You must use the enum constants, no typecasting allowed.
6. You must provide several test cases with sections.
*/
void cTrim(char* str, trimType type)
{
    int len = int(strlen(str));
    int firstNonWS = 0;
    int i;

    bool empty = true;
    for (i = 0; i < len; i++)
    {
        if (!isspace(str[i])) empty = false;
    }
    if (empty)
    {
        str[0] = '\0';
        return;
    }

    switch (type)
    {
    case BOTH:
        for (i = 0; i < len; i++)
        {
            if (!isspace(str[i]))
            {
                strcpy(str, &str[i]);
                break;
            }
        }
        len = int(strlen(str));
        for (i = len - 1; i >= 0; i--)
        {
            if (!isspace(str[i]))
            {
                str[i + 1] = '\0';
                break;
            }
        }
        break;
    case FRONT:
        for (i = 0; i < len; i++)
        {
            if (!isspace(str[i]))
            {
                strcpy(str, &str[i]);
                return;
            }
        }
        str[0] = '\0';
        break;
    case END:
        for (i = len - 1; i >= 0; i--)
        {
            if (!isspace(str[i]))
            {
                str[i + 1] = '\0';
                break;
            }
        }
        break;
    }
}

/*
This will be a non valued function that will have two arguments. The first argument is a c++ string and
the second argument will be the enumerated value for the method. If the method is equal to FRONT,
you will remove all whitespace from the beginning of the c++ string. If the method is equal to END, you
will remove all whitespace from the back of the c++ string. If the method is equal to BOTH, you will
remove all whitespace from both ends of the c++ string.

1. You must use the isspace function that is in the cctype library for detecting characters that are a
whitespace character. Use an iterator to traverse through the string and pass in a dereferenced
iterator.
2. You must use a c++ string member function to remove the requested whitespace.
3. You may not reverse the string.
4. You may not call the function from inside the function.
5. You must use the enum constants, no typecasting allowed.
6. You must provide several test cases with sections.
*/
void sTrim(string &str, trimType type)
{
    string::iterator it;

    // Check if all WS string
    bool empty = true;
    for (it = str.begin(); it != str.end(); it++)
    {
        if (!isspace(*it))
        {
            empty = false;
        }
    }
    if (empty)
    {
        str.clear();
        return;
    }
    // Check if empty string
    if (str.empty()) return;

    switch (type)
    {
    case BOTH:
        for (it = str.begin(); it != str.end(); it++)
        {
            if (!isspace(*it))
            {
                str.erase(str.begin(), it);
                break;
            }
        }

        for (it = str.end() - 1; it != str.begin(); --it)
        {
            if (!isspace(*it))
            {
                str.erase(it + 1, str.end());
                break;
            }
        }
        break;
    case FRONT:
        for (it = str.begin(); it != str.end(); it++)
        {
            if (!isspace(*it))
            {
                str.erase(str.begin(), it);
                break;
            }
        }
        break;
    case END:
        for (it = str.end() - 1; it != str.begin(); --it)
        {
            if (!isspace(*it))
            {
                str.erase(it + 1, str.end());
                break;
            }
        }
        break;
    }
}