#include "employee.h"

employee::employee( )
{
    id = 0;
    firstName = "";
    lastName = "";
    salary = 0.0;
    bonus = 0.0;
}

employee::employee( int theID, string fname, string lname, double theSalary,
                    double theBonus )
{
    id = 0;
    firstName = "";
    lastName = "";
    salary = 0.0;
    bonus = 0.0;

    if( id > 0 && theSalary >= 0.0 && theBonus >= 0.0 && 
        !fname.empty() && !lname.empty() )
    {
        id = theID;
        firstName = fname;
        lastName = lname;
        salary = theSalary;
        theBonus = theBonus;
    }
}

employee::~employee( )
{

}

int employee::getID()
{
    return id;
}

bool employee::setID(int newID)
{
    if (newID < 0)
    {
        return false;
    }
    else {
        id = newID;
        return true;
    }
}

string employee::getFName()
{
    return firstName;
}

bool employee::setFName(string newFName)
{
    if (newFName.empty())
    {
        return false;
    }
    else {
        firstName = newFName;
        return true;
    }
}

string employee::getLName()
{
    return lastName;
}

bool employee::setLName(string newLName)
{
    if (newLName.empty())
    {
        return false;
    }
    else {
        lastName = newLName;
        return true;
    }
}

double employee::getSalary()
{
    return salary;
}

bool employee::setSalary(double newSalary)
{
    if (salary < 0)
    {
        return false;
    }
    else {
        salary = newSalary;
        return true;
    }
}

double employee::getBonus()
{
    return bonus;
}

bool employee::setBonus(double newBonus)
{
    if (bonus < 0)
    {
        return false;
    }
    else {
        bonus = newBonus;
        return true;
    }
}