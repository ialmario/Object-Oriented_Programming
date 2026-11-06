#ifndef CHARMANDER_H
#define CHARMANDER_H

#include <string>
#include <vector>
#include "Pokemon.h"

using namespace std;

class Charmander : public Pokemon
{
public:
    // Constructors
    Charmander();

    Charmander(
        string name,
        int hp,
        int sp_atk,
        int atk,
        int def,
        int sp_def,
        int speed,
        vector<string> type,
        vector<string> skills
    );

    // Overridden functions
    void speak() override;
    void printStats() override;

private:
    vector<string> skills;
};

#endif