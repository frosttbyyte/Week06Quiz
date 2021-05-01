// Week06Quiz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

const int ARRAY_SIZE = 10;

string firstNames[ARRAY_SIZE];
string lastNames[ARRAY_SIZE];
int ages[ARRAY_SIZE];

// i created a function to print out the title
void DrawTitle(string title) {
    const int width = 60;
    const int length = title.length();
    cout << setfill('*') << setw(width) << "*" << endl;
    cout << setfill('*') << setw((width - length) / 2) << "*" << title << right << setw((width - length) / 2) << "*" << endl;
    cout << setfill('*') << setw(width) << "*" << endl;
    cout << endl;
}

// i created another function to read in the file and get the names and ages from the file
bool GetNamesAndAges(string fileName, string firstNames[], string lastNames[], int ages[]) {
    // first we need to open the file up
    ifstream file;
    file.open(fileName);
    int index = 0;
    string line;
    // next we need to see if the file opening was successful
    // if it failed, i will return false
    if (!file) {
        cout << endl;
        cout << fileName << " could not be opened..." << endl;
        return false;
    }
    // if successful, we read in the file and store data into the arrays
    else {
        while (!file.eof()) {
            // when it reads in data for lastname, it includes the colon, which we don't want
            // I couldn't figure out how to get rid of the colon in the lastNames string
            file >> firstNames[index] >> lastNames[index] >> ages[index];
            // testing code
            // cout << firstNames[index] << " " << lastNames[index] << " " << ages[index] << endl;
            index++;
        }
        return true;
    }
}

// the required function
void PrettyPrintName(string firstNames[], string lastNames[], int ages[]) {
    // the first loop will print the data forward by counting i upwards
    for (int i = 0; i < ARRAY_SIZE; i++) {
        const int width = 15;
        // two things wrong with the data output
        // 1) data doesn't line up like in the example - FIXED
        // 2) need to get rid of the colons in last name
        cout << setw(width) << setfill('.') << left << firstNames[i] << setw(width) << setfill('.') << left << lastNames[i] << setw(width) << setfill(' ') << left << ages[i] << endl;
    }
    cout << endl;
    // the second for loop will print the data in reverse order by counting downwards
    for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
        const int width = 15;
        cout << setw(width) << setfill('.') << left << firstNames[i] << setw(width) << setfill('.') << left << lastNames[i] << setw(width) << setfill(' ') << left << ages[i] << endl;
    }
}

int main()
{
    const string title = " Welcome to my Names Program ";
    string fileName;
    string firstNames[10];
    string lastNames[10];
    int ages[10];

    DrawTitle(title);

    cout << "Please enter a file to read in: ";
    cin >> fileName;

    GetNamesAndAges(fileName, firstNames, lastNames, ages);
    PrettyPrintName(firstNames, lastNames, ages);

    system("pause");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
