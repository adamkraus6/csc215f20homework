#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

float** alloc2d(int rows, int cols);
void free2d(float**& ptr, int rows);
float sumArray(float* arr, int cols);
float* findMin(float* arr, int cols);
float* findMax(float* arr, int cols);

int main(int argc, char** argv)
{
    int rows, cols, i, j;
    float* min = nullptr;
    float* max = nullptr;
    float** my2dArray = nullptr;

    ifstream fin;
    ofstream fout;

    // check for proper number of command line arguments
    if (argc != 3)
    {
        // missing 2 command line arguments
        cout << "Usage: m0021.exe inputfile outputfile" << endl;
        exit(0);
    }

    // open input and output file
    fin.open(argv[1]);
    fout.open(argv[2], ios::out | ios::app);

    //check input file
    if (!fin.is_open())
    {
        // inputfile failed to open
        fin.close();
        cout << "Unable to open input file: " << argv[1] << endl;
        exit(0);
    }

    // check output file
    if (!fout.is_open())
    {
        // output file failed to open
        fout.close();
        cout << "Unable to open output file: " << argv[2] << endl;
        exit(0);
    }

    // read in rows and columns
    fin >> rows >> cols;

    // dynamically allocate memory
    my2dArray = alloc2d(rows, cols);

    // fill the 2d array
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            fin >> my2dArray[i][j];
        }
    }

    // output information to file for each row in 2d array
    fout << rows << " " << cols << endl;
    fout << fixed << showpoint << setprecision(3);
    for (i = 0; i < rows; i++)
    {
        min = findMin(my2dArray[i], cols);
        max = findMax(my2dArray[i], cols);
        fout << "Row:" << setw(10) << i << " "
            << "Sum:" << setw(15) << sumArray(my2dArray[i], cols) << " "
            << "Minimum:" << setw(15) << *min << " "
            << "Maximum:" << setw(15) << *max << endl;
    }
    fout << endl;

    // output the entire 2d array to file, one row per line
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            fout << setw(15) << my2dArray[i][j];
        }
        fout << endl;
    }

    // free memory
    free2d(my2dArray, rows);

    // close files
    fin.close();
    fout.close();
}

float** alloc2d(int rows, int cols)
{
    float** fptr = nullptr;
    int i;

    fptr = new (nothrow) float * [rows];
    if (fptr == nullptr)
    {
        cout << "Not enough memory to run program." << endl;
        free2d(fptr, rows);
        exit(1);
    }

    for (i = 0; i < rows; i++)
    {
        fptr[i] = new (nothrow) float [cols];
        if (fptr[i] == nullptr)
        {
            cout << "Not enough memory to run program." << endl;
            free2d(fptr, rows);
            exit(1);
        }
    }

    return fptr;
}

void free2d(float**& ptr, int rows)
{
    int i;
    if (ptr == nullptr) return;

    for (i = 0; i < rows; i++)
    {
        delete[] ptr[i];
    }

    delete[] ptr;
}

float sumArray(float* arr, int cols)
{
    int i;
    float sum = 0;

    for (i = 0; i < cols; i++)
    {
        sum += arr[i];
    }

    return sum;
}

float* findMin(float* arr, int cols)
{
    int i, min = 0;

    for (i = 1; i < cols; i++)
    {
        if (arr[i] < arr[min]) min = i;
    }

    return &arr[min];
}

float* findMax(float* arr, int cols)
{
    int i, max = 0;

    for (i = 1; i < cols; i++)
    {
        if (arr[i] > arr[max]) max = i;
    }

    return &arr[max];
}