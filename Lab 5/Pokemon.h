#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>

using namespace std;

class Pokemon
{
public:
    // Constructors
    Pokemon();

    Pokemon(
        string name,
        int hp,
        int sp_atk,
        int atk,
        int def,
        int sp_def,
        int speed,
        vector<string> type
    );

    // Virtual functions
    virtual void speak();
    virtual void printStats();

protected:
    string name;

    // Six Pokemon stats
    int hp;
    int sp_atk;
    int attack;
    int defense;
    int sp_def;
    int speed;

    vector<string> type;
};

#endif