#include <iostream>
#include "Pokemon.h"

using namespace std;

// Default constructor
Pokemon::Pokemon()
{
    name = "unidentified";

    hp = 0;
    sp_atk = 0;
    attack = 0;
    defense = 0;
    sp_def = 0;
    speed = 0;

    cout << "Default Constructor (Pokemon)\n";
}

// Overloaded constructor
Pokemon::Pokemon(
    string name,
    int hp,
    int sp_atk,
    int atk,
    int def,
    int sp_def,
    int speed,
    vector<string> type
)
{
    this->name = name;
    this->hp = hp;
    this->sp_atk = sp_atk;
    this->attack = atk;
    this->defense = def;
    this->sp_def = sp_def;
    this->speed = speed;
    this->type = type;

    cout << "Overloaded Constructor (Pokemon)\n";
}

// Says what a normal Pokemon says
void Pokemon::speak()
{
    cout << "...\n";
}

// Prints the Pokemon's information
void Pokemon::printStats()
{
    cout << "Name: " << name << "\n";

    cout << "HP: " << hp << "\n";
    cout << "Special Attack: " << sp_atk << "\n";
    cout << "Attack: " << attack << "\n";
    cout << "Defense: " << defense << "\n";
    cout << "Special Defense: " << sp_def << "\n";
    cout << "Speed: " << speed << "\n";

    cout << "Type: ";

    for (size_t i = 0; i < type.size(); i++)
    {
        cout << type[i] << "\t";
    }

    cout << endl;
}