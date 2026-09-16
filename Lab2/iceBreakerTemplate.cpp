#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>

using namespace std;

//------------------------PROTOTYPES-------------------------------------------

size_t ranGen(size_t questionSize);
bool readFile(const string& filename, vector<string>& vec);

bool writeFile(
    const string& filename,
    const vector<string>& v0,
    const vector<string>& v1
);

void promptFile(vector<string>& v);
void printVec(const vector<string>& v);

//------------------------MAIN-------------------------------------------------

int main()
{
    vector<string> roster;
    vector<string> qBank;

    if (!readFile("2310_F26_Rosters.csv", roster)) {
        return 1;
    }

    if (!readFile("Questions.csv", qBank)) {
        return 1;
    }

    if (!writeFile("Student_question_bank.csv", roster, qBank)) {
        return 1;
    }

    cout << "Student question bank created successfully." << endl;

    return 0;
}

//------------------------FUNCTION DEFINITIONS---------------------------------

size_t ranGen(size_t questionSize)
{
    static random_device rd;
    static mt19937 generator(rd());

    uniform_int_distribution<size_t> distribution(
        0,
        questionSize - 1
    );

    return distribution(generator);
}

bool readFile(const string& filename, vector<string>& vec)
{
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open " << filename << endl;
        return false;
    }

    string line;

    while (getline(inputFile, line)) {
        vec.push_back(line);
    }

    inputFile.close();
    return true;
}

bool writeFile(
    const string& filename,
    const vector<string>& v0,
    const vector<string>& v1
)
{
    if (v1.empty()) {
        cerr << "Error: No questions were loaded." << endl;
        return false;
    }

    ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        cerr << "Error: Could not create " << filename << endl;
        return false;
    }

    for (size_t i = 0; i < v0.size(); i++) {
        outputFile
            << v0[i]
            << ","
            << v1[ranGen(v1.size())]
            << endl;
    }

    outputFile.close();

    if (!outputFile) {
        cerr << "Error: Could not finish writing to "
             << filename << endl;
        return false;
    }

    return true;
}

void promptFile(vector<string>& v)
{
    cout << "File to read?" << endl;

    string myFile;
    cin >> myFile;

    if (!readFile(myFile, v)) {
        cerr << "The requested file could not be read." << endl;
    }
}

void printVec(const vector<string>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}