// RPG.cpp
#include "RPG.h"

#include <cstdio>
#include <random>

using namespace std;

// Default constructor
RPG::RPG()
{
    name = "NPC";
    hits_taken = 0;
    luck = 0.1f;
    exp = 50.0f;
    level = 1;
}

// Overloaded constructor
RPG::RPG(string name, int hits_taken, float luck,
         float exp, int level)
{
    this->name = name;
    this->hits_taken = hits_taken;
    this->luck = luck;
    this->exp = exp;
    this->level = level;
}

// Returns true if the RPG is alive
bool RPG::isAlive() const
{
    return hits_taken < MAX_HITS_TAKEN;
}

// Changes the RPG's hits taken
void RPG::setHitsTaken(int new_hits)
{
    hits_taken = new_hits;
}

// Changes the RPG's name
void RPG::setName(string name)
{
    this->name = name;
}

// Increases the RPG's experience
void RPG::updateExpLevel()
{
    exp += 50.0f;

    if (exp >= 100.0f)
    {
        level += 1;
        exp = 0.0f;
        luck += 0.1f;
    }
}

// Attacks another RPG
void RPG::attack(RPG* opponent)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);

    float random_num = static_cast<float>(dis(gen));

    bool hit = random_num > HIT_FACTOR * opponent->getLuck();

    if (hit)
    {
        opponent->setHitsTaken(
            opponent->getHitsTaken() + 1
        );
    }
}

// Accessors
string RPG::getName() const
{
    return name;
}

int RPG::getHitsTaken() const
{
    return hits_taken;
}

float RPG::getLuck() const
{
    return luck;
}

float RPG::getExp() const
{
    return exp;
}

int RPG::getLevel() const
{
    return level;
}

// Prints all RPG statistics
void RPG::printStats()
{
    printf(
        "Name: %s\tHits Taken: %d\tLuck: %f\tExp: %f\tLevel: %d\tStatus: %s\n",
        name.c_str(),
        hits_taken,
        luck,
        exp,
        level,
        isAlive() ? "Alive" : "Dead"
    );
}

// Destructor
RPG::~RPG()
{
}