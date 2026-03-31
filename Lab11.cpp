// This program asks the user for a file name, in which it has a series of numbers and it reads the contents of the file into an array, lastly displays data.
// Anael Redrovan 
// March 31 2026

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int SIZE = 100;

// Function to read numbers from file into array
int readFile(const string& filename, double arr[], int maxSize)
{
    ifstream infile(filename);
    int count = 0;

    if (!infile)
    {
        cout << "Error: Unable to open file.\n";
        return 0;
    }

    while (count < maxSize && infile >> arr[count])
    {
        count++;
    }

    infile.close();
    return count;
}

// Function to calculate and display statistics
void analyzeData(double arr[], int count)
{
    if (count == 0)
    {
        cout << "No numbers to analyze.\n";
        return;
    }

    double min = arr[0];
    double max = arr[0];
    double sum = 0;

    // First loop: min, max, sum
    for (int i = 0; i < count; i++)
    {
        if (arr[i] < min)
            min = arr[i];

        if (arr[i] > max)
            max = arr[i];

        sum += arr[i];
    }

    double average = sum / count;

    // Second loop: standard deviation
    double varianceSum = 0;
    for (int i = 0; i < count; i++)
    {
        varianceSum += pow(arr[i] - average, 2);
    }

    double stdDev = sqrt(varianceSum / count);

    // Output results
    cout << "\nResults\n";
    cout << "Numbers read: " << count << endl;
    cout << "Lowest number: " << min << endl;
    cout << "Highest number: " << max << endl;
    cout << "Total: " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Standard Deviation: " << stdDev << endl;
}

int main()
{
    double numbers[SIZE];
    string filename;

    // Greeting
    cout << "Welcome to the Number Analyzer\n";
    cout << " This program reads numbers from\n";
    cout << " a file and calculates statistics.\n";

    cout << "Enter the file name: ";
    cin >> filename;

    int count = readFile(filename, numbers, SIZE);

    analyzeData(numbers, count);

    cout << "Thank you for using the program"<<endl;


    return 0;
}