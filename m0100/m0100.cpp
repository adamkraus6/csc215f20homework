#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

enum trait {POTENCY, ESSENCE, ASPECT};
struct rune
{
    string name;
    trait type;
};

void permute(int sol[], bool used[], int n, int pos, int k, rune runes[]);

int main(int argc, char** argv)
{
    ifstream fin;
    bool used[300] = { false };
    int sol[300] = { 0 };
    rune runes[300];
    string header, str;
    rune r;
    int pos = 0, i = 0, k = 3;

    if (argc != 2)
    {
        cout << "m0100.exe csvdatafile" << endl;
        exit(0);
    }

    fin.open(argv[1], ios::in);
    if (!fin.is_open())
    {
        cout << "Unable to open: " << argv[1] << endl;
        exit(0);
    }

    getline(fin, header);

    while (getline(fin, str, ','))
    {
        i++;

        r.name = str;
        getline(fin, str, '\n');
        if (str == "Potency")
        {
            r.type = POTENCY;
        }
        else if (str == "Essence")
        {
            r.type = ESSENCE;
        }
        else if (str == "Aspect")
        {
            r.type = ASPECT;
        }

        runes[i] = r;
    }

    permute(sol, used, i, pos, k, runes);

    fin.close();
}

void permute(int sol[], bool used[], int n, int pos, int k, rune runes[])
{
    int i;

    if (pos == k)
    {
        if (runes[sol[0]].type == POTENCY && runes[sol[1]].type == ESSENCE && runes[sol[2]].type == ASPECT)
        {
            for (i = 0; i < k; i++)
            {
                cout << runes[sol[i]].name << ' ';
            }
            cout << endl;
        }
        return;
    }

    for (i = 0; i <= n; i++)
    {
        if (!used[i])
        {
            sol[pos] = i;
            used[i] = true;

            permute(sol, used, n, pos + 1, k, runes);

            used[i] = false;
        }
    }
}