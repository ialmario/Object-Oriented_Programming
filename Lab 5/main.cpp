#include <iostream>
#include <string>
#include <vector>
#include "Charmander.h"

using namespace std;

int main()
{
    vector<string> pokemonType;
    pokemonType.push_back("Fire");

    vector<string> skills;
    skills.push_back("Growl");
    skills.push_back("Flamethrower");
    skills.push_back("Scratch");
    skills.push_back("Ember");

    cout << "-------Constructor Created--------\n";

    Charmander charlie(
        "Charlie",  // Nickname
        39,         // HP
        60,         // Special Attack
        52,         // Attack
        43,         // Defense
        50,         // Special Defense
        65,         // Speed
        pokemonType,
        skills
    );

    cout << "\n-------Direct Speak--------\n";
    charlie.speak();

    // Pokemon pointer pointing to Charmander
    Pokemon* p1 = &charlie;

    cout << "\n-------Speak called from Pokemon Pointer--------\n";
    p1->speak();

    // Charmander pointer pointing to Charmander
    Charmander* c1 = &charlie;

    cout << "\n-------Speak called from Charmander Pointer--------\n";
    c1->speak();

    cout << "\n-------Print Stats--------\n";
    charlie.printStats();

    return 0;
}