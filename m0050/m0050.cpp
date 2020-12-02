#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct employee
{
    int id;
    string firstName;
    string lastName;
    double salary;
    double bonus;
};

bool sortByName(employee left, employee right);
bool sortById(employee left, employee right);
bool sortBySalary(employee left, employee right);

int main(int argc, char** argv)
{
    ifstream fin;
    ofstream fout;
    int i;
    bool sortId = false, sortName = false, sortSal = false;
    vector<employee> records;
    employee emp;
    string header, line;

    // check command line arguments
    if (argc != 4)
    {
        cout << "Usage: m0050.exe inputCSVFile outputCSVFILE sortMethod" << endl;
        exit(0);
    }

    // check sort method
    if (strcmp(argv[3], "-n") == 0)
    {
        sortName = true;
    }
    else if (strcmp(argv[3], "-i") == 0)
    {
        sortId = true;
    }
    else if (strcmp(argv[3], "-s") == 0)
    {
        sortSal = true;
    }
    else {
        cout << "Invalid Sort Method:" << endl;
        cout << "-i - sort by id" << endl;
        cout << "-n - sort by name" << endl;
        cout << "-s - sort by salary" << endl;
        exit(0);
    }

    // open/check input and output files
    fin.open(argv[1], ios::in);
    fout.open(argv[2], ios::out);
    if (!fin.is_open())
    {
        cout << "Unable to open input file: " << argv[1] << endl;
        exit(0);
    }
    else if (!fout.is_open())
    {
        cout << "Unable to open output file: " << argv[2] << endl;
        exit(0);
    }

    // read input file
    getline(fin, header);

    while (getline(fin, line, ','))
    {
        emp.id = stoi(line);
        getline(fin, line, ',');
        emp.firstName = line;
        getline(fin, line, ',');
        emp.lastName = line;
        getline(fin, line, ',');
        emp.salary = stod(line);
        getline(fin, line, '\n');
        emp.bonus = stod(line);

        /*cout << fixed << setprecision(2) << emp.id << ',' << emp.firstName << ',' << emp.lastName << ',' <<
            emp.salary << ',' << emp.bonus << endl;*/
        records.push_back(emp);
        emp = {};
    }

    // sort vector
    if (sortName)
    {
        sort(records.begin(), records.end(), sortByName);
    }
    else if (sortId)
    {
        sort(records.begin(), records.end(), sortById);
    }
    else if (sortSal)
    {
        sort(records.begin(), records.end(), sortBySalary);
    }

    // write output file
    fout << header << endl;

    for (i = 0; i < records.size(); i++)
    {
        fout << fixed << setprecision(2) << records.at(i).id << ',' 
            << records.at(i).firstName << ',' << records.at(i).lastName << ',' 
            << records.at(i).salary << ',' << records.at(i).bonus << endl;
    }

    // close input/ouput files
    fin.close();
    fout.close();
}

bool sortByName(employee left, employee right)
{
    int comparedLast = strcmp(left.lastName.c_str(), right.lastName.c_str());
    int comparedFirst;
    if (comparedLast < 0)
    {
        return true;
    }
    else if (comparedLast == 0)
    {
        comparedFirst = strcmp(left.firstName.c_str(), right.firstName.c_str());
        if (comparedFirst < 0)
        {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

bool sortById(employee left, employee right)
{
    return left.id < right.id;
}

bool sortBySalary(employee left, employee right)
{
    return left.salary < right.salary;
}