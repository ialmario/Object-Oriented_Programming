#include <iostream>
#include "Charmander.h"

using namespace std;

// Default constructor
Charmander::Charmander() : Pokemon()
{
    type.push_back("Fire");

    skills.push_back("Growl");
    skills.push_back("Flamethrower");
    skills.push_back("Scratch");
    skills.push_back("Ember");

    cout << "Default Constructor (Charmander)\n";
}

// Overloaded constructor
Charmander::Charmander(
    string name,
    int hp,
    int sp_atk,
    int atk,
    int def,
    int sp_def,
    int speed,
    vector<string> type,
    vector<string> skills
) : Pokemon(
        name,
        hp,
        sp_atk,
        atk,
        def,
        sp_def,
        speed,
        type
    )
{
    this->skills = skills;

    cout << "Overloaded Constructor (Charmander)\n";
}

// Says what a Charmander says
void Charmander::speak()
{
    cout << "Charmander-char\n";
}

// Prints the Pokemon stats and Charmander's skills
void Charmander::printStats()
{
    Pokemon::printStats();

    cout << "Skills: ";

    for (size_t i = 0; i < skills.size(); i++)
    {
        cout << skills[i] << "\t";
    }

    cout << endl;
}