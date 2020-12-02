#ifndef __EMPLOYEE__H__
#define __EMPLOYEE__H__
#include <string>
using std::string;

class employee
{
    public:
        employee( );
        employee( int theID, string fname, string lname, double theSalary,
                  double theBonus );
        ~employee( );
        int getID();
        bool setID(int newID);
        string getFName();
        bool setFName(string newFName);
        string getLName();
        bool setLName(string newLName);
        double getSalary();
        bool setSalary(double newSalary);
        double getBonus();
        bool setBonus(double newBonus);

    private:
        int id;
        string firstName;
        string lastName;
        double salary;
        double bonus;
};

#endif

