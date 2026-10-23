// RPG.h
#ifndef RPG_H
#define RPG_H

#include <string>

using namespace std;

const int INVENTORY_SIZE = 10;
const float HIT_FACTOR = 0.05f;
const int MAX_HITS_TAKEN = 3;

class RPG
{
public:
    // Constructors
    RPG();
    RPG(string name, int hits_taken, float luck,
        float exp, int level);

    // Returns true if the RPG is alive
    bool isAlive() const;

    // Mutators
    void setHitsTaken(int new_hits);
    void setName(string name);
    void updateExpLevel();
    void attack(RPG* opponent);

    // Accessors
    string getName() const;
    int getHitsTaken() const;
    float getLuck() const;
    float getExp() const;
    int getLevel() const;

    // Displays the RPG's statistics
    void printStats();

    // Destructor
    ~RPG();

private:
    string name;
    int hits_taken;
    float luck;
    float exp;
    int level;
};

#endif