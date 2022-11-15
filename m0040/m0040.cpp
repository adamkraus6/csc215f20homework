#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

void printFile(fstream &fio);
bool applyBonus(fstream &fio, int empID);

struct empData
{
    int id;
    char firstName[20];
    char lastName[40];
    double salary;
    double bonus;
};

int main(int argc, char** argv)
{
    fstream file;
    if (argc != 3)
    {
        cout << "Usage: m0040.exe binaryData employeeID" << endl;
        exit(0);
    }

    file.open(argv[1], ios::in | ios::out | ios::binary);
    if (!file)
    {
        file.close();
        cout << "Unable to open binary file: " << argv[1] << endl;
        exit(0);
    }

    int id = atoi(argv[2]);

    printFile(file);

    cout << endl;

    bool bonusApplied = applyBonus(file, id);
    if (!bonusApplied)
    {
        cout << "Employee ID " << id << " was not found." << endl;
    }
    else {
        cout << "Employee ID " << id << " has been updated." << endl;
    }

    cout << endl;

    printFile(file);

    file.close();
}

void printFile(fstream &file)
{
    int i, count;
    empData emp;
    cout << fixed << showpoint << setprecision(2);

    file.seekg(0, ios::end);
    count = (int)file.tellg() / sizeof(empData);
    file.seekg(0, ios::beg);

    for (i = 0; i < count; i++)
    {
        file.read((char*)&emp, sizeof(empData));

        cout << setw(7) << emp.id << " "
            << left << setw(20) << emp.firstName
            << setw(40) << emp.lastName << right
            << " Salary: " << setw(10) << emp.salary
            << " Bonus: " << setw(10) << emp.bonus << endl;
    }
}

bool applyBonus(fstream &file, int empID)
{
    int i, count;
    empData emp;

    file.seekg(0, ios::end);
    count = (int)file.tellg() / sizeof(empData);
    file.seekg(0, ios::beg);

    for (i = 0; i < count; i++)
    {
        file.read((char*)&emp, sizeof(empData));

        if (emp.id == empID)
        {
            emp.bonus += 500.0;

            file.seekg(i * sizeof(empData), ios::beg);
            file.write((char*)&emp, sizeof(empData));
            return true;
        }
    }

    return false;
}